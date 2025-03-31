### **Introduction to Process Scheduling: FIFO**  

In the **ready state**, processes wait in the **ready queue** until the OS **schedules** one for execution.  

### **How Does the Scheduler Pick a Process?**  
A **scheduling algorithm** determines which process moves from the ready queue to the **running state** based on:  
- **Turnaround Time** = **Completion Time - Arrival Time**  
  - (i.e., total time spent from arrival to completion)  
- The goal is to **minimize average turnaround time** for all processes.  

---

### **First-In, First-Out (FIFO) Scheduling**  
To simplify scheduling, we assume:  
1. **All processes take the same time** to complete.  
2. **Processes run to completion once started** (no preemption).  
3. **We know each process’s execution time beforehand**.  
4. **No process uses I/O**.  

With these assumptions, all processes are identical in behavior, making **FIFO (First-In, First-Out)** an ideal choice.  
- The order of execution **does not** affect the average turnaround time.  

---

### **Why FIFO Fails in Real Scenarios (Convoy Effect)**  
If we remove the assumption that **all processes have the same runtime**, issues arise:  
- If a **long-running process** arrives first, **shorter processes must wait**, even if they could finish quickly.  
- This leads to the **convoy effect**, where small tasks pile up behind a large one, increasing overall waiting time.  

Thus, **FIFO is not efficient** when processes have varying execution times. A smarter approach would prioritize **shorter tasks first**.
