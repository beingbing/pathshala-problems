### **Multilevel Feedback Queue (MLFQ) Scheduling**  

We've explored Round Robin (RR) and its ability to balance **fairness** and **efficiency**. However, real-world schedulers must handle **processes of varying nature**—some are **I/O-intensive**, while others are **CPU-intensive**. This brings us to **Multilevel Feedback Queue (MLFQ) Scheduling**, a more **adaptive and realistic** algorithm.  

---

### **Adapting to Process Behavior**  
If we remove our **final assumption** (knowing process runtime in advance), we need a **dynamic** way to estimate how long a process will run. **MLFQ** achieves this by maintaining multiple **priority queues**, adjusting priorities based on process behavior.  

- **Queue Structure:**  
  \[
  Q_1 \quad \rightarrow \quad Q_2 \quad \rightarrow \quad Q_3 \quad \dots
  \]  
  - **Highest priority (Q1)** → Shortest time quantum (~10ms), used for **interactive & I/O-heavy processes**.  
  - **Lower priority queues (Q2, Q3, ...)** → Increasing time quantum, assigned to **CPU-intensive processes**.  

---

### **How MLFQ Works**  
1. **All processes start in the highest priority queue (Q1)** and execute in **Round Robin** fashion with a **small time quantum**.  
2. **Processes that use their entire quantum without yielding (I/O interaction) are downgraded** to the next lower queue.  
3. **Each lower queue has a larger time quantum** to accommodate longer-running CPU-bound processes.  
4. **The lowest-priority queue (Qn) follows FCFS**, allowing long CPU-bound tasks to complete without frequent preemptions.  

---

### **Advantages & Disadvantages**  
✅ **Adapts to process nature dynamically** (I/O vs. CPU-bound).  
✅ **Balances fairness (interactive tasks get priority) and efficiency (long tasks run without frequent interruptions).**  
❌ **Starvation problem**—Processes demoted to lower queues may rarely get CPU time.  
❌ **Processes may change behavior over time** (e.g., an initially CPU-bound process may become I/O-heavy).  
❌ **Cheating the system**—A process could make fake I/O requests to stay in a high-priority queue.  

---

### **Solutions to MLFQ’s Weaknesses**  

1. **Priority Boost**:  
   - Periodically (e.g., every **2 seconds**), **all processes are moved back to the highest priority queue (Q1)**.  
   - Prevents starvation and adapts to processes that change their behavior.  

2. **Quota System**:  
   - Instead of resetting a process’s full time quantum every time it gets CPU, we **track total CPU time used**.  
   - Once a process **exceeds its quota**, it is **downgraded**, preventing abuse by fake I/O interactions.  
