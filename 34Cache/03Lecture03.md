# 🚀 **Cache Invalidation and Cache Eviction**
Before diving into cache patterns and organization, let’s explore two essential concepts in caching: **cache invalidation** and **cache eviction**. These concepts ensure that cached data remains **fresh, accurate, and optimized for performance**.

## 🔄 **A. Cache Invalidation: Keeping Data Fresh**
Caching boosts performance by storing frequently accessed data. But when the **source data changes**, cached data can become **stale**, risking inaccurate responses to clients. Cache invalidation ensures the cache reflects the **latest updates**.

### 📌 **Techniques for Cache Invalidation:**
1. **Time-Based Invalidation (TTL - Time to Live)**
   * Cached data has an expiration time (TTL).
   * Once TTL expires, the system marks the data as expired and fetches updated data from the source.
   * ⚠️ **Challenge**: Choosing the right TTL is tricky—too short increases backend load; too long risks stale data.

2. **Event-Based Invalidation**
   * Cache is invalidated when specific events (like a database update or data change) occur.
   * A flag or notification triggers recalculating and refreshing the cache.
   * ⚠️ **Challenge**: Event tracking adds complexity and can slow down the system.

### 🛠️ **Strategies for Cache Invalidation:**
* **HTTP Cache-Control Headers**: Directives like `max-age`, `must-revalidate`, and `no-cache` specify how long data stays fresh.
* **Write-Through/Write-Behind Caching**: Ensures the cache updates when the database updates.
* **Monitoring and Alerts**: Automated tools can detect data changes and trigger invalidations.

### 📏 **Design Considerations:**
* **Granularity**: Should we invalidate the whole cache, a specific entry, or a related group of data?
* **Performance Impact**: Invalidation should be efficient and avoid slowing down the system or overloading the backend.

## 🗑️ **B. Cache Eviction: Managing Limited Space**
Cache memory is **finite**, so when it fills up, we need to **evict older or less useful data** to make room for new or more frequently accessed information. This is **cache eviction**.

### 📌 **Eviction Policies:**
1. **FIFO (First In, First Out)**: Remove the oldest cached data first, regardless of usage frequency.
2. **LFU (Least Frequently Used)**: Remove the data accessed least often.
3. **LRU (Least Recently Used)**: Remove the data that hasn’t been accessed recently.

### 🔎 **Why Eviction Matters**:
* **Improves Cache Efficiency**: Ensures the cache contains the most relevant and frequently accessed data.
* **Prevents Overload**: Keeps cache storage optimized and avoids system slowdowns.
