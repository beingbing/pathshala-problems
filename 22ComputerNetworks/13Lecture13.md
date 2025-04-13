## 🔐 MAC Addresses (Data Link Layer)

In the **OSI model**, every layer uses a different type of address to identify source and destination. The **Data Link Layer (DLL)** uses **MAC addresses** for this purpose.

---

### 📘 What is a MAC Address?

**MAC** stands for **Media Access Control**.  
It’s a **unique identifier** assigned to every device’s **Network Interface Card (NIC)** — the hardware component responsible for network communication at the DLL.

---

### 🔍 Structure of MAC Address

- A MAC address is **48 bits** long (6 bytes), typically written in hexadecimal (e.g., `00:1A:2B:3C:4D:5E`).
- It is divided into two parts:
  - **First 24 bits** → **Organizationally Unique Identifier (OUI)**: Identifies the **manufacturer**.
  - **Last 24 bits** → Uniquely identifies the **specific device**.

✅ This ensures that every NIC has a **globally unique** MAC address.

---

### 💻 MAC and the NIC

- Each **NIC** comes pre-assigned with a MAC address by the manufacturer.
- It is **embedded in hardware**, making it difficult (though not impossible) to change.
- A single computer typically has **one NIC per network interface**, but multiple NICs **can** legally exist (e.g., Ethernet + Wi-Fi on a laptop).

🛑 However, **cloning MAC addresses** (assigning the same MAC to multiple NICs) within the same LAN is **not allowed**, as it creates identity conflicts.

---

### 📡 MAC Address in LANs

In a **Local Area Network (LAN)**:
- Every device **recognizes the MAC addresses** of others in the network.
- MAC addresses help the switch (DLL device) determine **where to forward frames**.
- Unlike IP addresses (used in the **Network Layer**), MAC addresses operate **locally** and don’t change as the device moves between networks.
