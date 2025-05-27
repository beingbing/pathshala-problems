# Single Leader Replication Model (Master-Slave Replication)
In contrast to the complex **leaderless replication model**, a simpler approach—**Single Leader Replication**—is commonly used. Here’s how it works:

## Basic Idea:
* The system follows a **Master-Slave (Leader-Follower) architecture**:
    * **Leader (Master)**: The primary node that handles **all writes**.
    * **Followers (Slaves)**: Replicas that receive updates from the leader and can serve **read requests**.
* **Writes are allowed only on the leader**, while **reads can happen on both leader and followers**.

### Update Propagation:
* The leader propagates changes to followers using either:
    * **Synchronous replication** (waits for acknowledgments, more consistent but slower).
    * **Asynchronous replication** (doesn’t wait, faster but less consistent—used \~99% of the time).

## Advantages:
- **Data durability**: Multiple replicas increase resilience.
- **Higher read throughput**: Followers can handle read traffic, reducing load on the leader.

## Challenges:
- **Leader bottleneck**: All writes go through the leader, which can become overloaded.
- **Increased write latency**: Writes must pass through the leader, which may slow operations. 
- **Single point of failure**: If the leader fails, writes halt, and there’s potential for **data loss** if not all updates were propagated.

## Addressing Leader Failure (Failover):
* If the leader fails, a **failover mechanism** is used to promote a follower to be the new leader.
* **Options for selecting the new leader**:
    * **Seniority-based**: Promote the longest-serving follower.
    * **Latest-update-based**: Promote the follower with the most recent data.

### Key Challenges in Failover:
* **Detecting failure**:
  * Followers use **timeouts**—if the leader doesn’t respond within a predefined time, failover is triggered.
  * This timeout needs careful tuning to avoid premature or delayed failover.

* **Selecting the new leader**:
  * Based on pre-decided seniority or data recency.
  * The system must **reroute all writes to the new leader**, which introduces:

* **Routing challenges**:
  * Clients may continue to send writes to the old leader or an outdated address.
  * Solution: **Writes can be initially sent to any node, which then forwards them to the current leader**.

* **Split-brain problem**:
  * If the old leader comes back online after failover, the system may have **two leaders** with diverging data.
  * To resolve this, the system must **detect and eliminate one of the conflicting leaders** to maintain consistency.
