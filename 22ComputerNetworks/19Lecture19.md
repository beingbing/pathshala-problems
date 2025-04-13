## 📡 Link State Routing (LSR)

Distance Vector Routing (DVR) had major drawbacks like **slow convergence** and limited network visibility.  
To solve this, we use **Link State Routing**, which gives **each router a complete map of the network**.

---

### 🔄 How Link State Routing Works

1. **Initialization:**
   - Each router, upon startup, identifies its **direct neighbors** (its adjacency list).

2. **Flooding:**
   - It then **floods this information** (Link State Packets) across the entire network.
   - Every router receives link information from every other router—so all routers eventually learn the **entire topology**.

3. **Route Calculation:**
   - Once the full map is available, routers use **Dijkstra’s Algorithm** to compute **shortest paths** to all destinations (Datagram-based routing).

4. **Ongoing Updates:**
   - Whenever there's a change (e.g., link failure or new node), updated link state info is **reflooded**, and routing tables are **recomputed**.

---

### 📉 Limitations of DVR & LSR

- **Scalability issues**:  
  Both Distance Vector and Link State Routing are **ideal for smaller networks** like LANs or organizational intranets.
  
- As the **number of routers grows**, routing tables become **massive** (millions of entries), and **flooding traffic** in LSR can overload the network.

---

## 🌐 Hierarchical Routing — Routing at Internet Scale

To scale routing to the size of the Internet, we adopt a **Hierarchical approach**.

---

### 🏘️ Structure

- The Internet is divided into **smaller logical networks** like **LANs**, **MANs**, and **WANs**.
- Each LAN is connected to the broader Internet using a **gateway router** (also called border router).

---

### 🛣️ How It Works

1. **Within LAN:**
   - Devices use **DVR or LSR** to communicate.
   - If the destination is **not in the same LAN**, the packet is sent to the **gateway router**.

2. **Between LANs:**
   - The gateway router checks **other gateway routers** to find the destination LAN.
   - Once located, it forwards the packet to the **destination LAN’s gateway**.
   - Finally, that gateway delivers the packet to the correct **end node** within its LAN.

> This way, each packet takes **three steps**:  
   `Source → Source Gateway → Destination Gateway → Destination`

---

### 🗂️ Information Stored

| Router Type        | Knows About                                                |
|--------------------|------------------------------------------------------------|
| Internal Router    | Its LAN + its own gateway router                           |
| Gateway Router     | Its LAN + other gateways (not full Internet topology)      |

> Gateways act as **boundary routers**, keeping the system scalable by **localizing** routing knowledge.

---

### 📦 Types of Communication Models

All routing methods discussed so far are focused on **Unicast** (1 sender → 1 receiver).

Next, we’ll explore how routing works for:

- **Broadcast**: 1 → All
- **Multicast**: 1 → Some (group-based)
- **Anycast**: 1 → Nearest (one of many)
