### **Translation Lookaside Buffer (TLB): Speeding Up Memory Access**  

Paging introduces an extra step in memory access:  
1. **Look up the page table** to find the frame number.  
2. **Access the frame in RAM**.  

Since **RAM access is slow**, we use a **TLB (Translation Lookaside Buffer)**—a **high-speed cache** that stores recently used **page-to-frame mappings** to reduce lookup time.  

---

### **TLB Working Mechanism**  

🔹 **TLB Hit** → If the required page is in the TLB, we fetch the frame number directly and access RAM. ✅ Fast!  

🔹 **TLB Miss** → If the page is **not in the TLB**, we:  
   1. Look up the **page table** in RAM.  
   2. Store the new **page-frame mapping** in the TLB.  
   3. Access the frame in RAM.  

---

### **Handling a Full TLB: Cache Replacement Policy**  
When the TLB is full, we **remove an old entry** to make space for a new one.  

**Common Replacement Strategies:**  
1. **LRU (Least Recently Used)** → Removes the **least recently accessed entry**.  
   - 🛑 **Issue:** Hackers can exploit this by forcing frequent cache misses using **n+1 access patterns**, where `n` is the TLB size.  
2. **Random Replacement** → Randomly replaces an entry, making it resistant to manipulation.  

---

### **TLB Performance Benefits**  

✅ **Spatial Locality** → If a page is in the TLB, accessing nearby addresses (e.g., array elements) is **faster**.  
- **Example:** If `a[0]` is in the TLB, then `a[1]`, `a[2]`, etc., are likely to be **quickly accessible**.  
- **2D Arrays:**  
  - **Row-major order (left-to-right first)** is faster than **column-major order** because adjacent memory locations have a higher chance of being on the same page.  

✅ **Temporal Locality** → **Recently accessed pages** are likely to be accessed again soon, improving **TLB hit rate**.  

---

### **Challenges with TLB**  

❌ **Context Switching** → When switching between processes, a wrong page-frame mapping could be used.  
- **Example:** If Process P1 maps **Page 3 → Frame 105** and then Process P2 also accesses **Page 3**, it might get the wrong frame.  

🔹 **Solutions:**  
1. **Flush the TLB** on context switch (but this is inefficient).  
2. **Use a Validity Flag** → Marks whether an entry is valid for the current process.  
3. **Use Address Space Identifiers (ASIDs)** → Stores a **process-specific ID** in TLB entries to distinguish between different processes.  

---

### **Extra Information Stored in the Page Table**  

🛡 **Permissions** → Defines read/write access for each page.  
   - **Code pages** → Read-only.  
   - **Stack pages** → Read-Write.  

📂 **Shared Pages** → Some processes share **common code libraries**, so these **read-only pages** can be mapped to multiple processes.  
