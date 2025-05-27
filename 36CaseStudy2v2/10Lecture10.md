# 📤 **Result Fetching Flow – Simplified**

## 📦 **How the Result Reaches the Client**
Once a **submission’s result** is saved in the **Result-DB** (typically stored as an output file linked to the submission-entry-ID):
- A **Change Data Capture (CDC)** mechanism detects the new result.
- The CDC triggers an event, pushing the **submission ID** into a **Kafka queue** dedicated for the **Result Service**.
- **Result-service workers (consumers)** pick up tasks from this Kafka queue.

## 🔄 **How the Result Reaches the Client**
The **Result Service** can deliver the result back to the client in multiple ways:
* **1️⃣ Polling (Synchronous Check)**
  * The client periodically sends requests asking for the result.
  * When the result is ready, the server responds with it.
  * **Limitations**: Simple but inefficient and not scalable; wastes resources due to repeated requests.
* **2️⃣ WebSockets or SSE (Asynchronous Push)**
  * A **persistent connection** is established between the client and the Result Service as soon as the submission is accepted.
  * When a Result-Service worker picks up a completed result from Kafka, it finds the matching client connection and sends the result immediately.
  * **Advantages**: More efficient and real-time.
      * **WebSockets**: Bi-directional communication.
      * **SSE (Server-Sent Events)**: Unidirectional (server-to-client) communication.
* **Considerations**: SSE is often preferred for its simplicity and built-in reliability for push notifications.

## ⚙️ **Reliability, Scalability, and Maintainability**
* **Submission Service**
  * **Reliability**: Achieved via multiple replicas and a load balancer.
  * **Scalability**: Scales horizontally by adding replicas.
  * **Maintainability**: Focuses solely on handling submission requests.

* **Result Service**
  * **Reliability**: If a Result-Service replica fails, **WebSocket/SSE connections** tied to it are lost. The client must reconnect, as WebSockets/SSE connections are server-instance specific.
  * **Scalability**: A single service instance can handle around **30 simultaneous connections**. Additional replicas can be added if the load increases.
  * **Maintainability**: Simplified by focusing solely on delivering results.
* **Kafka Queues**
  * **Reliability, Scalability, Maintainability**: Managed through Kafka’s distributed architecture, offering durability, load balancing, and fault tolerance.

## 🚀 **Summary of Result Fetching**
- Result saved in **Result-DB** triggers **CDC → Kafka queue**.
- **Result Service workers** pull results from Kafka.
- **Delivery Options**:
  - Client can **poll** (inefficient but simple).
  - **WebSockets or SSE** enable **real-time, efficient delivery**.
    4️⃣ Architecture is **reliable, scalable, and maintainable**, leveraging **Kafka**, **load balancers**, and **replicas**.
