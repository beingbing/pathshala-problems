# 🚀 **How to Approach System Design Problems**
Unlike DSA problems (which often have definite solutions), system design problems are **open-ended**. There’s rarely a "correct" design. Instead, the goal is to **discuss, explore trade-offs, and iteratively improve the design** based on **requirements** and **constraints**.

Here’s a **roadmap** to systematically tackle system design questions:

## 📝 **1. Clarify Requirements**
Start by clearly understanding the **functional** and **non-functional** requirements.
* **Functional Requirements**: What should the system do?
  Example:
  * Input → `userId`, Output → user’s timeline
  * Input → `tweet`, Output → confirmation of post

* **Non-Functional Requirements**: How should the system perform?
  * **Availability**: Should the system be highly available (e.g., 99.99%)?
  * **Latency**: What is the acceptable response time?
  * **Consistency**: Do we prioritize strong or eventual consistency?

💡 **Tip**: Ask clarifying questions to **drill down the scope** before jumping into design.

## ✏️ **2. Back-of-the-Envelope Estimations**
Estimate the **scale** and **load** of the system to understand resource needs.
* Data volume: How much data (e.g., GBs or TBs) per day/month?
* Requests: How many requests/second?
* Read/Write ratio: Are we read-heavy, write-heavy, or balanced?
* Storage: How much capacity is needed?
* Load: What are peak load expectations? How will we balance it?

💡 **Tip**: These rough estimates help decide capacity planning, caching needs, and database partitioning.

## 🏗️ **3. High-Level Architecture**
Sketch an initial architecture (often a **three-tier system**: frontend – backend – database).
* **Frontend**: Focus is minimal unless explicitly asked.
* **Backend**: APIs, services, and logic.
* **Database**:
  * Choose a suitable DB type (SQL, NoSQL, distributed DB, etc.).
  * Model data relationships (ER diagrams).
  * Discuss indexing, partitioning, sharding, or federation if needed.

💡 **Tip**: Use diagrams to clearly illustrate how components interact.

## 🔎 **4. Deep Dive into Key Components**
Iteratively refine the design by diving deeper into **critical components** based on the problem’s specifics.
* Backend: Discuss service interactions, data flow, failure recovery.
* Database: Explore consistency models, replication strategies, fault tolerance.
* Caching: Where and how should we cache (e.g., at API level, DB query results)?
* Queueing: Should we use message queues for async processing?

💡 **Tip**: Focus on **backend and database** layers—frontends are generally simpler unless the system involves complex UI interactions.

## 📈 **5. Scaling Considerations**
Anticipate growth. Think about:
* Increased data volume: How will storage scale (e.g., horizontal scaling)?
* Increased request load: How to scale backend services and databases?
* Geographical distribution: How to handle global users (e.g., CDNs, multi-region DBs)?
* High availability: How to handle server failures or network partitions?

💡 **Note**: Sometimes interviewers may **skip estimations (Step 2)** and jump directly into design. Be ready to adapt!
