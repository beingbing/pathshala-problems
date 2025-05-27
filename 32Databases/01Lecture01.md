# Database Reliability: Replication

## Introduction

To scale our 3-tier system, we need to start with the tier containing the database (DB), file system (FS), and cloud storage. Our goal is to design a scalable system that ensures reliability and maintainability.

## Issues with Concurrent Access

### Reliability Concerns
1. Network issues between backend and DB.
2. Power outages.
3. Data corruption due to hardware failure.

### Scalability Concerns
1. Slowness due to processing many requests concurrently.

> **Note:** DB server maintainability is often handled by vendors, And whatever maintainability is needed at our end is covered under scalability.

## Ensuring Reliability

Reliability requires addressing:
1. Single Point of Failure (SPOF).
2. Handling incomplete transactions if the DB goes down.

### Replication Strategy

**Replication** involves creating a DB replica on another machine. If the primary DB fails, the backend redirects requests to the secondary DB to remedy SPOF.

#### Additional Benefits of Replication
- **Reduced Latency**: The secondary DB, located closer to the client, can respond faster than the distant primary DB.

#### Issues with Replication
1. **Data Updates**: New data must be stored and updated across all replicas.

    **Synchronous Updates (Consistency-Oriented)**:
    - Updates are confirmed to the client only after being successfully applied to all replicas.
    - Ensures strong consistency: all nodes have the same data.
    - Problems:
        - Increased write latency (compromised availability).
        - Need for heartbeat checks to monitor replica status. Because if a replica is down, it can fail the request even if all other replicas have successfully completed the request.

    **Asynchronous Updates (Availability-Oriented)**:
    - The DB processes and returns the response immediately, then updates other replicas asynchronously.
    - Lower latency for write operations, better availability and responsiveness.
    - Problems:
        - If the DB confirming the update fails before informing others, the change might be lost. This violates Durability aspect of ACID properties, which states that once a change is confirmed, it must persist.
        - Replication lag: changes might not be immediately visible to users connected to different replicas. But this delay is acceptable if happens in acceptable time limit.

    **Hybrid Approach**:
    - To balance consistency and availability, a hybrid approach can be used. For example, out of 5 replicas, if at least 3 confirm an update, it is considered successful. The remaining updates can be asynchronous.

> Note: The hybrid approach is a trade-off between consistency and availability.
