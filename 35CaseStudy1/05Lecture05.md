# 🌐 **Designing a URL Shortener – System Design (Part 2)**
With the **database design** established, let’s now design the **backend servers and APIs** that power the URL shortener.

## 🏷️ **Core APIs**
### 1️⃣ `shorten(longURL)`
**Input:** A long URL (string)
**Output:** A unique, shortened URL

#### **How It Works:**
* The goal is to generate a **short URL token** (e.g., 6–7 characters) uniquely mapped to the given long URL.
* **MD5 hashing** (128-bit) is too long and impractical for short tokens.
* **Base62 encoding** (characters A–Z, a–z, 0–9) can create compact tokens from unique numbers (like timestamp-derived IDs), but using timestamps alone makes tokens **predictable** and vulnerable to guesswork.
* **Purely random tokens** from each server risk **collisions** (same token generated for different URLs). This would require extra **database checks** for uniqueness, increasing latency.

#### **Improved Approach:**
* Introduce a **centralized key-generation service** ("Key DB").
  * This service maintains a **pool of pre-generated unique tokens** (\~10⁹ keys).
  * Whenever a server needs a short URL token, it fetches one from this key pool.
  * This design ensures **global uniqueness** while avoiding collision checks and reducing latency.
  * The key-generation service periodically **replenishes the key pool** in the Key DB.

### 2️⃣ `getLongUrl(shortURL)`
**Input:** A short URL token (string)
**Output:** The original long URL

#### **How It Works:**
* The server directly queries the **database** to retrieve the corresponding long URL.
* **Read performance** is crucial here since the system is **read-intensive** (10:1 read/write ratio).

## ⚖️ **Load Balancing and Server Management**
### **Load Distribution:**
* Both APIs (`shorten` and `getLongUrl`) query the database, so a **round-robin load balancer** can distribute requests evenly across backend servers (S1, S2, S3).
* If servers have **different capacities**, use **weighted round-robin** to balance load proportionally.

### **Dynamic Load Adaptation:**
* Traffic varies over time, so we need a **Monitoring Service (MS)** to track server workloads.
* Based on real-time load data, we can shift from **round-robin** to **consistent hashing** for request distribution, ensuring stable performance even as server availability or load changes.

### 🧹 **Database Cleanup Service**
* URLs have expiration times, and the system must **remove expired entries** regularly to prevent unnecessary data buildup and maintain performance.
* A dedicated **cleanup service** scans the database and deletes expired short URLs.
