### **Modes of Process Execution**  

An operating system (OS) must **restrict direct access to critical system resources** to ensure security and stability. To achieve this, the OS defines two **execution modes**:  

1. **Kernel Mode**: The CPU has **full access** to all system resources. Privileged instructions can be executed.  
2. **User Mode**: Restricted access. The process **cannot directly** interact with critical system components (e.g., memory, hardware, or I/O devices).  

---

### **Accessing Restricted Resources**  

A **user-mode process** cannot directly access privileged resources. If it tries, the OS **triggers an exception** and may **terminate the process**.  

However, if a user-mode process **legitimately needs** access (e.g., reading a file), it must request the OS using a **system call**:  

1. **Process makes a system call** (e.g., read, write, open).  
2. **A special instruction (software interrupt) triggers a mode switch** from **User Mode → Kernel Mode**.  
3. **The OS executes the requested service in Kernel Mode**.  
4. **The process returns to User Mode** after execution.  

---

### **Interrupts and Traps**  

Interrupts help the OS **respond to events efficiently**. They can be:  

#### **Software Interrupts (System Calls & Exceptions)**  
- **System Calls**: Explicitly requested by a user process to access system resources.  
- **Traps/Exceptions/Faults**: Occur when a process encounters **an illegal operation** (e.g., division by zero, invalid memory access).  
- The OS maintains a **Trap Table**, mapping **trap IDs** to their handling code.  

---

### **Hardware Interrupts**  

Hardware devices (e.g., keyboard, mouse, disk) must notify the CPU when they need attention. Two approaches exist:  

1. **Polling**: The CPU continuously checks devices for updates. This wastes CPU time.  
2. **Hardware Interrupts**: Devices send an interrupt signal to the CPU when needed.  
   - **Urgent Interrupts**: Must be handled **immediately** (e.g., power failure).  
   - **Non-Urgent Interrupts**: Can be handled **later** when the CPU is free.  

---

### **Process Stacks in Different Modes**  

Each process maintains two separate stacks:  
- **User Stack** (Used in User Mode) → Stores function calls and local variables.  
- **Kernel Stack** (Used in Kernel Mode) → Handles system calls and interrupts.  

This separation ensures **memory isolation**, preventing user processes from corrupting kernel data.  
