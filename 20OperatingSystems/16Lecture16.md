### **Interprocess Communication (IPC)**  

Processes often need to communicate and coordinate tasks. IPC allows processes to share data, synchronize execution, and avoid conflicts.  

**Why Do We Need IPC?**  
- **Data Sharing:** Example: **Producer-Consumer Problem**, where one process generates data, and another consumes it.  
- **Synchronization:** Example: Process **Z** can run only after **X** and **Y** complete. **X** and **Y** run in parallel and inform **Z** when they finish.  

---

## **Ways to Achieve IPC**  

### **1. Shared Memory**  
- **Process 1 (P1)** allocates a **shared memory segment**.  
- **P1** grants access to **Process 2 (P2)**.  
- **P2** attaches the shared memory to its address space.  
- Now, both processes **read/write** directly to shared memory.  

✅ **Fast once set up** but 🚨 requires **manual synchronization mechanisms** (e.g., semaphores) to prevent race conditions.  
⚠ **Limited in size**, and improper use can lead to memory corruption.  

---

### **2. Message Passing System**  
Processes communicate by **sending and receiving messages**, without shared memory.  

#### **A. Direct vs Indirect Communication**  

- **Direct Communication:**  
  - Processes know each other explicitly and communicate directly.  
  - Supports **one-way (asymmetric)** or **two-way (symmetric)** links.  

- **Indirect Communication (via Mailboxes)**  
  - **Processes don’t know each other**; they communicate using an **intermediary** (e.g., ports or pipes).  
  - **Ports:** Special memory addresses where messages are sent and received. Example: **Both P1 and P2 bind to port 5001** to exchange data.  
  - **Pipes (Named Pipes):** Special files used as **communication channels**. Example: UNIX **FIFO files** allow IPC between unrelated processes.  

---

### **3. Synchronization in Message Passing**  

Processes can either **block (wait)** or **continue execution** after sending/receiving a message.  

**4 Possible Combinations:**  
1. **Blocking Send – Blocking Receive**: Both sender and receiver wait until the message is delivered.  
2. **Blocking Send – Non-blocking Receive**: Sender waits; receiver continues execution.  
3. **Non-blocking Send – Blocking Receive**: Sender continues execution; receiver waits for a message.  
4. **Non-blocking Send – Non-blocking Receive**: Both sender and receiver proceed without waiting.  

---

### **4. Buffering in Message Passing**  

A buffer temporarily holds messages before they are processed.  

- **Zero Buffer:** No storage space. The sender **must wait** for the receiver to be ready, and vice versa.  
- **Bounded Buffer:** Limited buffer size. If full, the sender must wait. The receiver can be either blocking or non-blocking.  
- **Unbounded Buffer:** No size limit. Both sender and receiver can proceed independently.  

---

### **Conclusion**  
- **Shared Memory** is faster but **complex to manage**.  
- **Message Passing** is simpler but **can be slower** due to copying overhead.  
- Choosing the **right IPC mechanism** depends on the system’s requirements for **speed, complexity, and synchronization**.
