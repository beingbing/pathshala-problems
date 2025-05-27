# ⚖️ Load Balancers (LBs)
Now that we understand backend reliability with **replication** and **REST APIs**, let’s explore how **load balancers** ensure reliable and scalable backend communication.

## 🎯 What is a Load Balancer?
A **load balancer** is a layer between the client and backend servers (or between clients and a distributed database) that distributes incoming requests efficiently.
Think of it as a **traffic manager** ensuring requests are routed to healthy, available backend replicas.

## 🚀 Benefits of Load Balancers
- **Distributes load** among multiple backend replicas (or pods), preventing overload.
- **Detects unhealthy servers** via heartbeats and avoids routing requests to them.
- **Improves reliability**—eliminates single points of failure.
- **Enhances security**—can serve as an API gateway (e.g., verifying subscriber status or blocking malformed API calls).
- **Handles SSL/TLS security**—manages certificate handshakes to ensure secure connections.

## 🔍 Types of Load Balancers
There are two primary kinds:
- **Hardware-based LBs**
  * Physical devices that manage traffic (like network switches).
  * High cost but can handle high loads.

- **Software-based LBs** (e.g., Nginx, HAProxy)
  * Software running on servers, managing traffic based on configured rules.
  * Stores backend IPs, verifies requests, and routes them efficiently.

## 🛡️ Handling Load Balancer Failures
What if the load balancer itself fails? We can use **redundancy**:
* **Active-Passive LBs** (Master-Slave): One LB is active while others are passive backups. If the active one fails, a passive LB takes over. Risk: the active LB might become a bottleneck under heavy load.
* **Active-Active LBs**: All LBs are active and listed on DNS. Clients can pick any LB to send requests to. This design is complex and can be tricky to manage (e.g., client-side load selection).
