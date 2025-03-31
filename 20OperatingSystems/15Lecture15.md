### **Context Switching**  

When a **running process** is replaced by another **waiting process**, the CPU performs a **context switch**. This involves:  

1. **Saving the state** (Process Control Block - PCB) of the outgoing process.  
2. **Loading the state** (PCB) of the incoming process.  
3. **Transferring CPU control** to the newly scheduled process.  

During this switch, the OS may also **swap processes in and out of RAM** if memory is limited.  

---

### **Types of Context Switching**  

#### **1. Cooperative Switching (Voluntary)**  
- The running process **voluntarily** gives up control by making a **system call** (e.g., I/O request).  
- A **software interrupt** switches the CPU to **Kernel Mode**.  
- The OS runs the **scheduler** to decide which process to execute next.  

**Issue:** If a process enters an **infinite loop**, it never gives up control, leading to a system freeze.  

---

#### **2. Preemptive Switching (Forced by OS)**  
- The OS forces a switch using a **hardware interrupt**.  
- A **timer interrupt** is set, triggering the OS after a fixed time slice.  
- The OS forcibly stops the current process and schedules the next one.  

**Why is Preemption Necessary?**  
- Prevents a single process from monopolizing the CPU.  
- Ensures fair CPU distribution.  
- Allows the OS to **terminate or reschedule misbehaving processes** (e.g., infinite loops).  

---

### **How Context Switching Works**  

1. **Hardware interrupt or system call** triggers a switch.  
2. The **OS takes control** and executes the **scheduler**.  
3. The **current process’s PCB is saved**, and a new process’s PCB is loaded.  
4. The CPU **resumes execution** of the new process.  

**Trade-off:** Context switching ensures **fair CPU usage** but introduces **overhead**, as time is spent saving/loading states instead of actual execution.  

---

### **Conclusion**  
A **purely cooperative approach is unreliable**, as processes can misbehave. Thus, the OS uses a **combination of cooperative (voluntary) and preemptive (forced) switching** to maintain system stability and fairness.
