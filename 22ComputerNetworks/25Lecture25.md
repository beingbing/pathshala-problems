## 🚀 Introduction to the Transport Layer

### 🌐 Recap of Layers (Top to Bottom)

```
7. Application
6. Presentation
5. Session
---------------------
4. Transport   ← Now
---------------------
3. Network      ✅
2. Data Link    ✅
1. Physical     ✅
```

Until now, we’ve focused on:
- **How to establish connectivity** between two devices over a network
- Ensuring reliable delivery **between directly connected nodes** (Data Link Layer)
- Finding the **route across multiple networks** (Network Layer)

But here's the **problem we haven't solved yet**:

> ✅ A path exists between sender and receiver  
> ❌ But how do we ensure **end-to-end reliability** over that path?

---

## 🔒 Enter the Transport Layer

The **Transport Layer (Layer 4)** is responsible for **end-to-end delivery of data between applications**, not just devices.

It ensures that the data **arrives correctly, completely, and in order**, even when passing through multiple intermediate nodes.

---

## ✨ Key Responsibilities of the Transport Layer

1. **Error Control**
   - Similar to the Data Link Layer — but at a **global scale**.
   - Ensures that data corrupted or lost in transit is **detected and retransmitted**.

2. **Flow Control**
   - Ensures that a **fast sender doesn’t overwhelm a slow receiver**.
   - Regulates the rate of data transmission between source and destination.

3. **Congestion Control**
   - Helps avoid network overload.
   - **Works together with the Network Layer** to reroute or delay packets when the network is congested.

4. **Segmentation and Reassembly**
   - Breaks large messages into smaller segments before sending.
   - Reassembles them correctly at the receiver's end.

---

## 📦 Transport Layer Protocols

Two major protocols operate at this layer:

| Protocol | Full Form | Nature | Use Case |
|----------|------------|--------|----------|
| **TCP** | Transmission Control Protocol | Reliable, connection-oriented | Web browsing, emails, file transfer |
| **UDP** | User Datagram Protocol | Fast, connectionless | Streaming, gaming, DNS |

We’ll explore TCP and UDP in detail next.
