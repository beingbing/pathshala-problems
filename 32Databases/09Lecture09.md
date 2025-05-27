# Database Scalability: Denormalization
Now that we’ve covered **database reliability** (keeping data safe with replication) and **maintainability** (federation for modular design), let’s focus on **scalability**—which is about maintaining **acceptable performance as the load increases** (e.g., more users, higher concurrency).

## Key Distinction:
* **Reliability** ensures data safety and availability by replicating data.
* **Scalability** ensures **consistent performance** as data size and user load grow.
* Importantly, **reliability ≠ scalability**. Just having multiple copies of data doesn’t guarantee performance under increasing load.

## Approaches to Scalability:
Scalability can be achieved through:
1. **Improving performance of existing systems**
2. **Splitting the workload** across multiple systems (e.g., federation, sharding)

## Performance Improvements for Scalability:
- **Choose the Right Database**
  * Use a database that fits your workload (e.g., relational, NoSQL).

- **Denormalization** (for relational databases)
  * In database design, **normalization** (following normal forms) avoids data redundancy and improves integrity.
  * However, highly normalized schemas can lead to **complex joins** and **slow queries**, especially as data grows.
  * **Denormalization** deliberately **adds redundancy** by storing derived or duplicated fields to **speed up query performance**.
  * Example: Instead of always computing the total order price by joining multiple tables, you might store the total directly in the order record.
  * **Caution**: Denormalization is a trade-off between **redundancy** and **query performance**. Use it **only when scalability bottlenecks justify it** and after other optimizations (like indexing) have been considered.

- **Indexing**
  * Proper indexing can significantly improve query performance by reducing data scan times.

## When Performance Tweaks Aren’t Enough:
If performance optimization hits its limit, **splitting the workload** is the next step:
* **Federation**: Divide data by **functional modules** (e.g., users, orders, products).
* **Sharding**: Split a single large dataset into **smaller partitions** (e.g., by user ID range or region).
