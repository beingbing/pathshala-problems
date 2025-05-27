# 🚀 **Cache Patterns in a Three-Tier Architecture**
Caching isn’t just about where data is stored—it’s also about **how we manage and organize it** to balance **performance, consistency, and complexity**. Let’s explore key caching patterns used in designing robust systems.

## 🗂️ **1. Cache-Aside (Lazy Loading) Pattern**
* The application controls caching. When data is requested:
  * First, check the cache. If found (**cache hit**), return it.
  * If not found (**cache miss**), fetch from the database, store it in the cache, and return it.
* Example: **Memcached**.

**Advantages:**
* Decouples cache from the database—system continues to function if the cache fails.
* Efficient for read-heavy workloads; only requested data gets cached.
* Minimal overhead for writes (writes go directly to DB, not cache).

**Disadvantages:**
* Cache misses increase latency.
* Harder to implement cache invalidation (since app logic handles it).

## 🔁 **2. Read-Through / Write-Through Pattern**
* The cache sits between the application and database:
  * **Read-Through**: If a cache miss occurs, the cache itself fetches data from the DB, stores it, and returns it.
  * **Write-Through**: Writes go first to the cache, which synchronously writes to the DB.

**Advantages:**
* Reduces server workload (cache handles DB reads/writes).
* Ensures cache and DB stay consistent.
* Suitable for apps needing high read consistency.

**Disadvantages:**
* Tight coupling between cache and DB (if cache fails, system may suffer).
* Write latency increases due to dual writes (cache + DB).
* Risk of **cache pollution** (storing rarely accessed data).

## 🔃 **3. Write-Around / Read-Through Pattern**
* Writes bypass the cache and go directly to the DB.
* Reads use the cache (like Read-Through). If data isn’t cached, it’s fetched from DB and cached for future.

**Advantages:**
* Reduces cache pollution (avoids caching data unlikely to be read soon).
* Cache failures don’t affect writes.
* Lower latency for writes (single DB call).

**Disadvantages:**
* Cache misses can slow reads.
* Cache becomes a single point of failure for reads.

## 📝 **4. Write-Behind (Write-Back) Pattern**
* Writes go first to the cache and are queued for asynchronous bulk updates to the DB later.
* Reduces write load on the DB and batches updates for efficiency.

**Advantages:**
* Efficient for high-volume writes.
* Helps buffer writes if DB is temporarily unavailable.

**Disadvantages:**
* Risk of data loss if cache crashes before flushing to DB.
* Complexity increases if using message queues for reliability.

## 🔮 **5. Refresh-Ahead Pattern**
* The cache proactively **refreshes data before it expires**, predicting which data will be needed.
* Instead of waiting for cache expiry or a request, the system preloads fresh data.

**Advantages:**
* Faster responses for frequently requested data.
* Balanced backend load (preloading spreads workload over time).
* Reduces latency spikes for high-demand data.

**Disadvantages:**
* Increased resource use (computationally and in memory).
* Risk of wasted effort if predictions are inaccurate.
* More complex to implement and maintain.
