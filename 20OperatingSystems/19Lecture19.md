### **Segmentation: A Solution to Fixed Memory Allocation Issues**  

In **address translation**, we identified two key problems:  
1. **Wasted memory** between heap and stack due to fixed allocation.  
2. **Limited flexibility** when a process needs more space than available in RAM.  

**Segmentation** addresses these issues by **dividing a process’s memory into logical segments**—each with its own **Base Register (BR) and Limit Register (LR)**.  

---

### **How Segmentation Works**  
Instead of allocating a **single contiguous block**, memory is divided into **segments**, such as:  

| Segment       | Size  | Stored Separately? |
|--------------|------|------------------|
| Code         | 1KB  | Yes |
| Global Data  | 1KB  | Yes |
| Heap         | 3KB  | Yes (Grows Up) |
| Stack        | 1KB  | Yes (Grows Down) |

Each segment **can be placed anywhere in RAM**, reducing **wasted space**. The OS **allocates heap/stack space dynamically** instead of reserving unused space in advance.  

---

### **Handling Expanding Segments (Heap & Stack Growth)**  
1. **Check Nearby Free Space:**  
   - If available, extend the segment in place.  
   - Update the segment’s **Base and Limit Registers**.  
2. **Relocate if Needed:**  
   - If no space is available, move the segment to a **larger free area** in RAM.  

---

### **Memory Allocation Strategies**  
Since memory segments **vary in size**, allocation uses different **search algorithms** to find free space:  

1. **First Fit:**  
   - Find the **first available** free block that fits the segment.  
2. **Best Fit:**  
   - Find the **smallest free block** that can accommodate the segment (minimizing wasted space).  
3. **Worst Fit:**  
   - Choose the **largest free block**, hoping to leave large usable gaps.  

---

### **Fragmentation: The Leftover Memory Problem**  
Even with segmentation, **free memory may become scattered**, leading to **fragmentation**:  

1. **External Fragmentation:**  
   - **Total free memory** is sufficient, but it’s **scattered** in small unusable chunks.  
   - Example: You need **3MB**, but the largest **continuous** free block is **2MB**, even though **8MB** is available in total.  

2. **Internal Fragmentation:**  
   - A segment is allocated more space than needed, leaving unused memory inside it.  

---

### **Key Takeaways**  
- **Segmentation divides memory into logical parts** that can be placed **separately in RAM**.  
- **Dynamic allocation of heap and stack** prevents unnecessary memory reservation.  
- **Fragmentation remains an issue**, requiring **efficient allocation strategies**.  
- Future solutions like **paging** will further optimize memory allocation and reduce fragmentation.
