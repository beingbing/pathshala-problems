# 🗃️ **Submission & Result Data Storage – Simplified**

## 📥 **Data Storage Flow**
* **Incoming Requests**:
    * Each submission includes:
        * **Input File** (\~1MB)
        * **Code File** (\~1MB)
        * **Output File** (\~1MB) → generated after processing
    * **Total Data per Request**: \~3MB
    * **Request Rate**: 30 submissions/second

## 📊 **Storage Calculation**
* **Total Data per Second**:
  30 × 3MB = **90 MB/second**
* **Total Data per Day**:
  90 MB/s × 60 × 60 × 24 = **\~7.8 TB/day**

## 🏗️ **Storage Optimization**
- **Problem**: Directly storing large files in the DB makes it bloated, slows writes, and adds maintenance overhead.
- **Solution**: Store files in **Cloud Object Storage** (e.g., AWS S3, GCS) and save **file links (URLs)** in the database.

* **Updated Submission Table**:
  * `unique-id`
  * `code-language-id`
  * `input-file-link`
  * `code-file-link`
  * `last-access-time` (for cleanup)

* **Updated Result Table**:
  * `unique-id`
  * `submission-db-unique-id`
  * `output-file-link`
* **File Link Size**: \~300 characters per link (\~1KB total per request).

### **Optimized Data Volume**:
* 30 requests/s × 1KB = **30KB/second**
* 30KB/s × 60 × 60 × 24 = **\~2.6 GB/day**

By offloading files to the cloud and storing only lightweight links, we reduce DB load dramatically (from \~8TB to \~2.6GB/day). However, the cloud storage will still need to handle the actual 8TB/day file volume, which can be managed through **sharding** and lifecycle management.

## 🗄️ **Database Design**
* **Combined Database**: Instead of separate DBs for submissions and results, merge them into one DB with two related tables to avoid complex joins during reads.
* **Database Choice**:
    * Use a relational DB like **PostgreSQL** or **MySQL**.
    * `unique-id` serves as the primary key.
    * No complex indexing needed.

## 🧹 **Cleanup Service**
* **Purpose**: Efficiently manage storage by removing unused or stale data.
  * Remove submissions **not accessed for over a day** (from both DB and cloud storage).
  * Remove submissions that never generated a result if not accessed after submission.

- To support this, add a `last-access-time` field to track the last read/access for each submission.
- Run the cleanup service **daily**.

## 📈 **Ensuring Scalability, Reliability & Maintainability**
* **Reliability**:
  * SQL DB without sharding simplifies management.
  * Backups of recent data (last 1-2 hours) safeguard against data loss.
  * Losing older data (beyond backups) is tolerable.
* **Scalability**:
  * Cloud storage handles large volumes (8TB/day) efficiently.
  * DB load reduced to lightweight link storage (\~2.6GB/day), easily handled by a single machine.
* **Maintainability**:
  * Clear separation of concerns:
      * DB for metadata (links, submission info)
      * Cloud storage for files
  * Cleanup service ensures stale data doesn’t accumulate.
