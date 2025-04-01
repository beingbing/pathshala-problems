### **Swap Space & Page Fault Handling**  

When a process requires **more memory than available RAM**, the OS uses **swap space**—a reserved section on the **hard disk (HDD or SSD)**—to store pages that are **not currently needed in RAM**.  

---

### **How Does Swap Space Work?**  
1️⃣ **Pages in RAM vs. Pages in Swap Space**  
   - Each process has a **large number of pages**, but **only a few fit in RAM**.  
   - The remaining pages are stored in **swap space** until needed.  

2️⃣ **Page Presence Check**  
   - The **OS maintains a flag** to track whether a page is in **RAM or swap space**.  
   - If a process **requests a page that is not in RAM**, it triggers a **page fault**.  

---

### **What Happens During a Page Fault?**  
A **page fault** occurs when a required page is in swap space **instead of RAM**. The OS then:  
✔ **Locates the page** in swap space.  
✔ **Loads it into RAM**.  
✔ **Updates the page table** with the new frame ID and sets the flag to "in RAM".  

⏳ **Page fault handling takes time** because accessing disk storage is **much slower** than accessing RAM.  

---

### **What If RAM Is Full?**  
If no free space is available in RAM, the OS applies a **page replacement policy** to remove an existing page and make room for the new one.  

---

### **Page Fault Service Time & Acceptable Probability**  
Since handling a page fault requires **disk access**, the OS **minimizes page faults** to keep the system responsive.  

The **average page fault time (t)** is:  
\[
t = (p \times t_f) + ((1 - p) \times t_n)
\]  
where:  
- \( p \) = probability of a page fault  
- \( t_f \) = time taken to handle a page fault  
- \( t_n \) = normal execution time without a fault  

For efficient performance, **page faults should be extremely rare**, ideally occurring **once every 400,000 memory accesses** or less.  
