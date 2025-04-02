### **LRU Page Replacement & Its Approximation**  

When a page needs to be replaced in memory, an efficient **page replacement policy** is required. One such strategy is **Least Recently Used (LRU)**, based on the **Principle of Locality**.  

---

### **LRU (Least Recently Used) Policy**  
💡 **Concept**: The OS removes the **least recently used page**, assuming that **recently used pages** are more likely to be accessed again soon.  

**Why is LRU effective?**  
- Real-world programs tend to **revisit** recently used pages frequently.  
- Though cases exist where **FIFO (First In First Out) performs better**, they are **rare** in typical workloads.  
- **Experimental evidence** confirms that the **Principle of Locality** holds in most scenarios, making LRU a strong choice.  

---

### **Drawback of LRU**  
🚨 **High overhead**: LRU requires **tracking usage history** for all pages, which demands **extra data structures, time, and memory**.  
🚫 **Not practical for large page tables**: Works well for **cache management** (small memory), but is **too costly for full RAM management**.  

---

### **LRU Approximation (Clock Algorithm)**  
To **reduce LRU overhead**, an **approximate** version is used:  

1️⃣ **Reference Bit Mechanism**  
- Each page has a **reference bit** in the **page table**, initially **set to 0**.  
- When a page is **accessed**, its reference bit is **set to 1**.  
- When replacement is needed, the OS **scans for a page with a reference bit of 0** (indicating it has not been used recently).  

2️⃣ **Enhancements**  
- Instead of just a **binary reference bit**, we can store **access frequency** to make a **better replacement decision**.  

---

### **Key Takeaways**  
✔ **LRU is effective but costly** due to tracking usage history.  
✔ **LRU Approximation (Clock Algorithm)** uses a **reference bit** to reduce overhead.  
✔ **Hybrid approaches** combine **LRU-Approximation + FIFO** for **better performance** in practical systems.  

🚀 **Next up: Hybrid Page Replacement Policies!**
