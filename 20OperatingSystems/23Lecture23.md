### **Optimizing Page Tables: Hierarchical & Inverted Page Tables**

Paging ensures efficient memory management, but **storing the page table itself** can consume significant space.

For example, in a **32-bit system with 4KB pages**, we need **4MB of memory** just to store the page table—**too large** for practical use.

So, how do we **reduce page table size**?

---

### **1️⃣ Increase Page Size**
Larger pages mean **fewer entries** in the page table.  
🔴 **Drawback:** Leads to **internal fragmentation** (unused memory within allocated pages).

---

### **2️⃣ Avoid Storing Empty Pages**
Instead of creating **page table entries for unused memory**, we **only allocate entries when needed**.  
🔴 **Drawbacks:**
- The **OS doesn't know in advance** which pages will be used.
- **Dynamically adding pages** during execution is slow and inefficient.

---

### **3️⃣ Hierarchical (Multi-Level) Page Tables**
Instead of a **single large page table**, we use **multiple levels**:

- **Page Directory** → Holds **pointers to page tables** (instead of storing every page entry directly).
- **Page Tables** → Stores actual **page-to-frame mappings** for each memory segment.

Example:  
If pages are **grouped into 64** → the **directory entry** stores whether the group is **empty or holds a pointer** to its page table.

✅ **Advantage:** Reduces memory usage.  
🔴 **Drawback:** Adds **extra steps** to page translation. If a **TLB miss** occurs, the additional lookup makes it **even more expensive**.

---

### **4️⃣ Inverted Page Tables**
Instead of storing a **page-to-frame mapping** for each process, we store a **frame-to-page mapping** for all processes.

- **Frame Entry** = `(PID, Page Number)`.
- A process searching for a page must **scan the entire table** to find its frame.

✅ **Advantage:** **Much smaller** table size.  
🔴 **Drawback:** **Slower lookups** since it requires a **linear search** (unless a hash table is used).

---

### **Final Takeaway**
No single method is **perfect**, so modern OS **combine** multiple approaches:  
✔ **Hierarchical page tables** reduce memory usage **while keeping lookups manageable**.  
✔ **Inverted page tables** further optimize space but require **efficient searching techniques** (e.g., hashing).

Thus, **efficient page table design** balances **speed, memory usage, and lookup complexity**. 🚀
