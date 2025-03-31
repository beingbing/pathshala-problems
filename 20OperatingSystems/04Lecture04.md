### **2.b: Memory Virtualization**  

#### **Why Do We Need Memory Virtualization?**  

From our previous discussion on the **fetch-decode-execute cycle**, fetching instructions quickly is crucial for efficient execution.  

- **HDD/SSD storage is too slow** for directly executing code from it.  
- **RAM (Memory) is much faster**, so we load executable code into RAM for quicker access.  
- **But RAM is limited**, and a program might require more memory than what is physically available.  

To solve this, the **OS virtualizes memory**, making each program think it has more memory than what physically exists.  

#### **How Does Memory Virtualization Work?**  

- The OS **moves necessary parts of a program into RAM** when needed.  
- It **swaps out unused parts** to make space for other processes.  
- Each program sees a **virtual memory address**, which **does not correspond to an actual physical RAM location**.  

##### **Example Demonstration**  
If we run two instances of the same program and print memory addresses of variables, they will appear identical. However, in reality, both cannot occupy the same physical address simultaneously. This confirms that these addresses are **virtual addresses assigned by the OS**, not actual RAM locations.  

---

### **3: Concurrency**  

While **parallelism** refers to different programs running at the same time, **concurrency** happens **within a single program**—allowing it to handle multiple tasks simultaneously.  

For example, in a web browser like Chrome:  
- You can **download a file**,  
- **Stream a video**, and  
- **Write code in an online editor**—all within the same application.  

Concurrency is what allows a single software program to efficiently handle multiple tasks at once.  

---

### **4: Security & Access Management**  

An OS also ensures that multiple users can safely share a system. **Access control mechanisms** prevent one user from accessing another’s data, maintaining security and privacy.
