# 🚀 **Scaling the System for 10x Load**
With the load increasing from **30 to 300 requests/second** and daily data volume rising from **8TB to 80TB**, we need to adapt our system to maintain **performance, reliability, and scalability**.

## 🏗️ **Scaling Strategy**
### 🌐 **What Scales Well Horizontally**
* **Submission Service**
  * Introduce a **smarter load balancer** (e.g., performance-based or least-connections) instead of simple round-robin.
  * Handle **file uploads asynchronously** to cloud storage, decoupling uploads from the main processing flow.
* **Clean-Up Service**
  * Increase the frequency of the clean-up service to run **multiple times a day**, ensuring stale data is removed promptly.
* **Submission & Result DB**
  * With the optimized approach of storing only **file links**, the current DB setup (Postgres/MySQL with combined tables) can comfortably handle the **10x request rate** without significant changes.

## 🔧 **Areas Requiring Adjustment**
### **Submission-Service Workers**
* **Cluster by Programming Language**:
  * Create dedicated worker clusters for each supported language.
  * Dynamically scale clusters based on load distribution per language.
  * Isolate failures: a language-specific cluster failure (e.g., version mismatch) won't affect others.
* **More Machines per Cluster**:
  * Scale horizontally by adding machines to clusters with heavier loads.

### **Result-Service Workers**
* Instead of directly writing results to the DB (which can cause contention under load),
  * **Push results to a Kafka queue**,
  * Use **dedicated DB writer threads** to asynchronously write these results, balancing throughput and consistency.

## **Result Service Scaling**
* Increase the number of **replicas** to handle **300 concurrent client connections**.
* Implement **connection sharding using consistent hashing**:
  * For example, hash the submission IDs or client IDs to evenly distribute connections across replicas.
  * This prevents any single replica from becoming overloaded and improves fault tolerance.

### 💡 **Summary**
To handle a **10x increase** in load, we’ll:
* Enhance the **submission service** with smarter load balancing and async uploads.
* Scale **clean-up frequency** to manage data efficiently.
* Use **clustered workers** by language for isolation and efficiency.
* Implement **Kafka queues and DB writer threads** in the result-service to manage high write loads.
* Scale the **result-service** with multiple replicas and consistent hashing to manage connections effectively.
