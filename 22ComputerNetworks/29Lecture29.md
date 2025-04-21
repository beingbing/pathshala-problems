## 🚫 Congestion Control: Admission Control (Proactive Approach)

All methods we've discussed so far — like **ECN** and **Backpressure** — were **reactive**:  
> They respond **after** congestion has already started.

But what if we could prevent congestion from occurring in the first place?

That’s the idea behind **Admission Control** — a **proactive** strategy where we **control the rate of packet inflow** into the network so that routers never get overwhelmed.

---

### 🔐 How Admission Control Works

Each router enforces a **maximum transmission rate** — i.e., how many packets it will forward in a given time frame.

This limit is enforced using **rate-limiting algorithms**, mainly:
- **Leaky Bucket**
- **Token Bucket**

These algorithms are widely used in network systems and general computer science for **throttling** and **rate control**.

---

### 🪣 Leaky Bucket Algorithm

**Concept**:  
The router maintains a fixed-size **bucket (queue)** where packets wait before being forwarded.

- **Packets arrive at any rate**, but they are **transmitted (leak out)** at a **constant rate**.
- If the bucket is **full**, new incoming packets are **dropped** — hence the term "leaky".

#### ⚠️ Drawbacks:
- **Packet Loss**: Incoming packets get dropped if there's no space in the queue.
- **Increased Latency**: Even if a packet enters the bucket, it may be **delayed** due to fixed-rate output.

---

### 🎟️ Token Bucket Algorithm

**Concept**:  
Here, sending packets requires **tokens**, which are generated at a fixed rate.

- Tokens are stored in a **token bucket**.
- Each packet requires a token to be transmitted.
- If tokens are available, packets **flow at burst speeds**; otherwise, they must wait for tokens to replenish.

#### ✅ Advantages over Leaky Bucket:
- Allows **burstiness** — i.e., short-term surges in traffic can be handled smoothly.
- More **flexible** than leaky bucket as it doesn’t strictly enforce a constant output rate.

#### ⚠️ Drawbacks:
- If token generation rate is too low, high-volume legitimate traffic might get delayed or blocked.
- If not tuned properly, short bursts might still overwhelm downstream routers.

---

### 🧠 Summary

| Feature            | Leaky Bucket                        | Token Bucket                        |
|--------------------|-------------------------------------|--------------------------------------|
| Flow Rate          | Constant (strict)                  | Flexible (allows bursts)             |
| Overflow Handling  | Drops excess packets               | Waits for tokens                     |
| Use Case           | Smooth and predictable flow        | Bursty and variable traffic          |

---

In essence:
- **Leaky Bucket** = Smooth, constant flow (good for shaping).
- **Token Bucket** = Controlled bursts (good for policing and flexibility).
