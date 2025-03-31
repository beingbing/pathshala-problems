### **Introduction to Processes**  

In **CPU virtualization**, the OS creates an illusion that each program has its own CPU. But how does it achieve this?  

#### **What is a Process?**  
A **process** is simply a **program in execution**. The OS manages multiple programs by:  
1. Selecting a program to run.  
2. Converting it into a **process**.  
3. Assigning CPU time to execute it.  

However, since a CPU core can execute only **one process at a time**, the OS switches between processes using two key concepts:  

- **Context Switching** – The OS **saves the state** of the current process and loads another one.  
- **Time Sharing** – The OS **allocates CPU time** to each process, ensuring all get a chance to run.  

Together, these mechanisms create the illusion of smooth multitasking and interactivity.  

#### **Disadvantage of Context Switching**  
- **Overhead** – Each context switch consumes time, as the OS must save and load process states.  
- **Performance Lag** – If too many processes are waiting, excessive switching can slow down execution.  

---

### **Process Control Block (PCB)**  

To manage each process, the OS uses a **Process Control Block (PCB)**—a data structure that stores all necessary details.  

#### **1. Memory Layout** (Process Address Space)  
- **Code Segment** – Compiled machine code of the program.  
- **Data Segment** – Preallocated memory for global/static variables.  
- **Heap** – Dynamic memory allocation (e.g., `malloc`, `new`).  
- **Stack** – Stores function calls, local variables, and return addresses.  

⚠ **Heap and Stack Collision** → If they meet, it leads to a **Memory Limit Exceeded (MLE)** or **Segmentation Fault**.  

#### **2. Registers (Tracking Execution State)**  
- **Program Counter (PC)** – Stores the current instruction being executed. Helps resume execution after a context switch.  
- **Stack Pointer (SP)** – Tracks the top of the stack for function calls.  
- **Frame Pointer (FP)** – Marks the start of the current function’s stack frame, allowing cleanup after function execution.  

#### **3. Metadata (Process Information)**  
- **Process ID (PID)** – Unique identifier for the process.  
- **Priority** – Determines scheduling preference.  
- **Process Status** – Running, waiting, terminated, etc.  
- **I/O Status** – Tracks resource usage.  
- **Parent Process ID** – Identifies the process that spawned it.
