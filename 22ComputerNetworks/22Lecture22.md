## 🌐 IP Addressing — The Identity of Devices on the Internet

In the **Data Link Layer**, devices use **MAC addresses** to identify each other within a local network.

But for communication **across networks**, we need a different kind of address — the **IP address**, used at the **Network Layer**.

---

### 🧾 What is an IP Address?

An **Internet Protocol (IP) address** is a unique identifier for a device connected to the internet. It allows routers to **locate and route data** from the source to the correct destination.

---

### ✌️ Two Versions of IP Addressing

#### **1. IPv4** — Internet’s First Addressing Scheme  
- Format: `a.b.c.d` (4 numbers separated by dots)  
- Each number = 8 bits → Total = 4 × 8 = **32 bits**
- Range: `0.0.0.0` to `255.255.255.255`
- Max addresses: 2³² = **~4.3 billion**

🧠 **Problem**: Not enough for today’s massive number of internet-connected devices.

---

#### **2. IPv6** — Designed for the Future  
- Total: **128 bits**
- Written as 8 groups of 4 hexadecimal digits (e.g. `2001:0db8:85a3:0000:0000:8a2e:0370:7334`)
- Max addresses: 2¹²⁸ = **an unimaginably large number** (~3.4 × 10³⁸)

🟢 Future-proof and solves IPv4 exhaustion.

---

### 📌 Dual-Stack Support

- Most modern devices and websites support **both IPv4 and IPv6**.
- However, IPv6 adoption is still **in progress**, due to:
  - Higher infrastructure cost
  - Backward compatibility needs
- **IPv4 is still widely used**, thanks to **NAT (Network Address Translation)**.

---

### 🏠 Public vs Private IPs with NAT

- **NAT** allows **multiple devices in a local network** to share **a single public IP**.
- Devices get **private IPs** internally (like `192.168.x.x`) and communicate through a **router**.

✅ This **preserves IPv4 addresses** and extends its life.

---

### ❓ Why IP When We Already Have MAC?

| MAC Address                         | IP Address                           |
|-------------------------------------|---------------------------------------|
| Fixed (burned into hardware)        | Dynamic (assigned when connected)     |
| Works only within local networks    | Works across global internet          |
| Random and manufacturer-specific    | Regionally structured and managed     |
| Too large for fast routing lookup   | Optimized for routing efficiency      |

🧠 IP addresses are **structured** for better **routing**, **regulation**, and **scalability**.

---

### 🌍 IP Address Allocation & Routing

- Managed by **IANA** (Internet Assigned Numbers Authority)
- Certain IP ranges are **region-specific**  
  E.g. IPs starting with `12.x.x.x` might be routed to a region like India.

📦 This structure helps reduce **routing table size** and enforces **location-based routing**.

---

### 🔁 IPs Are Dynamic, Not Fixed

- Devices don’t keep the same IP every time.
- They get a **dynamic IP** via **DHCP (Dynamic Host Configuration Protocol)** from the local router or ISP.
