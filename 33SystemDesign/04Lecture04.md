# 🎯 **Consistent Hashing for Random Load Balancing**
When distributing requests randomly, we often want **consistency**—so a user gets routed to the same server every time. This is especially important when servers go down or new servers come online. Enter **Consistent Hashing**. It ensures that adding/removing servers affects only a small portion of requests.

## 🔗 **The Challenge**
* If we use a simple hash function to map requests to servers, adding or removing a server (or replica) can shift mappings for many requests.
* This disrupts consistency, causing unnecessary cache misses or session issues.

## 🔄 **The Hash Ring (or Circle)**
- **Visualize servers arranged in a circle**, each mapped to a random point in a fixed range (say, 0–10). This circle is called a **hash ring**.
- Every **request is hashed** to a number in this range. The request is assigned to the **next server in a clockwise direction**.
- If a server goes down, requests mapped to its positions are rerouted to the next server in the ring.

## 🏗️ **The Problem**
When a server dies, its entire load shifts to its immediate neighbor, creating a bottleneck.

## 💡 **The Solution: Virtual Nodes (or Replicas)**
Instead of mapping each server to just one point on the ring:
- **Map each server to multiple points (virtual nodes)**. For example, with a hash range of 0–100 and 3 servers, map each server to 5–10 different points on the ring.
- This way, when one server goes down, its load **spreads across multiple servers**, not just one.
- This also balances the load more evenly when new servers join or leave.
- Commonly used in **distributed caching systems** (like Memcached, Redis), **distributed databases**, and **content delivery networks (CDNs)**.
