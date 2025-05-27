# 🌐 Database Scalability: Sharding
Once we've pushed performance improvements to the limit—using techniques like denormalization and indexing—but the **data volume and request load keep growing**, it's time to **split the data across multiple databases**. This is where **sharding** comes in.

## 🔨 What is Sharding?
Sharding is the **horizontal partitioning** of data across multiple servers or nodes, called **shards**.
* Each shard holds a **unique subset** of the data and handles its own **read/write operations**, reducing bottlenecks.
* Shards work **independently**, improving scalability and resilience.

## 🗂 How is Data Divided?
Data is distributed across shards based on a **shard key**:
* The **shard key** could be:
  * A **unique identifier** (e.g., user ID).
  * A **range of values** (e.g., date ranges).
  * A **hash of the data** itself (for uniform distribution).
* The goal is to balance load evenly across shards.

- **Hashing vs Lookup Table**
  * Typically, a **hash function** on the shard key determines which shard holds the data.
  * Alternatively, a **lookup table** (or metadata table) maps keys to shards.
    * The application checks the table first, then queries the appropriate shard.

## 🔗 Shard Routing Layer
Shards don’t work in isolation.
* A **routing layer** (also called a router) sits above the shards.
* This **routes each query** to the correct shard based on the shard key.
* It introduces an extra tier in the architecture, making it **4-tier** (client → routing layer → shards → storage).

## ✅ Benefits of Sharding
- **Scalability:** Spreads data and workload across multiple servers.
- **Fault Tolerance & Reliability:** If one shard goes down, others continue serving.

## ⚠️ Challenges of Sharding
- **Increased Complexity:** Routing logic adds a layer of complexity.
- **Higher Latency:** Extra routing hop slows requests.
- **Routing Layer Must Be Reliable:** It becomes a single point of failure if not designed properly.
- **Data Skew:** If shard keys don’t distribute data evenly, some shards become hotspots, requiring **re-sharding**.
- **Cross-Shard Queries:** Complex queries spanning multiple shards are harder to implement and may impact performance.
