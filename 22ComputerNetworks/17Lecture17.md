## 🌐 Connectionless Routing (Datagram Routing)

Unlike **connection-oriented routing**, where a fixed path is set before data transfer, **connectionless routing** treats every packet independently. Each packet may take a **different route** to reach the destination.

---

### 🧭 Key Objective

Each router must answer this question:
> “From me, which neighboring router leads to the **shortest path** to the destination?”

To find this, routers compute the **shortest path** to every other node in the network.

---

### 📊 Using Dijkstra’s Algorithm

To determine the shortest path from a router to all others, **Dijkstra’s algorithm** is commonly used. It builds a shortest path tree using:

- **Graph of the network**: Routers as nodes, links as edges.
- **Edge weights**: Cost associated with each link.

---

### 🧩 The Core Problems

#### **Problem 1: Knowing the Full Network Graph**

To run Dijkstra, a router must have **complete information** about all routers and links in the network. This is not always available directly and must be **gathered and updated continuously**.

#### **Problem 2: Defining Link Weights**

How should we measure the cost (weight) of each link in the graph?

- ❌ **Physical wire length** – Not reliable; doesn't reflect real-time traffic or delays.
- ✅ **Echo/Test packets** – Sent periodically to estimate actual **travel time or delay**, but:
    - Weights **change dynamically**, requiring **frequent updates**.
    - Can introduce overhead.

---

### 🔁 Reframing the Challenge

To keep routing decisions optimal, routers must:

1. **Continuously gather** up-to-date information about the full network topology.
2. **Recompute paths** whenever that information changes (due to node failures, new links, congestion, etc.).

Different **routing protocols** (like Link State or Distance Vector) aim to solve these challenges efficiently. We’ll explore those next.
