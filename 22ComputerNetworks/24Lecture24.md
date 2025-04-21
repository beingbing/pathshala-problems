## 🔐 VPNs, Firewalls & ARP/RARP Protocols

### 🌍 What is a VPN?

A **VPN (Virtual Private Network)** allows you to connect securely to another network over the internet — as if your device is **virtually located** somewhere else.

We’ll focus on one common use case: **bypassing firewalls and accessing restricted content**.

---

### 🧭 How VPNs Bypass Firewalls

When a device connects to the internet:

- The **router assigns it an IP address**, usually based on the region it’s in, as per the **IANA** (Internet Assigned Numbers Authority) address allocations.
- This regional IP can be **blocked** by local ISPs or government-controlled firewalls if it tries to access **restricted content** or blacklisted IPs.

Now, here’s how a VPN helps:

1. You **connect to a remote VPN server** in a different country or region.
2. The VPN assigns your device a **private IP** within its network.
3. The **VPN server** (not your device) communicates with the public internet **on your behalf**.

So:
- To outside websites, it appears like **your traffic is coming from the VPN server**, not your actual location.
- The **local firewall** can't block the content because it only sees an allowed VPN IP, not the actual blocked destination.

➡️ In essence, the VPN **acts as a proxy**, masking your identity and location.

---

### ⚠️ The VPN-Government Cat-and-Mouse Game

Governments and ISPs may attempt to block VPNs by:
- **Blacklisting known public IPs** of popular VPN servers.

VPNs counter this by:
- **Rotating their public IPs**
- **Deploying servers in new regions**
- **Using stealth technology** to disguise VPN traffic

This ongoing battle continues as **VPNs evolve to stay undetected**.

---

### 🧠 Key Analogy

> You → VPN → Internet  
> Instead of going directly to a blocked website, you **ask the VPN to go get it for you**, and bring it back through an unblocked path.

---

## 🔁 ARP & RARP: Mapping Between IP and MAC

### 🔧 Why ARP and RARP Exist

Devices on a network have **two types of addresses**:
- **MAC Address** (fixed hardware ID at Data Link Layer)
- **IP Address** (assigned for communication at Network Layer)

To communicate across layers, we need a **way to translate between them**:

| Protocol | Input | Output | Use Case |
|----------|-------|--------|----------|
| **ARP** (Address Resolution Protocol) | IP Address | MAC Address | To send data to a known IP |
| **RARP** (Reverse ARP) | MAC Address | IP Address | To find IP during device boot-up (less common today) |

🔄 ARP is widely used today. RARP is mostly **obsolete**, replaced by **DHCP** for dynamic IP assignment.
