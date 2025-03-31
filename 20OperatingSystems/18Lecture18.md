### **Address Translation: Mapping Virtual to Physical Memory**  

Every process perceives memory as a **continuous block** assigned exclusively to it, but in reality, the OS maps this virtual memory to physical RAM locations.  

#### **Understanding Process Memory Layout**  

Consider a process **P1** allocated **16KB** of virtual memory:  

| Segment       | Size  | Virtual Address Range |
|--------------|------|----------------------|
| Code         | 1KB  | 0KB – 1KB            |
| Global Data  | 1KB  | 1KB – 2KB            |
| Heap Space   | 3KB  | 2KB – 5KB (grows up)  |
| Stack Space  | 1KB  | 15KB – 16KB (grows down) |

This **0–16KB** allocation is the **virtual address space** of the process. However, it can be mapped to **anywhere in RAM**—for example, **100KB–116KB** in physical memory.  

---

### **Address Translation Mechanism**  

Since processes operate on virtual addresses, a **mapping** is required to find the corresponding **physical address** in RAM.  

**Formula:**  
\[
\text{Physical Address} = \text{Virtual Address} + \text{Base Address}
\]
- **Base Register** stores the **starting physical address** of a process.  
- **Limit Register** ensures the process doesn’t exceed its allocated space.  

These registers are part of the **Memory Management Unit (MMU)** inside the CPU. If a process tries to access memory beyond its limit, the OS triggers a **trap** and raises a **Segmentation Fault**.  

---

### **Issues with Fixed Allocation**  

1. **Wasted Space**  
   - The heap and stack grow dynamically, but the space between them remains **fixed and often underutilized**.  

2. **Process Larger than RAM?**  
   - What if a process **needs more memory than RAM can provide**?  
   - The solution lies in **paging and virtual memory** mechanisms, which allow processes to use **disk storage as an extension of RAM**.  

---

### **Key Takeaways**  
- **Address Translation** maps virtual addresses to physical addresses using **base and limit registers**.  
- The **MMU ensures memory protection** by restricting access beyond allocated space.  
- **Fixed allocation leads to inefficiencies**, necessitating advanced techniques like **paging and virtual memory** to optimize memory usage.
