### **Threading Model: Evolution and Implementation**  

The development of **concurrency** in operating systems evolved from a need to efficiently manage multiple tasks within a process. Initially, OSes only supported **parallelism** at the process level, but software developers introduced threading libraries to achieve concurrency within processes. However, these early implementations had limitations, leading to the creation of **kernel threads**.  

---

### **Early Threading: User-Level Threads**  

Initially, **user threads** were implemented entirely in user space using threading libraries. Here’s how it worked:  

✅ A process (e.g., P1) is scheduled on the CPU.  
✅ Internally, the process has its own scheduler that manages multiple threads (T1, T2, T3).  
✅ When the process gets CPU time, it switches between these threads to simulate concurrency.  

However, this approach had **significant drawbacks**:  

❌ **No true concurrency**: The OS saw the entire process as a single entity, meaning **all threads were paused** if the process was blocked.  
❌ **Blocking problem**: If one thread requested I/O (e.g., waiting for user input), the OS assumed the entire process was idle and swapped it out—even if other threads could still execute.  

Due to these issues, **OS developers introduced kernel-supported concurrency** through **kernel threads** (also called **Lightweight Processes (LWP)**).  

---

### **Kernel Threads: True Concurrency**  

To enable actual concurrency, OSes introduced **kernel threads**, which could be independently scheduled by the OS. This allowed:  

✅ Multiple threads within a process to run in **parallel** on different CPU cores.  
✅ The OS to recognize and schedule **individual threads**, avoiding the blocking problem.  
✅ Better utilization of CPU resources through multi-threading.  

A **kernel thread** is associated with a **user thread**, and different threading models define how these associations work.  

---

### **Threading Models**  

There are **three major threading models** for mapping user threads to kernel threads:  

1️⃣ **Many-to-One Model**  
   - A **single kernel thread** manages multiple user threads.  
   - Only **one user thread** can execute at a time.  
   - If one thread **blocks**, all threads in the process are blocked.  
   - **Inefficient** → No actual parallel execution.  
   - ❌ **FAILED** due to poor concurrency support.  

2️⃣ **One-to-One Model**  
   - Each **user thread** gets a **dedicated kernel thread**.  
   - OS schedules threads **independently** → True concurrency.  
   - But OS **limits the number of kernel threads**, leading to scalability issues.  
   - **Used in modern OSes (e.g., Windows, Linux pthreads)**.  

3️⃣ **Many-to-Many Model (Hybrid Model)**  
   - OS provides a **pool of kernel threads**, shared among user threads.  
   - Threads can be dynamically **mapped to available kernel threads**.  
   - Allows **scalability** and **efficient resource utilization**.  
   - **Used in modern threading libraries (e.g., Linux NPTL, Windows Thread Pools).**
