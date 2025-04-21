## 🚨 Congestion Control: Traffic Throttling

In congestion control, we not only need to **detect** congestion but also **respond** effectively by instructing the sender to **slow down**.

---

### 📉 Why Traffic Throttling?

Even with smart routing (like traffic-aware routing), the **core issue** remains:  
> The **source is generating packets faster** than the network can handle.

So, we need mechanisms to **throttle** the sender’s speed — i.e., force it to **reduce the transmission rate**.

---

### 🔍 Step 1: Detecting Congestion

The **router** is in the best position to detect congestion since it handles packet forwarding.

- Each router maintains a **queue** of packets to be forwarded.
- If this queue **grows beyond a threshold** for a specific destination, the router infers that **congestion is building up**.

---

### 📦 Step 2: Preventing Congestion (Informing the Source)

Once a router detects congestion, it must **inform the source** to slow down.

A **CHOKE packet** is used to notify the source to reduce its transmission rate.

---

### ❓But Who Gets the CHOKE Packet?

You might think the router can:
> Analyze the queue and identify which **source** is sending the most packets.

But routers are designed to be **lightweight and fast**, so this kind of per-source analysis isn't feasible.

---

### 🧠 Practical Solution: ECN (Explicit Congestion Notification)

- The router **randomly selects a packet** from the queue.
- It assumes this packet belongs to a source contributing to congestion.
- A **CHOKE packet** is sent back to that **source**.

#### 🚫 Drawbacks of ECN:
1. The **wrong source** might be notified — actual offender continues to congest the network.
2. By the time the CHOKE packet reaches the source, **many more packets** may have already worsened congestion.

---

### ⛓️ Improved Strategy: Hop-by-Hop Backpressure

To respond **faster and more locally**, routers use **Hop-by-Hop Backpressure**.

- Instead of contacting the source directly, the router informs its **immediate neighbor (previous hop)** to **slow down**.
- This signal is **propagated backward hop-by-hop**, effectively applying pressure to reduce incoming traffic.

> 🧩 This method spreads the throttling responsibility across the network and responds faster than ECN.

---

### ⚠️ Common Limitation in Traffic Throttling

Despite improvements, **all throttling techniques** suffer from:
- **Delayed feedback** to the actual source.
- Difficulty in **pinpointing the exact sender** causing the congestion.

So, while throttling helps, it doesn't provide an **instant fix**.

---

### 🛠️ Coming Up: Leaky Bucket & Token Bucket

To regulate packet flow more precisely and proactively, we’ll explore **rate-limiting algorithms** like:
- **Leaky Bucket**
- **Token Bucket**

These mechanisms control traffic **at the source**, preventing congestion from forming in the first place.
