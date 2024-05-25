# Scaling 10x

With a load increase to 300 requests per second and 80 TB of data per day, our architecture can be
adjusted to maintain performance and reliability. 

**Components that Scale Well Horizontally:**

- **Submission Service**:
  - Use a smarter load balancer that allocates requests based on machine performance rather than
  round-robin.
  - Handle file uploads to cloud storage asynchronously.

- **Clean-Up Service**:
  - Run multiple times a day to manage the increased data load.

- **Submission and Result DB**:
  - No significant changes needed; current setup should handle the load well.

**Areas Needing Adjustment:**

- **Submission-Service Workers**:
  - Create separate clusters for different programming languages.
  - Allocate more machines to clusters with heavier loads.
  - If a cluster fails (e.g., due to a language version update), it can be fixed independently
  without affecting other clusters.
  - This improves maintainability under increased load.

- **Result-Service Workers**:
  - Instead of directly writing to the DB, put generated results in a queue.
  - Use dedicated DB threads to manage write operations of result-service to the DB, reducing
  dynamicity of internal direct load and managing write-intensive tasks more efficiently.

- **Result-Service**:
  - Implement multiple replicas to handle 300 concurrent connections.
  - Use sharding with consistent hashing to distribute connections across replicas. For example,
  based on hashing 50 connections go to the first replica, the next 50 to the second, and so on.
  - This ensures that each machine maintains a manageable number of connections.

By implementing these adjustments, we can efficiently scale our system to handle a 10x increase in
load while maintaining reliability, maintainability, and scalability.
