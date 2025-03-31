### **2.a: CPU Virtualization**
#### **How Does a CPU Run Multiple Programs?**  

At its core, a **CPU can execute only one program per core at a time**. However, modern computers appear to run **many programs simultaneously** due to two key concepts:  

1. **Multiple Cores** – Each core operates independently, allowing multiple programs to run in parallel.  
2. **CPU Virtualization (Context Switching)** – Even with limited cores, an OS enables running **many programs** by rapidly switching between them.  

This switching happens so fast that it feels like multiple programs are running at the same time, even though, at any given moment, a single core is executing only one task.  

Through **virtualization**, the OS **shares CPU time across programs**, making efficient multitasking possible.