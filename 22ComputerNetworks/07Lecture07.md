## 🧩 Introduction to the Data Link Layer (DLL)

The **Physical Layer** deals with the **hardware** aspects of communication—how bits move across wires or wireless mediums. However, hardware alone can’t ensure reliable communication.

This is where the **Data Link Layer** steps in—it handles the **software-level responsibilities** to ensure smooth and reliable data transfer between two directly connected nodes (called *peers*).

---

### 🎯 Responsibilities of the Data Link Layer

#### 1. ✅ Error Control  
Ensures that data received is **accurate and intact**.  
If a packet (or frame) is found to be **corrupted** (e.g., due to interference), it is discarded and a **retransmission** is requested from the source.

📦 Example:  
Source sends `xyz`, but interference changes it to `xya` → DLL at destination detects the error and requests `xyz` again.

---

#### 2. 🔁 Flow Control  
Prevents the **sender from overwhelming the receiver**.  
If the receiver is slower or temporarily busy, DLL ensures that packets are sent at a manageable pace, and **resends dropped packets** if needed.

---

#### 3. ⚖️ Access Control  
When multiple devices share the same communication medium (like a shared bus or Wi-Fi), DLL manages **who can send data at a given time** to prevent **collisions** and data loss.

---

### 🧱 What is a Frame?

At the Data Link Layer, data is organized into units called **frames**.

A **frame** = Data + Metadata (header/footer)  
This metadata includes:
- Sender and receiver info
- Error-checking bits
- Control flags, etc.

Frames help the DLL **identify, verify, and manage** each data packet during transmission.
