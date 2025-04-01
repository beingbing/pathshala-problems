### **Paging: A Smarter Way to Manage Memory**  

**Problem with Segmentation?**  
- **Unused gaps** between segments waste memory.  
- Finding **continuous free space** for large segments is difficult.  

**Solution: Paging**  
Instead of variable-sized segments, we **divide process memory into fixed-size blocks**:  
- **Pages** → Fixed-size chunks of **process memory**.  
- **Frames** → Fixed-size chunks of **RAM** (same size as pages).  
- **1:1 Mapping** → Each **page is mapped to a free frame** in RAM.  

Since **frames can be anywhere**, this solves the **external fragmentation** problem.  

---

### **Ensuring Security & Mapping Memory**  

Each process gets a **Page Table**, which maintains:  
- **Page Number → Frame Number mapping**  
- **Offset** → Position within the frame  

#### **How Logical Addresses Are Converted to Physical Addresses**  

| **Logical Address** | **Physical Address** |
|---------------------|---------------------|
| Page Number + Offset | (Frame Number × Page Size) + Offset |

🔹 Example: If Page Size = **4KB**, and Page 3 is mapped to Frame 5 →  
- **Logical Address:** Page **3**, Offset **200**  
- **Physical Address:** (5 × 4KB) + **200** = **20KB + 200 bytes**  

---

### **Choosing the Right Page Size**  
**Trade-offs:**  
- **Large pages** → Less overhead but **more internal fragmentation**.  
- **Small pages** → Less waste but **large page tables** take up RAM.  
- **OS optimizes page size** to balance efficiency.  

---

### **Speeding Up Address Translation**  
Since every **memory access** now requires looking up the **page table**, we introduce:  

🔹 **Page Table Base Register (PTBR)** → Stores the **location of the page table in RAM**.  

🔹 **Translation Lookaside Buffer (TLB)** → A **cache** inside the CPU that stores **recently used page mappings** for faster lookups.  
- **If TLB hit** → Fast translation  
- **If TLB miss** → Look up in page table (slower)  
