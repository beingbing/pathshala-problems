## 🌐 Public vs Private IP Addresses & Firewalls

### 🔓 Public IP Address
A **public IP address** is **visible on the internet**. It uniquely identifies your device or gateway to the outside world.

- Assigned by your **Internet Service Provider (ISP)**.
- Used for devices or servers that need to be **accessible from outside**, like websites, APIs, or email servers.

---

### 🔒 Private IP Address
A **private IP address** is used **within local networks** like a home, office, or enterprise network.

- **Not visible on the internet**
- Used to identify devices **inside** the local network
- Examples: `192.168.x.x`, `10.x.x.x`, `172.16.x.x to 172.31.x.x`

💡 These ranges are **reserved by IANA** specifically for private use, so they’ll **never conflict** with public IPs.

---

### 🧩 Proxy Pattern & Gateway Devices

In many networks:
- Only **gateway devices** (like routers or proxy servers) are assigned **public IPs**.
- All internal devices get **private IPs** and access the internet **through the gateway**.

This is called the **proxy pattern** — the gateway acts **on behalf of internal devices**, hiding them from the outside world.

🗨️ Think of it like a receptionist (proxy) handling all messages for people in the office — outsiders never directly talk to anyone inside.

---

### 🛡️ Firewalls — Network Security Guards

When public IPs are exposed to the internet, we need a way to **filter** who can send messages to our internal network.

That’s where **firewalls** come in:

- A **firewall** is a system (hardware or software) that monitors incoming and outgoing traffic.
- It can **block or allow traffic** based on rules (like IP address, port, protocol).
- Typically placed on **gateway devices** with public IPs.
- Protects internal devices by **blocking access from untrusted or malicious IPs**.

✅ Firewalls help **shield private IPs** and enforce network security.

---

### 🔐 Bypassing Firewalls — VPNs

A **VPN (Virtual Private Network)** creates a **secure, encrypted tunnel** between your device and a private network over the public internet.

- It **bypasses firewalls** by masking your real IP and routing traffic through a trusted external server.
- Commonly used for:
  - Accessing blocked content
  - Connecting to corporate networks remotely
  - Improving privacy on public Wi-Fi
