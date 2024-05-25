# Submission and Result DB

### Data Storage Strategy

**Submission DB Schema**:
- `unique-id`
- `code-language-id`
- `input-file`
- `code-file`

**Result DB Schema**:
- `unique-id`
- `submission-db-unique-id`
- `output-file`

### Data Storage Calculation

- **Request Rate**: 30 requests per second.
- **Read:Write Ratio**: 1:1.
- **Data Size per Request**: 
  - Input file: 1MB
  - Output file: 1MB
  - Code file: 1MB
  - Total: 3MB

**Total Data per Second**: 
30 requests/second × 3 MB/request = 90 MB/second

**Total Data per Day**:
90 MB/second × 60 × 60 × 24 = 7.776 TB/day ≈ 8 TB/day

### Optimizing Data Storage

Since both databases are write-heavy, storing large files directly in the DB can cause bloating
and slow down the writing process. To optimize:

1. **Cloud File Storage**:
   - Store files in a cloud storage system.
   - Save only the file links in the database.

**Updated Submission DB Schema**:
- `unique-id`
- `code-language-id`
- `input-file-link`
- `code-file-link`

**Updated Result DB Schema**:
- `unique-id`
- `submission-db-unique-id`
- `output-file-link`

### Optimized Data Storage Calculation

- **Link Size**: Assume each link is ≤ 300 characters.
- **Data per Request**: 
  - 1 character = 1 byte
  - 900 bytes/request ≈ 1 KB/request

**Total Data per Second**:
30 requests/second × 1 KB/request = 30 KB/second

**Total Data per Day**:
30 KB/second × 60 × 60 × 24 = 2.592 GB/day

By storing only file links, we reduce storage requirements from 3MB to 1KB per request,
significantly easing and speeding up the writing process. A single machine can now handle the daily
data load, whereas storing 8TB/day would have required multiple machines.

However, the cloud storage will still need to handle 8TB/day, necessitating sharding to manage this
volume.

### Database Structure

**Q. Do we need two separate DBs ?**

A. No. Since most reads will require data from both submission and result DBs, merging them into a
single database with two separate tables is more efficient than performing joins every time.

### Clean-up service

To manage storage efficiently, implement a clean-up service with the following responsibilities:
- Identify submissions not accessed for more than a day and delete them from both cloud-storage and DB.
- Remove submissions that never had a link generated, if not accessed again once result was generated.

To support this, add a `last-access-time` field to the submission table. The clean-up service will
run daily to clear out stale entries and associated files.

### Database Choice

For the combined database, use a relational DB with an SQL-based solution like PostgreSQL or MySQL.
The `ID` field will serve as the primary key, and no additional indexing will be needed.

**Database Schema**

**Submission Table**:
- `unique-id`
- `code-language-id`
- `input-file-link`
- `code-file-link`
- `last-access-time`

**Result Table**:
- `unique-id`
- `submission-db-unique-id`
- `output-file-link`

By consolidating the databases and implementing a clean-up service, we can maintain efficiency,
reduce storage requirements, and ensure the system remains performant.

### Ensuring Reliability, Maintainability, and Scalability

- **Reliability**: Using SQL without sharding simplifies data management. Losing older data is not
critical; backing up data from the last 1-2 hours will ensure reliability.
- **Maintainability**: Quick read and write operations enhance maintainability.
- **Scalability**: Cloud-file-storage reduces the data load on the database, ensuring that a single
machine can handle scaling needs effectively.
