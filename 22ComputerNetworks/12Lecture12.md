## 🧭 Network Topologies

**Network topology** refers to the way devices are **physically or logically arranged** within a **Local Area Network (LAN)**. The choice of topology affects how efficiently the network functions and how easy it is to manage.

---

### ⭐ 1. **Star Topology**

- **Structure**: All devices are connected to a **central hub or switch**.
- **Communication**: Devices send data to the central device, which forwards it to the intended recipient.
- **Device Used**: Hub (for simple broadcast) or Switch (for selective forwarding).

✅ **Advantages**:
- Easy to manage and troubleshoot.
- Failure of a single node doesn’t affect the rest of the network.

⚠️ **Drawbacks**:
- If the central device fails, the whole network goes down.

---

### 🔗 2. **Bus Topology**

- **Structure**: All devices are connected to a **single communication line** (a backbone cable).
- **Communication**: Every node places its message on the shared bus. All other nodes listen, and only the **intended recipient** picks up the message (based on the address).

✅ **Advantages**:
- Simple and inexpensive setup.

⚠️ **Drawbacks**:
- High chance of **collisions**.
- Harder to troubleshoot.
- Performance drops as more devices are added.

---

### 🌐 3. **Mesh Topology**

- **Structure**: Devices are connected in a **graph-like structure**—each node connects to multiple other nodes.
- **Communication**:
  - Messages propagate via **DFS-like flooding** (to neighbors).
  - Destination is identified using **BFS-like exploration**.
  - Devices **keep track of seen messages** to avoid forwarding duplicates.

✅ **Advantages**:
- Highly **reliable and fault-tolerant** (many alternate paths).
- Scalable for robust systems.

⚠️ **Drawbacks**:
- Complex to set up and maintain.
- More cabling and hardware are needed.

---

### 🔄 Extra Note:

For **peer-to-peer communication** within a LAN, only the **Physical Layer** and **Data Link Layer** are needed. **Higher layers (like Network or Transport)** become essential only when communication **crosses LAN boundaries** or **involves the internet**.
