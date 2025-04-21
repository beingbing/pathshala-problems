## 🧠 Congestion Control: Traffic-Aware Routing

**Congestion Control** is a key responsibility of the **Network Layer** (with some support from the Transport Layer). It aims to prevent excessive load on the network, which can lead to **packet delays**, **losses**, and overall **reduced performance**.

---

### 🚦 Problem Scenario

Suppose there are **two possible routes** between a source and a destination — one **shorter**, the other **longer**.

- Naturally, most traffic prefers the **shorter path**.
- But if the **destination processes packets slower** than the **source sends them**, the shorter path gets congested.
- Eventually, **queues build up**, and packets may get dropped or delayed.

---

### 🔄 Traffic-Aware Routing

To manage this, routers can dynamically **adjust the routing table** based on current traffic conditions. This is called **Traffic-Aware Routing**.

#### How It Works:
- The source sends **ECHO packets** through all possible paths.
- The **fastest returning packet** indicates the **least congested path**.
- The routing table is then updated to **prefer that path**.

> 📡 This technique tries to **detect congestion** in real time and **reroute** traffic accordingly.

---

### ⚠️ Core Limitation: Oscillating Routing Tables

However, this doesn’t solve the **root problem** — a source that's **too aggressive in sending data**.

- Even if paths are changed, the **overall load remains high**.
- All alternate paths eventually become **congested** as well.
- The routing table keeps **switching back and forth** between paths in search of relief.

This back-and-forth behavior is known as **Oscillating Routing**, where:
> The network **keeps reacting** to congestion but never actually **controls the source** causing it.

---

### 🔍 Key Insight

Traffic-aware routing **only shifts the problem** — it doesn't fix it. True congestion control must also involve:
- **Regulating the sender’s data rate**
- And/or using **feedback-based mechanisms** at the Transport Layer (e.g., TCP’s congestion window)

These strategies help reduce congestion **at the source**, not just **route around it**.
