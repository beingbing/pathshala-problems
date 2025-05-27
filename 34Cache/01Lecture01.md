# ⚡ **Introduction to Cache**
A **cache** is a **software or hardware component** that temporarily stores data, so that future requests for that data can be served faster. The key idea is simple:
* **If data is available in the cache**, return it immediately without recomputation.
* **If data isn’t in the cache**, fetch it from the original source, store it in the cache for future use, and then return it to the requester.

This **reduces load** on the original system, improves **performance**, and saves **time and resources**—much like how we humans **memorize** information for quick recall.

## 🔍 **How Caching Works**
1. **Check the cache first**.
2. If **found** (called a **cache hit**), return the data quickly.
3. If **not found** (called a **cache miss**), fetch from the original source, store it in the cache, and return it.

The **goal** is to maximize the **cache hit rate** — the percentage of requests satisfied by the cache.

## ⚙️ **Types of Cache**
* **Software Cache**:
  Example: In-memory structures like **hash maps** or **LRU caches** in applications.
* **Hardware Cache**:
  Example: High-performance systems like **Redis**, or **CPU caches** like **L1/L2/L3**.

## 📈 **Cache Hit Rate**
The **cache hit rate** depends on system requirements and design:
* **Recency Bias**: Social media feeds prioritize recent updates, making newer content more likely to be cached.
* **Long-term Average**: Analytics or reporting systems cache computed results over longer periods.

A **higher cache hit rate** means fewer calls to the original data source, resulting in faster response times and reduced system load.
