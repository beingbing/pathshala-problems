### **Round Robin (RR) Scheduling**  

We've seen how **Shortest Time to Completion First (STCF)** optimizes efficiency by prioritizing shorter processes. However, **long processes suffer from starvation**, making it an unfair approach.  

### **Balancing Fairness and Efficiency**  
Scheduling is a tradeoff between:  
- **Efficiency**: Completing shorter processes early improves **turnaround time** (completion time - arrival time).  
- **Fairness**: Every process should get CPU time **reasonably soon** after arrival. This is measured by **response time**:  
  \[
  \text{Response Time} = \text{First Execution Time} - \text{Arrival Time}
  \]
  
An ideal scheduling algorithm should **balance** both fairness and efficiency.  

### **Round Robin (RR) Scheduling**  
Round Robin ensures fairness by allocating **each process a fixed CPU time**, called the **time quantum (or time slice)**.  
- If a process **finishes within its time quantum**, it **terminates**.  
- If not, the **CPU is taken away** (preempted), and the process moves back to the **ready queue**.  
- The next process in the queue gets CPU time, ensuring that **no process is ignored for too long**.  

**Data Structure**: Implemented using a **circular queue** or **circular linked list**.  

### **Choosing the Right Time Quantum**  
- **Large time quantum** → RR behaves like **First-Come-First-Serve (FCFS)** (bad response time).  
- **Small time quantum** → Too many **context switches**, increasing **CPU overhead**.  

**Optimal Range:** Experimentally, the best **time quantum** is **between 10ms and 100ms**, balancing responsiveness and efficiency.  

### **Performance Comparison**  
- **Good response time** (fairness) as every process gets a chance quickly.  
- **Poor turnaround time** compared to **SJF and STCF** since processes may take multiple rounds to complete.  

### **Modern Scheduling**  
Modern OS schedulers **combine** multiple algorithms (RR, SJF, STCF, and priority-based scheduling) to achieve both fairness and efficiency.  

### **What's Next?**  
We've removed many **assumptions** in our scheduling discussions, but one still remains. Exploring its removal will give us deeper insights into **real-world CPU scheduling** strategies.
