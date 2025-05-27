# 🌐 **Designing a URL Shortener – System Design (Part 1)**
Let’s design a scalable and reliable URL shortener system capable of handling a **global user base**.

## 📈 **System Scale Overview**
Our system needs to handle:
* **10 million global users**
* **Read/Write ratio**: \~10:1 (read-intensive system)
* **Data volume**: \~12.9 GB/month (≈150 GB/year, assuming 1-year URL expiry)
* **Active short URLs**: Up to **240 million**
* **Short code format**: 6-character strings (62⁶ ≈ 56.8 billion possible combinations, sufficient for uniqueness)
* **Request load**: \~3 write requests/sec, \~30 read requests/sec
* **Infrastructure**: 2–3 backend servers + 2–3 database replicas

## 🏗️ **High-Level Architecture**
```
Client Request to Shorten URL ↔ Frontend  
                                       |
                                       ↓
                                Load Balancer (LB)
                                       |
       ┌───────────────────────────────┴─────────────────────────────┐
       |                          Backend Servers                    |
       |      ┌───────────┐      ┌───────────┐      ┌───────────┐   |
       |      |    S1     |      |    S2     |      |    S3     |   |
       |      └───────────┘      └───────────┘      └───────────┘   |
       └────────────────────────────────────────────────────────────┘
                                       |
                                       ↓
                          ┌─────────────────────────────────┐
                          |       Database Replicas         |
                          | ┌────────┐  ┌────────┐ ┌──────┐ |
                          | |   R1   |  |   R2   | |  R3  | |
                          | └────────┘  └────────┘ └──────┘ |
                          └─────────────────────────────────┘
```
* **Frontend** handles user interactions, forwarding requests to a **load balancer (LB)**.
* The LB distributes traffic across multiple **backend servers (S1, S2, S3)**, ensuring fault tolerance and horizontal scalability.
* Each backend interacts with **database replicas (R1, R2, R3)** for reading and writing data.

## 🔒 **Ensuring Uniqueness and Data Consistency**
* **Global user base** requires a **single-leader replication model** (e.g., a primary database instance), ensuring each **short code is globally unique** and never points to multiple long URLs.
* **Writes (new URL mappings)** go through the **leader replica**, while **reads** are distributed across **replicas** for load balancing.

## ⚙️ **Consistency and Availability**
* The system aims for **eventual consistency** to ensure **low latency**, but introduces safeguards:
  * **Synchronous updates** to the **secondary leader replica** (next in line) before propagating asynchronously to the rest.
  * This minimizes the risk of data loss if the primary replica fails while ensuring quick response times for user requests.

## 🗃️ **Scalability and Storage**
* **Sharding (partitioning)** is **not required** as data volumes are manageable (\~1.5 TB over 10 years), which can easily fit within modern server storage capacities.
* **NoSQL solutions** like **Amazon DynamoDB** or **Riak** are well-suited for storing URL mappings, as they provide:
  * **Horizontal scalability**
  * **High availability**
  * **Low-latency reads and writes**
