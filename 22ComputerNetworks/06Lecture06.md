## 🔀 Switching Technologies in Networking

To transmit data from one device to another, we use **switching techniques**. These determine **how data travels** through a network.

---

### 1. ⚡ Circuit Switching

This is the method used in traditional telephone networks.

#### How it works:
- A **dedicated path** is established between source and destination **before** communication begins.
- All data follows this **same fixed path** during the entire session.

#### ✅ Pros:
- Reliable and ordered data transfer.
- Consistent bandwidth and no interference.

#### ❌ Drawbacks:
- **Resource underutilization**: Once a path is established, it remains reserved even if no data is being transferred.
- **Limited scalability**: Only a fixed number of connections are possible at a time.
- **Single point of failure**: If any node in the path fails, the entire connection breaks.

---

### 2. 📦 Packet Switching

Used in the **internet and modern communication systems**.

#### How it works:
- Data is broken into **packets** (small chunks).
- Each packet is routed independently, possibly taking **different paths** through the network.
- Packets are reassembled at the destination.

#### ✅ Advantages:
- **Efficient resource usage**: No need for dedicated lines.
- **Scalable**: Supports a large number of users.
- **Resilient**: If one path fails, packets can take alternate routes.

#### ❌ Drawbacks:
- **Higher complexity**: Each router/switch must make dynamic routing decisions for every packet.
- **Out-of-order delivery**: Packets may arrive in the wrong sequence; the receiver must reassemble them.
- **Packet loss**: Congestion can lead to some packets being dropped.
