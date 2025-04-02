### **Second Chance Algorithm & Dirty Bit**  

When a page needs to be replaced, the **Second Chance Algorithm** provides an improvement over **FIFO** by allowing frequently used pages to stay in memory longer.  

---

### **Second Chance Algorithm**  
💡 **Concept**:  
- Maintains a **queue (or linked list)** of all pages currently in memory.  
- Each page has a **reference bit**, initially set to **0**.  
- If a page is accessed, its **reference bit is set to 1**.  

🔄 **Page Replacement Process**:  
1️⃣ The OS starts from the **front of the queue** and checks the reference bit.  
2️⃣ **If reference bit = 0** → Replace the page.  
3️⃣ **If reference bit = 1** →  
   - Set it to **0** (giving it a second chance).  
   - Move to the next page in the queue.  
4️⃣ If the pointer reaches the end, it **wraps around** and starts again.  
5️⃣ Pages that received a second chance will be reconsidered in the next cycle.  

🚀 **Extension**:  
- Using **two bits** instead of one allows for **multiple chances** (e.g., up to 4 iterations).  

---

### **Dirty Bit & Its Role in Page Replacement**  
When replacing a page, it may need to be **saved back to disk (swap space)**.  
To **optimize disk writes**, we use a **Dirty Bit**.  

💡 **Concept**:  
- **Dirty Bit = 1** → Page **has been modified** in RAM and must be written back to disk before removal.  
- **Dirty Bit = 0** → Page **is unchanged**, so we can remove it without updating disk storage.  

📊 **Decision Table for Replacement**:  

| Reference Bit | Dirty Bit | Replacement Priority |
|--------------|----------|----------------------|
| 0           | 0        | **Highest** (replace immediately) |
| 0           | 1        | Medium (write to disk before replacing) |
| 1           | 0        | Medium (give a second chance) |
| 1           | 1        | **Lowest** (keep in memory) |

🛠 **Optimization**:  
- The OS may **preemptively save dirty pages** to disk during **CPU idle time**, resetting the **dirty bit** to 0.  
- This **reduces delays** when actual page replacement is needed.
