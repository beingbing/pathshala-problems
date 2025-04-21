# Three-Way Handshake

It's a fundamental concept in **TCP (Transmission Control Protocol)** — which is part of the **Internet Protocol Suite (TCP/IP)** used for establishing reliable connections between two devices (like your computer and a web server). Once this handshake succeed, TCP is ensured:
- Connection is reliable.
- Both ends are reachable.
- Each side is ready to start data transfer.

## What is the Three-Way Handshake?

The **Three-Way Handshake** is the process used to **establish a TCP connection** between a **client** and a **server**. It ensures both sides are **ready to transmit data** and **agree on initial sequence numbers**.

## Why Was It Needed?
Without the 3-way handshake, TCP couldn't guarantee:
- **Connection reliability**
- **Correct sequencing**
- **Protection against duplicate/old packets**

It was essential to make TCP **robust and dependable** across any type of network.

The **three-way handshake** was invented to solve critical problems that **simpler connection setups couldn’t handle**—especially in unreliable or asynchronous networks. Here's **what problem it solves** that wasn't solved without it:
- To **synchronize** sequence numbers.
- To ensure **both sides are ready** for data transmission.
- To establish a **reliable, ordered, and error-checked** connection.

## Problem Without Handshake:
If a client just sends a request and the server replies back, it doesn't ensure:
1. **Both sides are ready** for communication.
2. **Old or duplicate connection requests** aren't mistakenly accepted.
3. **Sequence numbers are synchronized**, which are needed for data integrity and ordering.

### 🎯 What Three-Way Handshake Solves:
1. **Ensures both client and server are alive and ready** to communicate.
2. **Prevents "ghost connections"**:
    - Without it, old delayed packets (e.g., SYN from an old connection) could trigger accidental or duplicate connections.
3. **Synchronizes sequence numbers**:
    - Each side sends its own initial sequence number (ISN).
    - This allows **reliable and ordered** data transfer, and prevents data corruption or misordering.

## Why is it called a “Three-Way” Handshake?
Because it involves **three steps** (or packets):
1. **SYN** — Synchronize
2. **SYN-ACK** — Synchronize-Acknowledge
3. **ACK** — Acknowledge

Each of these is a TCP segment (packet) with specific control flags set.

## Step-by-Step Breakdown
### 1. 🟢 **Client → Server: SYN**
- **Purpose**: The client wants to establish a connection.
- **What it does**:
    - Sends a TCP segment with the **SYN** flag set.
    - Picks an **Initial Sequence Number (ISN)** (e.g., 1000).
- **Packet Summary**:
  ```
  SYN = 1, Seq = 1000
  ```

### 2. 🟡 **Server → Client: SYN-ACK**
- **Purpose**: The server acknowledges the client's request and sends its own.
- **What it does**:
    - Sends a segment with **SYN and ACK** flags set.
    - Acknowledges the client’s ISN by setting `ACK = Client ISN + 1` (1001).
    - Picks its own **ISN** (e.g., 3000).
- **Packet Summary**:
  ```
  SYN = 1, ACK = 1, Seq = 3000, Ack = 1001
  ```

### 3. 🟣 **Client → Server: ACK**
- **Purpose**: Final confirmation from the client.
- **What it does**:
    - Sends a segment with just the **ACK** flag set.
    - Acknowledges the server’s ISN by setting `ACK = Server ISN + 1` (3001).
- **Packet Summary**:
  ```
  ACK = 1, Seq = 1001, Ack = 3001
  ```

Now the TCP connection is **established**, and both sides can start exchanging data. Now both sides know:
- What sequence to expect next
- Where to start sending and receiving

## Visual Representation
```
Client                             Server
  | ----------- SYN ------------> |
  |                               |
  | <-------- SYN + ACK -------- |
  |                               |
  | ----------- ACK ------------> |
  |                               |
Connection Established
```

## Sequence Numbers (ISNs)
Used to keep track of the order of packets. Helps in reassembly and ensures reliable delivery. Sequence numbers are exchanged to **synchronize the starting points of data transfer**, enabling **reliable, ordered, and consistent communication**.

## Purpose of Sending Sequence Numbers:
1. **Data Ordering**
    - TCP is a **stream-oriented** protocol — it needs to ensure data arrives in the **correct order**.
    - Sequence numbers track the position of each byte of data.

2. **Reliability**
    - The receiver uses sequence numbers to detect **missing** or **duplicate** packets.
    - Helps in **retransmission** of lost data.

3. **Initial Synchronization**
    - During the handshake, both client and server share their **Initial Sequence Numbers (ISNs)**.
    - This sets the starting point for byte numbering in both directions.

## Why is the sequence only getting increment by 1?
- In the handshake, there is **no actual data**, but the **flag itself consumes one sequence number**.
- So, the next expected sequence number is **ISN + 1**, even though no payload is sent.

