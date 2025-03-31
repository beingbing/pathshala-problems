### **Process Creation**  

A **new process** can only be created by an **existing process**. This forms a **hierarchical process tree**, where every new process is a **child** of an existing **parent process**.  

#### **Process Hierarchy**  
- The **scheduler process (`sched`)** (PID = 0) is the **root** of the process tree. Which is a kernel process that runs when no other process needs to be executed on a CPU core, effectively acting as the system's idle process.
- It spawns the **`init` process** (PID = 1), which then creates system processes and user applications.  

Each new process exists **independently**—there is **no control transfer** from parent to child. However, a parent can **pause execution** using the `wait()` system call until its child process finishes execution.  

---

### **How Does a Process Create a New Process?**  

A new process is spawned in two steps:  

1. **`fork()`** – The parent **duplicates itself**, creating an identical child process.  
2. **`exec()`** – The child process **replaces itself** with a new program, changing its behavior.  
