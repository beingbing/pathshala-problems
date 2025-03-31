### **Fragmentation: The Challenge of Unused Memory**  

When the OS allocates memory to processes, it often leaves behind **unused gaps** in RAM. This **wasted space** is called **fragmentation**, which comes in two forms:  

1. **External Fragmentation**:  
   - Total free memory is **enough**, but it’s **scattered** in small, **non-contiguous chunks**.  
   - Example: A process needs **8MB**, but only **smaller scattered blocks** exist, making allocation impossible.  

2. **Internal Fragmentation**:  
   - A process **overestimates** its memory requirement, leading to **unused space** inside allocated memory.  
   - This is usually **less significant**, so it’s **not a major concern**.  

---

### **How to Reduce External Fragmentation?**  

#### **1. Compaction**  
- **Periodically rearrange** all processes to **merge free space** into a large **contiguous block**.  
- **Drawback**: **Time-consuming** and difficult to decide **when** to perform compaction.  

#### **2. Fixed-Sized Memory Blocks (Based on History)**  
- **Analyze past process memory needs** and divide RAM into **fixed-size blocks** accordingly.  
- Example:  
  - If **2MB requests** are common, **reserve** a section of RAM in **2MB chunks**.  
  - If **1MB requests** are frequent, allocate another section in **1MB chunks**.  
- **Drawback**:  
  - **Limits flexibility**—a process with an **unusual request** might **fail** even if RAM has enough total space.  
  - **Deciding the right block sizes** is **not straightforward**.  

#### **3. Buddy System Allocation**  
- Forces processes to request memory in **fixed sizes of power of 2 (2ⁿ MB)**.  
- **How it works**:  
  - The OS **divides RAM recursively** into **smaller power-of-2 chunks** until a **suitable block size** is found.  
  - When a process finishes, its block **merges with its adjacent (buddy) block** if it's free, forming a **larger free chunk**.  
- **Example (256MB RAM, p1 needs 8MB, p2 needs 16MB):**  
  - **Step 1:** Split 256 → 128 + 128 → 64 + 64 → 32 + 32 → 16 + 16 → 8 + 8  
  - **Step 2:** Assign **p2 to a 16MB block** and **p1 to an 8MB block**.  
  - **Step 3:** If p2 exits, check if its **buddy block** is also free → merge to **32MB free block** → repeat merging when possible.  

- **Advantage**: Efficient merging and **reduces fragmentation** by keeping memory allocation **structured**.  
- **Drawback**: Can still lead to **wastage** if a process **needs slightly more than a power-of-2 block**.  