This ensures:
- **Correct tracking** of control messages.
- Future data is placed **after** the control segment in the byte stream.
- sequence spacing is consistent and reliable.

## From Where Does Sequence Number Start?
- The **Initial Sequence Number (ISN)** is **randomly generated** by each side (client and server) when a new TCP connection is created.
- It's typically based on a **clock or counter**, not always the same.
- Purpose: to prevent collisions and avoid issues from delayed/dropped packets of old connections.

## Does ISN Always Increment with Each Request?
- Yes, but **only by the number of bytes sent**.
- Each byte of data in TCP consumes one sequence number.
- Control flags like **SYN** and **FIN** also consume **one sequence number**, even if no data is sent.
  **Example:**
- Send "hello" (5 bytes) → sequence number increases by 5.
- Send SYN (0 bytes + flag) → increases by 1.

## **Does ISN Have an Upper Limit?**
- Yes. Sequence numbers are **32-bit unsigned integers**.
- So the range is:
  ```
  0 to 4,294,967,295 (2^32 - 1)
  ```
- After reaching the max, it **wraps around to 0** and continues — TCP handles this gracefully.

### Different TCP Flags
- **SYN**: Initiates a connection.
- **ACK**: Acknowledges received data or connection request.
- **FIN**: Terminates a connection.
- **RST**: Resets a connection.

## What Happens if One Packet is Lost?
TCP has built-in **retransmission timers**. If a packet (say, SYN or SYN-ACK) is lost, it will be **resent** after a timeout.

## Real-World Analogy
Think of it like this:
1. **Client**: "Hey, do you want to talk?" (SYN)
2. **Server**: "Sure, I'm here and ready!" (SYN-ACK)
3. **Client**: "Cool, let’s begin!" (ACK)

### Usage of TCP
TCP and its three-way handshake are **still widely used**, especially in:
- Web (HTTP/HTTPS over TCP)
- Email (SMTP, IMAP, POP3)
- File transfer (FTP)

### Is There Encryption in the TCP Three-Way Handshake?
No. The standard **TCP three-way handshake is not encrypted**.
- It's purely for establishing a connection (synchronizing sequence numbers, etc.).
- Anyone on the network can **see the handshake packets**, including the SYN, SYN-ACK, ACK, and IP/port info.

## So Where Does Encryption Come In?
**Encryption comes into play in protocols built *on top* of TCP**, like **HTTPS (HTTP + TLS)**.
That’s where a **TLS handshake** happens, after the TCP handshake, to establish an encrypted channel.

### 🔐 TLS Handshake (High-level View)
After TCP connection is established:

1. **Client → Server**: Sends "ClientHello" (supported TLS versions, cipher suites, etc.)
2. **Server → Client**: "ServerHello", sends its certificate (with public key)
3. **Client**:
    - Verifies the certificate
    - Generates a **pre-master key**
    - Encrypts it with server’s public key
4. **Server**:
    - Decrypts the pre-master key using its private key
5. **Both sides**:
    - Derive the same **session key** from the pre-master key
    - Use it for **symmetric encryption** of further communication

✅ Now the HTTP data (or any application-level protocol) is securely encrypted. TLS uses **asymmetric encryption** to share a secret, then switches to **symmetric encryption** for speed and security.

---

### 📌 Why Encryption Needed?
- Protects sensitive data (passwords, tokens)
- Prevents eavesdropping and tampering
- Ensures server identity (via certificates)

# How http handshake happen?
Unlike TCP, **HTTP doesn’t have its own handshake** — it relies on the **TCP three-way handshake** for connection setup. But here's how an **HTTP "handshake-like" process** works when a client (like a browser) connects to a server:

---

### 🔁 HTTP over TCP: Step-by-Step

#### 1. **TCP Handshake (Transport Layer)**
- **Client → Server**: SYN
- **Server → Client**: SYN-ACK
- **Client → Server**: ACK  
  ✅ TCP connection established

---

#### 2. **HTTP Request (Application Layer)**
- **Client → Server**: Sends an **HTTP request**
  ```
  GET /index.html HTTP/1.1
  Host: example.com
  ```

---

#### 3. **HTTP Response**
- **Server → Client**: Sends an **HTTP response**
  ```
  HTTP/1.1 200 OK
  Content-Type: text/html
  Content-Length: 1024

  <html>...</html>
  ```

✅ Now the client can render the webpage.

---

### 🔐 HTTPS Handshake (Bonus: Secure HTTP)
If using **HTTPS**, it includes an additional **TLS handshake** before HTTP messages are exchanged:

#### 1. TCP Handshake
#### 2. **TLS Handshake**
- Key exchange, cipher agreement, certificate validation, etc.
#### 3. HTTP Request over Secure Channel

---

### ✅ TL;DR
- HTTP itself doesn’t have a handshake.
- It relies on **TCP handshake**.
- For **HTTPS**, an extra **TLS handshake** is added before any HTTP data is exchanged.