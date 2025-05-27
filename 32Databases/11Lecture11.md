# Types of Indices in Databases
When we create **indices** to improve query performance, the underlying **data structures** fall into two broad categories:
* **Unordered (hash-based)**
* **Ordered (tree-based)**

Each has its own strengths, limitations, and use cases.

## 🗂 A. Unordered Indices
Unordered indices use **hashing or bitmaps** to enable fast, exact-match lookups.

- **Hash Table**
  * Maps keys to values using a **hash function**.
  * Enables **O(1) lookup** (in ideal cases).
  * Not suitable for **range queries** or ordered traversal.
  * Typically stores **pointers to locations (or buckets)** where records with the same hash key reside.

- **Bitmap Index**
  * Uses a **bitmap (bit array)** to represent presence/absence of data.
  * Effective for columns with **low cardinality** (few distinct values), e.g., gender, yes/no fields.
  * Often used in **analytical databases**.

- **Inverted Index**
  * Commonly used in **text search engines** (like Elasticsearch).
  * Maps **words (tokens)** to their occurrences (document IDs).
  * Enables **fast full-text search**.

## 🌳 B. Ordered Indices
Ordered indices organize data in **sorted structures** for both exact matches and **range queries**.

- **B-Tree**
  * A balanced search tree where keys are **sorted**, and each node has multiple children.
  * Ensures **O(log n) lookup**, suitable for general indexing.

- **B+ Tree**
  * An enhancement of B-Tree where all values are stored in **leaf nodes** and internal nodes only hold keys.
  * Leaf nodes are linked, enabling **efficient range scans**.
  * Commonly used in databases for **range and sorting queries**.

- **Suffix Tree/Array**
  * Advanced structures used for **string processing** and pattern matching.
  * Useful in **bioinformatics** and **text indexing**, but less common in general-purpose databases.

## Tradeoff
- Indexing improves **query speed**, but at a cost:
  * **Insertion and deletion become slower** (as indices need to be updated).
  * **Extra memory and disk space** are needed for maintaining indices.
- Indexing is a trade-off between **query time (faster)** and **resource usage (higher)**.
