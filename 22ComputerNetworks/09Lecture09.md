## 🔁 Flow Control – Reliable Data Transfer Between Sender and Receiver

Flow control ensures that data is **sent at a rate the receiver can handle** and that **lost or duplicated packets** are detected and handled properly.

---

### 🔍 Q1: How Do We Know If a Packet Was Dropped?

- When a packet is received correctly, the **receiver sends an ACK (Acknowledgement)** back to the sender.
- The **sender starts a timer** after sending a packet. If no ACK is received before the timer expires, it assumes the packet was lost and **resends** it.

> ❗ However, this has two potential issues:
1. The **ACK itself might get dropped**.
2. The **receiver can't tell** whether a packet is a **new one** or a **duplicate**.

🛠 **Solution: Add Sequence Numbers**  
Each packet is tagged with a **sequence number** so the receiver can identify and reorder packets, or detect duplicates.

---

## 📦 Flow Control Algorithms

---

### 1. 🚦 Stop-and-Wait Protocol

**How it works:**
- Send **one packet**, wait for its ACK.
- Only after receiving ACK, send the next packet.
- Uses **two sequence numbers**: 0 and 1 (alternating for each packet).

**Drawbacks:**
- **Very slow**, as only one packet is in transit at any time.
- **Inefficient**: For every packet, there's a corresponding ACK—doubling traffic.

---

### 2. 🚚 Go-Back-N Protocol

**How it works:**
- Sender sends a **window of `n` packets** without waiting for individual ACKs.
- Receiver sends a **cumulative ACK** (e.g., "I got up to packet 5").
- If **one packet is lost**, sender **resends all packets** starting from the lost one.

**Improvements:**
- Use **partial ACKs** to inform the sender exactly up to which packet was received, so retransmission starts from the next one.

**Sequence Numbers:**
- Needs **`n + 1` unique sequence numbers** to avoid confusion when numbers wrap around.

> 🔁 **Why wrap around sequence numbers?**  
Since packet numbers can grow infinitely, we **reuse numbers** once it's **safe** (i.e., when the previous round of packets using those numbers is confirmed as received).  
This wrap-around size is determined by the protocol (e.g., window size in Go-Back-N).

---

### 3. 🎯 Selective Repeat Protocol

**Improvement over Go-Back-N:**
- If packet `1` is lost but `2` and `3` are received, the receiver:
  - Sends **ACKs for 2 and 3**
  - Sends **NACK (Negative Acknowledgement)** for 1

**Advantage:**
- Sender **only resends missing packets**, not the entire window.

---

### 🔁 Summary Table

| Protocol          | ACK Type         | Efficient Use of Bandwidth | Handles Packet Loss | Sequence Numbers |
|------------------|------------------|----------------------------|----------------------|------------------|
| Stop-and-Wait     | Individual ACK   | ❌ Low                     | ✅ Yes               | 0, 1             |
| Go-Back-N         | Cumulative ACK   | ⚠️ Medium                 | ⚠️ Resends window   | n + 1            |
| Selective Repeat  | ACK + NACK       | ✅ High                    | ✅ Only resends lost| > 2n             |
