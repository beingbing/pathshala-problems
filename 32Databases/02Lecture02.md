## CAP Theorem in Distributed Databases
The **CAP theorem** explains that in a distributed system, it’s impossible to **guarantee all three of the following simultaneously**:
* **Consistency**: Every node sees the same data at the same time.
* **Availability**: Every request receives a response (though it may not contain the latest data).
* **Partition Tolerance**: The system continues to operate even when network partitions (communication breakdowns) occur.

A **network partition** happens when nodes in the system cannot communicate due to network failures, hardware issues, etc. Partition tolerance is effectively non-negotiable in real-world distributed systems, so the trade-off usually lies between **consistency** and **availability**.

### The Scaling → Reliability Chain
* To **scale**, we replicate and partition data across servers for **reliability**.
* **Replication** introduces the trade-off between **consistency** and **availability**.
  * **Synchronous replication** favors **consistency** (all nodes must confirm the update).
  * **Asynchronous replication** favors **availability** (nodes can respond independently).

### Consistency Patterns (Trade-offs of CAP Theorem)
These patterns represent levels of trade-off regarding consistency:

* **Weak Consistency**: Updates aren’t immediately propagated; it’s acceptable if nodes have outdated or divergent data.
  *Example: Analytics systems where occasional inconsistencies don’t break functionality.*

* **Eventual Consistency**: Updates eventually propagate to all nodes, ensuring consistency over time.
  *Example: Email systems, social media posts.*

* **Strong Consistency**: All nodes are immediately updated and return the same data.
  *Example: Banking and financial systems.*

#### Additional Nuanced Patterns:
* **Read-Your-Writes Consistency**: Once a write is acknowledged, subsequent reads (even from other nodes) reflect it.
  *Strategy: Session management or sticky sessions (track and stick to the same node).*

* **Monotonic Read Consistency**: Reads will never return older data than what’s been seen previously.
  *Strategy: Session management to ensure consistent reads from the same node.*

### A Critical Consistency Problem:
Consider a **distributed cluster** with nodes A, B, C, D, and E.

1. A client updates data on **A**; another client simultaneously updates different data on **B**.
2. Updates propagate asynchronously:
   * Some nodes receive A’s update first, then B’s.
   * Others receive B’s update first, then A’s.
3. Now, replicas disagree on which update is “latest,” creating **permanent inconsistency** since no clear “correct” value exists.

### Key Insight:
* **Replication** improves reliability but introduces a **trade-off**:
  * **Synchronous updates** favor **consistency** (at the cost of availability).
  * **Asynchronous updates** favor **availability** (at the cost of consistency).
* **Partition tolerance is mandatory**, so systems must **choose between consistency and availability** under network partitions.
