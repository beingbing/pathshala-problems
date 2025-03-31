### **Process Termination**  

A process **enters the terminated state** when it completes execution or is forcibly stopped.  

### **Ways a Process Can Terminate**  

1. **Voluntary Exit:**  
   - The process **completes its task** and calls the `exit()` system call to terminate itself.  

2. **Involuntary Termination:**  
   - The OS **kills** the process due to an error (e.g., **segmentation fault**).  
   - The **parent process** explicitly kills its child (e.g., **timeout exceeded (TLE)**).  

---

### **What Happens After Termination?**  
Once a process terminates:  
- The OS **frees its allocated resources** (memory, CPU, etc.).  
- It returns an **exit code** to the parent (e.g., `0` for successful execution).  

However, this process can sometimes lead to **issues**:  

### **Orphan Processes**  
- If a **parent process terminates** before its child, the child becomes an **orphan process**.  
- The **`init` process (PID = 1)** then adopts orphans and either:  
  - **Terminates them**, or  
  - **Allows them to complete** execution.  

### **Zombie Processes**
- A zombie process is a child process that has finished executing but still has an entry in the process table because its parent hasn't acknowledged its completion.
- It doesn't consume system resources (like CPU or memory) after termination.
- If the parent also terminates, **`init` inherits and cleans up** the zombie process.  

---

### **How One Process Kills Another?**  
A process can terminate another process by sending it a **termination signal** (e.g., `SIGTERM`).
