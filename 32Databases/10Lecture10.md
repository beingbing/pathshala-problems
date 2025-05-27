# Database Scalability: Indexing
Previously, we discussed **denormalization** as a way to improve performance in relational databases for scalability. Another powerful technique is **indexing**—which makes **data access faster** as the dataset grows.

## What is Indexing?
Indexing involves creating **special data structures** (called **indices**) to quickly locate data without scanning the entire table.

* **In simple terms**, an index works like a **Map (key-value pair)**, where:
  * **Key**: the value you want to search by.
  * **Value**: the location of that data in the database.
* This map is stored separately from the main data (either in-memory or on-disk), enabling fast lookups.

Indexing = Creating a fast-access map for data retrieval. Without an index, the database must **scan the whole table** (O(n)) to find a record. With an index, it can **jump directly** to the location (O(log n) or O(1)).

## Why Indexing is Important for Scalability:
As the database grows (more data, more users), **searching data efficiently** becomes critical to maintain performance. Indexing reduces:
* Time to fetch data.
* Load on the system.
* Latency for user queries.

## Types of Indexes:
- **Primary Index (Clustered Index)**
  * Built automatically by the DBMS on the **primary key** of a table.
  * Orders the table itself based on the index (hence called **clustered**).
  * You don’t need to manually create it.

- **Secondary Index (Non-Clustered Index)**
  * Created manually on **non-primary key fields** (e.g., location, email, etc.).
  * Useful for optimizing **frequently used queries** that aren’t covered by the primary key.
  * Example: Uber creates a secondary index on **user location** to quickly find nearby taxis.

- **Best Practices for Secondary Indexes:**
  * Use only when you’ve identified **frequent query patterns**.
  * Typically needed when you’ve scaled to a large user base.

## How Indexing Works Internally:
* **Ordered Indices** use **B-trees or B+ trees**, offering O(log n) lookup time.
* **Unordered Indices** use **hashing**, providing near O(1) access time but unordered data.
