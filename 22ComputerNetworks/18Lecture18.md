## 📦 Distance Vector Routing (DVR)

**Distance Vector Routing** is a distributed algorithm where each router builds and updates its routing table by **sharing distance (cost) information with neighbors**. It doesn't need to know the entire network topology—just what each neighbor knows.

---

### 🔄 How It Works — Step-by-Step

1. **Initial Wake-Up:**
   - Each router initializes a routing table with direct links to its **immediate neighbors**, determined by sending **test (echo) packets**.
   - These tests help measure the cost (distance/time) to each neighbor.

2. **Table Sharing Begins:**
   - Routers **periodically share their routing tables** with neighbors.
   - Each router examines its neighbors' tables to learn about **other destinations** they can reach through them.

3. **Table Updates:**
   - If a neighbor offers a **shorter path** to a destination than what the router currently has, it updates its routing table accordingly.
   - Over time, this allows routers to **gradually discover better paths** to all destinations.

> This process is based on the **Bellman-Ford algorithm**, where routers iteratively update their path cost estimates using neighbors’ information.

---

### 🧠 Key Idea

> “If my neighbor has a shorter path to a destination, I’ll use that neighbor to forward packets there.”

Each router maintains a table:
```
Destination | Next Hop | Cost
```

---

### ⚠️ Drawbacks of Distance Vector Routing

#### 1. 🐢 **Slow Convergence**
- Routers don't have complete knowledge of the network and rely on periodic updates.
- When a router boots up, it takes **multiple rounds of table exchanges** to fully learn all routes.
- Mitigation: If a route is missing, the router can **ask a neighbor** or wait for an update.

#### 2. ♾️ **Count-to-Infinity Problem**
- Occurs when a router or link goes **down**.
- Neighbors set the route to the failed node as **infinite cost** (i.e., "unreachable").
- Known as **route poisoning**—bad routes are explicitly marked with a high cost to prevent usage.

> Problem: Neighbors may still advertise outdated routes through each other, leading to **slow convergence and loops** as routers increase path cost step-by-step until reaching infinity.
