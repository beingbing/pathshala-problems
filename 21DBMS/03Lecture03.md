## 🗃️ Types of Databases

At a high level, databases can be categorized into two major types:

---

### 1. **Relational Database Management Systems (RDBMS)**

- All data is organized into **tables (rows and columns)**.
- Every **entity (noun)** becomes a **table**; relationships are formed via **foreign keys**.
- Requires a **predefined schema** (structured data).

#### ✅ Use When:
- Your data has a consistent structure.
- You need **complex querying** (e.g., joins, constraints).
- Data **integrity** is important.

#### 🛠️ Examples:
- **MySQL**, **PostgreSQL**, **Oracle**, **SQL Server**

#### 💡 Real-World Use:
- Banking systems, Inventory management, E-commerce orders.

---

### 2. **Non-Relational Database Management Systems (NoSQL)**

- Suitable for **unstructured or semi-structured** data.
- Schema is **flexible or not enforced**.
- Focuses on **scalability** and **performance** for specific use cases.

#### 📂 Types of NoSQL Databases:

| Type                  | Description                                  | Example Product | Real-World Use Case |
|-----------------------|----------------------------------------------|------------------|----------------------|
| **Key-Value Store**   | Data stored as simple key-value pairs        | Redis           | Caching (e.g., sessions, tokens) |
| **Document Store**    | Data stored as JSON-like documents           | MongoDB, Cassandra | Product catalogs (e.g., Amazon) |
| **Graph DB**          | Data as nodes and edges (relationships)      | Neo4j           | Social networks (e.g., LinkedIn, Facebook) |
| **Time Series DB**    | Optimized for time-stamped data              | Prometheus      | Monitoring metrics (e.g., Uber’s cab positions over time) |

---

### ⚖️ Choosing Between Relational & Non-Relational

| Criteria                  | Go for RDBMS                   | Go for NoSQL                              |
|---------------------------|--------------------------------|--------------------------------------------|
| Schema                    | Fixed & structured             | Flexible or dynamic                        |
| Relationships             | Complex & many-to-many         | Few or none                                |
| Querying                  | Powerful & SQL-based           | Simple or use-case specific                |
| Scalability               | Vertical (scale-up)            | Horizontal (scale-out)                     |
| Use Case Examples         | Banking, ERP, E-commerce       | Real-time apps, analytics, social networks |
