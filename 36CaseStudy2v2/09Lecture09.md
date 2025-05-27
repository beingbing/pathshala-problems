# 📝 **Code Submission Flow – Simplified**

## 🏗️ **Start with the Basics**
When a user submits code for execution, the **Submission Service** processes the request.
- **Initial Thought**: Spawn **one thread per submission** to run the code.
- **Why Not Threads?**
  * Threads share the **same memory** space as the parent process.
  * If one thread uses excessive memory or misbehaves, it can affect others.
  * Result: **Unreliable and unsafe** execution.
- **Better Approach**: Use **processes** instead of threads.
- Each process has **isolated memory**, reducing interference between submissions.

## 🚀 **Why Not Just Processes?**
- Processes are **isolated in execution** but not completely separated.
  - They **share the same filesystem (FS)**, so one process can still affect others by modifying files.
  - **Complete Isolation** would require one **process per machine**
  - impractical for high throughput.
  - E.g., for **30 requests/sec**, you’d need **30 machines/sec** – not feasible.

* **Solution**: **Containers**
  * Containers combine process-level isolation with a **separate filesystem and resource limits**.
  * Much **lighter** than VMs and **more scalable**.

## 📈 **How Many Containers Do We Need?**
* Each code submission uses about **512 MB RAM**.
* A typical server has **16 GB RAM**, so: Can handle \~**30 containers simultaneously**.

- **CPU Consideration**:
- A server with **8 CPU cores** can’t run 30 submissions in 1 second.
- If each submission takes \~1 second, the server can handle \~8 simultaneous submissions.
- To meet **30 submissions/sec**, we need at least **4 servers**.

* **Scalable Solution**: Deploy a **Kubernetes cluster with at least 4 nodes (machines)** to scale container deployment.

## 📦 **Container Creation Strategy**
**Why Not Create Containers Instantly?** Spinning up 30 containers per second is **resource-heavy and slow**.

### **Optimized Flow**:
- Client sends submission → **Server stores in DB** with a request ID.
- **Change Data Capture (CDC)** detects new submission and pushes it to a **Message Broker** (e.g., Kafka).
- **Worker threads (Consumers)** pull tasks from the broker **when they’re ready** and create containers to execute the code.
- Once done, results are **saved back in the DB**.

This approach ensures **asynchronous, scalable, and efficient** processing.

## ⚖️ **Handling High Request Volume**
- If we receive **30 requests/sec**, a single server might struggle.
  * Solution: Run **multiple replicas of the submission server** (e.g., 4 replicas on 8-core machines).
  * Use a **Load Balancer** with **Round Robin** distribution to evenly spread the load.

## 🏁 **Key Architecture Summary**
- **Request Handling**:
  * Client → Server → DB (save request, return request ID)
  * Multiple **server replicas** behind a **load balancer** for high availability.
- **Asynchronous Processing**:
  * CDC detects new submissions → Message Broker (Kafka) → Worker picks tasks → Container executes code → DB stores results.
- **Isolation & Scalability**:
  * Containers provide lightweight isolation with independent filesystem and resource limits.
  * Kubernetes manages container orchestration across multiple machines.
- **High Availability**:
  * Scale horizontally by adding servers or Kubernetes nodes as needed.
