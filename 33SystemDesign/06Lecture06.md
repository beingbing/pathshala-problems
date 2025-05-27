# 🔍 **Service Discovery in Microservices**
In a **microservices architecture**, services need to **find and communicate with each other**. This is called **service discovery**.

## 📡 **Why Do We Need It?**
* Each microservice runs on its own machine (or container), with its own IP and API endpoints.
* Machines might **change IP addresses** or **scale dynamically** (adding/removing replicas), making static configurations unreliable.
* Therefore, we need a dynamic way for services to locate one another.

## 🛠️ **How Can We Implement Service Discovery?**
### **1️⃣ Static Configuration**
* Hardcode the location of each service (IP addresses and ports) in configuration files.
* Works for small, static systems.

🚨 **Drawbacks**:
* IP changes require updating configurations everywhere.
* Scaling a service (e.g., adding replicas behind a load balancer) also demands config updates in all dependent services.

### **2️⃣ Dynamic Discovery Using a Discovery Server**
A **central registry** (discovery server) keeps track of all services and their locations:
* Each microservice **registers itself** with the discovery server upon startup.
* Other microservices query the discovery server to **find where to send requests**.

## 🔀 **Two Approaches to Service Discovery**
#### 🧑‍💻 **A. Client-Side Discovery**
* The **client microservice** queries the discovery server to get the location of the target service.
* The client then directly calls the target service’s API.
* **Pros**: Simple and flexible.
* **Cons**:
  * The client has to make two requests (discovery + actual call).
  * Clients need discovery logic built-in.

### 🖥️ **B. Server-Side Discovery**
* The client sends the request to the discovery server.
* The discovery server forwards the request to the appropriate service and returns the response.
* **Pros**: Clients don’t need to know discovery logic.
* **Cons**:
  * Adds an extra network hop, increasing latency.
  * If the discovery server fails, service communication breaks.

## 💡 **Bonus Insight: Load Balancer as Discovery Server**
In some systems, the **load balancer itself acts as a discovery service**:
* It maintains a **registry of service locations** and handles **traffic distribution**.
* This combines **load balancing and service discovery** into a single layer, simplifying architecture.

## 🧭 **What’s Next?**
In upcoming discussions, we’ll explore how load balancers can take on additional roles in system design, including **API gateway**, **security enforcement**, and more.
