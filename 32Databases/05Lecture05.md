# Multiple Leader Replication Model (Master-Master Replication)
While **Single Leader Replication** simplifies consistency, it struggles with **high write demands**. To handle this, we introduce the **Multiple Leader Model**, where **multiple nodes (leaders)** can accept writes.

### Basic Idea:
* **Multiple leaders** accept writes, while others (followers) may handle reads.
* This increases **write throughput** and reduces **write latency** by distributing write load.

### Benefits:
- **Higher write capacity**: Multiple leaders can handle more concurrent writes.
- **Lower write latency**: No single point of write entry.

### Challenges:
The core challenge is **conflicting writes** (just like in leaderless replication): When two leaders accept conflicting updates on the same data, we need a mechanism to **resolve which update is correct**.

### How conflicts are handled:
- **Last Write Wins (LWW)**:
  * Each update is given a **timestamp** (typically using **NTP** to synchronize clocks).
  * The **latest timestamp wins**—but this assumes perfect clock sync and can fail if clocks drift or timestamps are corrupted.

- **Manual conflict resolution**:
  * In case of **inconsistent updates**, where not all replicas are updated or a write is partially failed, **manual intervention** may be required.
  * The conflict is reviewed, and the correct value is chosen.

### Communication Between Leaders:
Leaders must exchange updates to keep each other consistent. This can be done in different **network topologies**:

- **Circle topology**:
  * Each leader communicates updates to just one adjacent node, forming a ring.
  * **Risk**: If any leader fails, updates cannot propagate through the ring.

- **Star topology**:
  * One central leader connects to all other leaders, acting as a hub.
  * **Risk**: If the central leader fails, the system's durability is compromised.

- **All-to-All topology**:
  * Every leader sends updates to every other leader.
  * **Issues**:
      * **Causality problem**: For example, if node B updates a value and sends it to C while C hasn't yet received the original value from A, it can create conflicts. This requires maintaining **ordering of updates** (timestamps, vector clocks).
      * **Duplicate propagation**: Updates may keep bouncing between nodes unless we track which updates have been seen by which node.
      * **CouchDB** uses this multi-leader model with conflict resolution strategies.

### Summary:
* **Multiple Leader Replication** improves **write performance** but introduces **complexity in consistency** and **conflict resolution**.
* Synchronizing multiple leaders demands careful handling of **update ordering** and **duplicate updates**.
* It's more robust than single-leader under high write loads but less consistent unless conflicts are managed carefully.

### What’s Next?
We’ve explored:
1. **Leaderless replication**—complex consistency management.
2. **Single leader replication**—simpler but bottlenecked.
3. **Multiple leader replication**—higher write capacity but complex conflict management.

Next, we’ll address a key reliability challenge:
💡 **What happens to ongoing transactions if a database node goes down?**
