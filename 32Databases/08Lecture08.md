# Database Maintainability

DB server maintainability is often handled by vendors, but choosing the right database type is
crucial for maintainability. The goal is to use existing solutions rather than modifying a
relational database to fit specific needs when there are ready-made solutions available.

## Types of Databases

Databases can be broadly divided into two categories:

### A. SQL (Relational Databases)
- **Structure**: Organized in tables joined using SQL queries.
- **Transactions**: Vendors ensure ACID properties (Atomicity, Consistency, Isolation, Durability).

#### Limitations
- **Schema Requirements**: Requires a strict schema, which can lead to storage inefficiencies.
- **Media Handling**: Not suitable for storing images or videos, which are streams of bytes.
- **Performance**: Queries can be slow with large tables containing vast amounts of data.

### B. NoSQL (Non-relational Databases)
- **Key/Value Pairs**: Example - Redis, MemCache. Ideal for creating eCommerce carts.
- **Document Databases**: Example - MongoDB. Uses large chunks of JSON for each object,
representing sets as key/value pairs in JSON format.
- **Graph Databases**: Example - Neo4j. Suitable for social networks.
- **Time Series Databases**: Example - InfluxDB. Used by services like Uber.

## Conclusion and Comparison

### SQL
- **Schema**: Strict schema.
- **Joins**: Supports complex joins.
- **Transactions**: Ensures ACID properties.
- **Scalability**: Uses sharding to handle large data volumes.

### NoSQL
- **Schema**: Flexible schema.
- **Logic**: Application logic for data handling.
- **Principles**: BASE principles (Basically Available, Soft state, Eventual consistency).
- **Scalability**: Capable of storing large amounts of data.

Choose SQL databases for scenarios requiring complex transactions and strict schema enforcement.
Opt for NoSQL databases for flexibility, scalability, and when dealing with diverse data types like
JSON, key/value pairs, or graph data.
