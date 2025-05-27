# 🌐 **Scaling the URL Shortener (For 10x Load)**
To handle **10x more traffic**, we need to enhance the system’s scalability and performance with the following strategies:

## 🧩 **1️⃣ Sharding the Database**
* As the data grows, a **single database becomes a bottleneck**. To scale, we **partition (shard)** the data.
* **Range-based partitioning** (splitting data by ranges of keys) may cause imbalance if many URLs fall into a specific range (e.g., similar prefixes).
* A better approach is **consistent hashing**, which:
  * Hashes the **short URL** to assign it to a shard (e.g., a partition or database node).
  * **Balances the data and traffic** across shards, even as new nodes are added or removed.

## ⚙️ **2️⃣ Backend Load Balancing**
* Since we’ve already implemented a **Monitoring Service (MS)**, it can dynamically adjust load balancing and distribute traffic among backend servers.
* This ensures even resource usage without manual intervention, even under higher load.

## 🚀 **3️⃣ Caching for Performance**
* To reduce database load and improve latency, we introduce **caching mechanisms**:
  * **Read-side caching**: Place a cache at the **reverse proxy** or server layer to cache frequent GET requests (i.e., `getLongUrl(shortURL)`).
  * **Write-through cache**: Maintain a cache between the backend server and the database so that writes update both the cache and DB simultaneously.
  * **LRU (Least Recently Used) eviction**: Ensures stale or infrequently accessed entries are removed when the cache is full, maintaining optimal memory usage.
