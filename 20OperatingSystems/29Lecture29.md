### **Threads and Memory Model**  

When a thread is introduced into a process, it affects how memory is structured. Understanding the **memory layout of a process** helps clarify how multiple threads share and manage memory.  

---

### **Memory Layout of a Process**  

A process's memory is typically divided into:  

1️⃣ **Code Segment (Text Segment)** 📜  
   - Stores the **executable code** of the program.  
   - **Shared among all threads** (since all threads execute the same code).  

2️⃣ **Global Data Segment** 📊  
   - Stores **global and static variables**.  
   - **Shared among all threads** (modifications by one thread affect all).  

3️⃣ **Heap Space** 🏗  
   - Used for **dynamic memory allocation (malloc, new, etc.)**.  
   - **Shared among all threads** (threads can allocate/free memory here).  

4️⃣ **Stack Space** 🧵  
   - Stores **local variables, function calls, and return addresses**.  
   - **Each thread gets its own stack** (to avoid conflicts).  
   - **Stack grows downward** while **heap grows upward** in memory.  

---

### **Threads and Stack Memory**  

Since **each thread needs its own execution context**, it has:  

✅ A **separate stack** (for local variables and function calls).  
✅ A **Stack Pointer (SP) and Frame Pointer (FP)** (to track execution).  

**Example:** If a process has three threads, memory will look like:  

```
----------------------------------
|          Code Segment         |  (Shared)
----------------------------------
|        Global Data Segment    |  (Shared)
----------------------------------
|         Heap Space            |  (Shared, dynamic allocation)
|        (Grows upward)         |
----------------------------------
| Stack (Thread 1) | Private |
| Stack (Thread 2) | Private |
| Stack (Thread 3) | Private |
| (Grows downward) |
----------------------------------
```

Since the **Process Control Block (PCB)** only stores information about the main process, we introduce the **Thread Control Block (TCB)** at the thread level.  

---

### **Thread Control Block (TCB)**  

Each thread maintains its own **TCB**, which stores:  

✅ **Thread ID**  
✅ **Stack Pointer (SP) and Frame Pointer (FP)**  
✅ **Register states (for context switching)**  
✅ **Thread-specific metadata (priority, scheduling info, etc.)**  
