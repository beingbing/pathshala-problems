### **Process Lifecycle & States**  

A **process** goes through multiple **states** during its lifecycle, depending on execution and resource availability.  

#### **Process States**  

1. **New State** – The program is ready to become a process but hasn’t started execution yet.  
2. **Ready State** – The OS has admitted the process, allocated necessary resources, and is waiting for CPU scheduling.  
3. **Running State** – The scheduler assigns CPU time to the process, and it begins execution.  
4. **Waiting State** – The process is **paused** while waiting for I/O or an external event.  
5. **Terminated State** – The process has **completed execution** or was forcibly stopped.  

#### **State Transitions**  

- If a **running process is interrupted**, it moves back to the **ready state**.  
- If a **waiting process gets its I/O request fulfilled**, it moves back to the **ready state**.  

---

### **Moving from New to Ready: Memory Allocation**  

Before a process enters the **ready state**, the OS must:  
✅ **Allocate address space** (load code into RAM).  
✅ **Reserve stack and heap memory** for execution.  

Due to limited memory, the OS uses two approaches:  

- **Eager Loading** – Loads the entire process into RAM immediately.  
- **Lazy Loading** – Prepares the setup but loads code into RAM **only when needed**.  

Regardless of the approach, these steps occur **before** a process can transition from **new** to **ready**.  

---

### **Process Queues for Scheduling**  

To efficiently manage processes, the OS maintains **queues** for different states:  

- **Job Queue** – Holds all processes in the **new state**.  
- **Ready Queue** – Stores PCBs of all processes waiting for CPU time.  
- **I/O Queue** – Holds processes waiting for I/O operations.  

These queues help the OS efficiently schedule and manage multiple processes.