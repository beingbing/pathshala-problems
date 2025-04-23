## 📶 OSI Model – Layered Approach to Communication

The **OSI (Open Systems Interconnection)** Model is a conceptual framework that standardizes how devices communicate over a network. It follows the **Single Responsibility Principle** — dividing the networking process into **7 clear layers**, where each layer handles a specific part of communication.

This layered design makes networking modular, easier to understand, and easier to troubleshoot.

---

### 🎯 Primary Goal of the Network

The **core purpose** of networking is simple:
- **Establish a connection**
- **Transfer data reliably and efficiently**

To do this well, we divide responsibilities among the OSI layers.

---

## 🧱 OSI Layers (Bottom to Top)

Let’s break it down from the bottom up — each layer only interacts with its **immediate upper and lower layers**, abstracting complexity.

Communication flows **from top to bottom** (sending) and **bottom to top** (receiving).

---

### 🔌 1. Physical Layer
- Deals with **actual hardware connections** (cables, switches, signals).
- Responsible for **transmitting raw bits** over a medium.

---

### 🔄 2. Data Link Layer
- Handles **node-to-node (peer-to-peer)** communication.
- Ensures **error detection**, **frame synchronization**, and **MAC addressing**.

---

### 🌍 3. Network Layer
- Responsible for **routing data** from source to destination across multiple networks.
- Uses **IP addressing** to find the best path.

---

### 📦 4. Transport Layer
- Manages **end-to-end communication** between devices.
- Ensures **reliable delivery**, **segmentation**, and **flow control**.
- Protocols: **TCP**, **UDP**

---

### 🧩 5. Session Layer
- Establishes, manages, and terminates **communication sessions**.
- Keeps track of dialog between two devices (like login sessions).

---

### 🎨 6. Presentation Layer
- Handles **data translation**, **encryption**, and **compression**.
- Converts data into a form understandable by the **application layer** (e.g., encoding formats like JPEG, MP3).

---

### 🌐 7. Application Layer
- Closest to the **user**.
- Provides **interfaces and services** for network applications (like browsers, email clients, etc.).
- Protocols: **HTTP**, **FTP**, **SMTP**, etc.

---

### 📜 Protocols – The Rules of Communication

A **protocol** is a set of rules that two entities agree upon to communicate effectively. Each OSI layer uses specific protocols to perform its duties.

> 🔁 **Mnemonic to remember the OSI layers (Top to Bottom):**  
> **A**ll **P**eople **S**eem **T**o **N**eed **D**ata **P**rocessing
