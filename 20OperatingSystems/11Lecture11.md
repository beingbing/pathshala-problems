### **Shortest Time to Completion (STC) Scheduling**  

### **Preemptive vs. Non-Preemptive Scheduling**  
Scheduling algorithms fall into two categories:  
- **Non-Preemptive**: Once a process starts, it runs until completion.  
- **Preemptive**: A running process can be interrupted and moved back to the ready queue.  

Preemptive scheduling introduces **context switching**, which allows better CPU utilization, especially when dealing with **I/O-heavy** processes.  

### **Handling I/O Bursts in Scheduling**  
Once we remove the assumption that jobs don’t perform I/O, we must consider both:  
- **CPU Burst**: The time a process actively uses the CPU.  
- **I/O Burst**: The time a process waits for I/O operations.  

In **non-preemptive scheduling**, if a process moves to the waiting state (for I/O), it gets assigned a **new PID** when it returns, treating it as a new job.  
In **preemptive scheduling**, the **same PID is retained**, and the process simply re-enters the ready queue when the I/O completes.  

### **The Need for Shortest Time to Completion (STC)**  
For interactive applications (e.g., real-time systems), I/O bursts are **significant compared to CPU bursts**. If we use **Shortest Job First (SJF)**, these jobs might experience long delays, leading to **poor responsiveness**.  

To address this, we adopt **Shortest Time to Completion (STC)**:  
- Also called **Preemptive SJF** or **Shortest Remaining Time First (SRTF)**.  
- Whenever a **new process arrives**, the scheduler **pauses the current process** and picks the one with the **shortest remaining execution time**.  

### **Starvation Issue in STC**  
A major drawback of STC is **starvation**:  
- If a continuous stream of short jobs arrives, a **long-running process may never get CPU time**.  
- This is especially problematic for **background tasks**, such as file compression or large computations.  

### **How to Solve Starvation?**  
Possible solutions include:  
1. **Aging**: Gradually increasing the priority of waiting processes over time.  
2. **Hybrid Scheduling**: Combining STC with priority-based scheduling to balance fairness and responsiveness.  
3. **Time Slices**: Ensuring long processes get **periodic execution** even if shorter jobs exist.  

STC is an effective algorithm for **interactive systems**, but **fairness mechanisms** are essential to prevent starvation.