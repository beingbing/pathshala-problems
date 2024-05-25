# Result Fetching

When a result is saved in the Result-DB against the submission-entry-ID in an output file. This
action triggers a CDC, which picks up the ID and places it in another Kafka-Queue where
Result-service Workers are active.

The result-service has several ways to send the result back to the client:
1. **Polling**: Send the result when the next polling request is received. It will not require any
Worker or Kafka-queue on top of result-service. However, this method is not scalable.
2. **Websockets/Server-Sent Events**: Establish a connection between the Client and Result-service
as soon as a submission is saved.

When a Result-service Worker picks up a result, it will find the corresponding connection and send
the result.

### Ensuring Reliability, Maintainability, and Scalability

**Submission Service:**
- **Reliability**: Achieved through multiple replicas and a load balancer.
- **Maintainability**: Simplified by focusing on a single task.
- **Scalability**: Managed with multiple replicas and a load balancer.

**Result Service:**
- **Reliability**: If a replica goes down, connections are lost and must be re-established by the
client due to the server's stateless nature.
- **Maintainability**: Simplified by focusing on a single task.
- **Scalability**: A single service instance can handle 30 connections, with only one active at a
time, making additional replicas unnecessary.

**Kafka Queues:**
- **Reliability, Maintainability, Scalability**: Handled by using distributed Kafka Queues, which
provide these features out of the box.

Next, we will discuss submission-DB and result-DB.
