### **Shortest Job First (SJF) Scheduling**  

The **FIFO algorithm** suffers from the **convoy effect**, where a long-running job delays shorter ones. To solve this, we use the **Shortest Job First (SJF) algorithm**.  

### **How Does SJF Work?**  
- The OS selects the process with the **shortest execution time** first.  
- It uses a **priority queue** (sorted by job length) to manage processes.  

However, SJF can still suffer from the **convoy effect**:  
- If a **long job arrives first**, it occupies the CPU while **shorter jobs wait**, increasing turnaround time.  
- To avoid this, we could **delay scheduling** to wait for shorter jobs to arrive, but this wastes CPU time.  

### **Solution: Preemptive SJF (Shortest Remaining Time First - SRTF)**  
- Instead of letting one process run to completion, we allow **preemption**.  
- If a **new job with a shorter runtime arrives**, it **interrupts the current process** and takes over the CPU.  
- This ensures shorter jobs **don’t get stuck behind longer ones**, improving overall efficiency.  
