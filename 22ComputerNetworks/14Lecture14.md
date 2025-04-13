## ⏱️ Network Delays

Whenever data travels over a network, it encounters several types of **delays**. Understanding these helps in analyzing performance bottlenecks and optimizing systems.

---

### 1. **Transmission Delay**
🛠️ **What it is:**  
The time it takes to **push all bits** of a packet onto the transmission medium.

🧮 **Formula:**  
\[
\text{Transmission Delay} = \frac{\text{Packet Size (in bits)}}{\text{Transmission Rate (bps)}}
\]

📍 Happens at the sender's side, before data actually begins traveling.

---

### 2. **Propagation Delay**
🚀 **What it is:**  
Time taken for the **signal to physically travel** from the sender to the receiver over the medium (like copper wire or fiber optics).

🧮 **Formula:**  
\[
\text{Propagation Delay} = \frac{\text{Distance}}{\text{Propagation Speed of Medium}}
\]

📝 **Key point:** This is usually the **largest delay**, especially over long distances.

---

### 3. **Queuing Delay**
📦 **What it is:**  
Time a packet spends **waiting in a queue** at a router or switch before being processed.

📍 Varies based on **network traffic**. During congestion, queuing delay can be significant.

---

### 4. **Processing Delay**
🧠 **What it is:**  
Time taken to **analyze** the packet header and **process** it — includes tasks like error checking and deciding where to forward the packet.

📍 Occurs at both routers and the final destination.

---

### 🧠 Relative Delay Comparison

In most real-world networks:
\[
\text{Propagation Delay} \gg \text{Queuing Delay} > \text{Transmission Delay} \approx \text{Processing Delay}
\]
