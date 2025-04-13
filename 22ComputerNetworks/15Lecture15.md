## 🌐 Introduction to the Network Layer (Layer 3 of OSI Model)

Up to the **Data Link Layer**, we could only manage communication between directly connected devices — either within a **peer-to-peer connection** or inside a **local area network (LAN)**.

But what if devices are far apart, across different networks?

That’s where the **Network Layer** steps in.

---

### 🧭 Core Responsibility: **Routing**

The Network Layer ensures that **packets travel from the source to the correct destination**, even across multiple, different networks.

---

### 🆔 IP Address: The Identity on the Internet

- Each device on a network is assigned an **IP address** (Internet Protocol address).
- This address is **unique within its network** and helps identify where a packet should go.
- Every data packet contains the **destination IP address** in its header.

---

### 📦 How Packets Travel: The Role of Routers

- **Routers** are specialized devices that read packet headers and **forward them along the best path** toward their destination.
- They use **routing tables** to decide the next optimal hop for each packet.
- These tables are built using **routing algorithms** and updated dynamically.

---

### 🌐 ISPs and the Bigger Internet

- **Internet Service Providers (ISPs)** deploy and manage routers across the internet.
- These routers form the **backbone of internet connectivity**, linking multiple networks together.
