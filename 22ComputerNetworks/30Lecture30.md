## 🔻 Congestion Control: Load Shedding & RED (When Prevention Fails)

So far, we've looked at **preventing** congestion (Admission Control) and **managing** it (Traffic Throttling).

But what happens when congestion **already** occurs?

That’s when we use **Load Shedding** — the last-resort strategy.

---

### 🧹 Load Shedding: Dropping Packets to Reduce Load

**Concept**:  
When a router's queue is completely full, it has no choice but to **drop some packets** to relieve pressure.

But which packets should be dropped? That depends on the **type of traffic**:

#### 1. **Live Streaming / Real-time Data (Milk model)**
- Drop **older packets** — they're already stale and useless.
- Keeping newer packets maintains the **continuity of the stream**.

#### 2. **File or Document Transfers (Wine model)**
- Drop **newer packets** — the earlier ones are already part of the transfer.
- Losing newer packets allows the system to **resume more easily** later via retransmission.

---

## 🚦 RED – Random Early Detection

**RED (Random Early Detection)** is a **proactive load shedding mechanism**.

### 💡 Idea:
- Instead of waiting until the queue is full, routers **start dropping packets early** — when the queue length crosses a certain **threshold (x%)**.
- This acts as an early warning to sources to **slow down**, thus preventing full-blown congestion.

### 🔧 How RED Works:
- It **randomly drops** packets with increasing probability as queue size grows.
- This randomness avoids penalizing a single flow repeatedly.
- It’s often used in **strict, high-performance networks** where congestion must be tightly controlled.

---

## 📌 Summary of Approaches

| Strategy             | When Used                  | Action Taken                              |
|----------------------|----------------------------|--------------------------------------------|
| Admission Control     | Before congestion          | Controls rate of packet entry              |
| Traffic Throttling    | As congestion builds       | Notifies source to slow down               |
| Load Shedding         | After congestion occurs    | Drops selected packets to free up space    |
| RED                   | Before full congestion     | Randomly drops packets to signal slow down |
