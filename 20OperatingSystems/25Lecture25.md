### **Page Replacement Policies**

When a **page fault** occurs, a new page must be loaded into RAM. However, if **RAM is full**, the OS needs a **page replacement policy** to decide which page to remove to make room for the new one.

---

### **Types of Page Faults**
1️⃣ **Cold (Compulsory) Misses**:
- Happen when a page is accessed for the **first time**.
- **Unavoidable** since the page has never been loaded before.

2️⃣ **Capacity Misses**:
- Occur when a required page **isn’t in RAM**, and **RAM is already full**.
- **These are the misses we aim to minimize** through efficient replacement policies.

---

### **Page Replacement Strategies**

#### 🔹 **1. Optimal Page Replacement**
✔ **Idea**: Remove the page that will be used **furthest in the future**.  
✔ **Best possible strategy** (minimum page faults).  
❌ **Impossible in practice** since we cannot predict future accesses.

---

#### 🔹 **2. FIFO (First-In-First-Out) Page Replacement**
✔ **Idea**: Remove the **oldest** page in RAM (the one loaded first).  
✔ **Easy to implement** (uses a simple pointer to track the oldest page).  
❌ **Not intelligent**—doesn’t consider **how frequently a page is used**.  
❌ **Belady’s Anomaly**: Increasing RAM size **may increase** the number of page faults.

**Example of Belady’s Anomaly:**  
🔹 Suppose **capacity = 3** and pages are requested in this order:  
`1, 2, 3, 4, 1, 2, 5, 1*, 2*, 3, 4, 5*` → **Page misses = 3**  
🔹 Now, **capacity = 4** and the same pages are requested:  
`1, 2, 3, 4, 1*, 2*, 5, 1, 2, 3, 4, 5` → **Page misses = 4** (more than before!).

💡 This shows FIFO **is not always efficient**.

---

#### 🔹 **3. Random Page Replacement**
✔ **Idea**: Remove any **random** page.  
✔ **Surprisingly works better than FIFO on average!**  
❌ **Still inefficient**—no consideration of recent/frequent usage.

---

#### 🔹 **4. Most Frequently Used (MFU) Page Replacement**
✔ **Idea**: Remove the page with the **highest past usage**.  
✔ Assumes **frequently used pages will no longer be needed**.  
❌ **Fails for programs with loops**—frequently accessed pages might still be crucial.

**Example**:
- If an **array is being processed in a loop**, its pages are accessed frequently.
- MFU **may remove these crucial pages**, causing **high page faults**.

---

#### 🔹 **5. Least Frequently Used (LFU) Page Replacement**
✔ **Idea**: Remove the page that **has been used the least**.  
✔ **Considers temporal locality** (pages that haven’t been accessed much are likely unimportant).  
❌ **Issue**: Doesn’t account for **recency**—a page used **a lot in the past** but **not recently** is still treated as “important.”

💡 **Example**:
- Suppose a **math library page** was frequently accessed **earlier**, but now the program has moved on.
- LFU **might still keep** that page, **removing a more recently used but less frequent page instead**.

---

### **What’s Next?**
🚀 **A better approach is needed!**
- **LFU doesn’t consider recency** of accesses.
- The next algorithm, **Least Recently Used (LRU)**, fixes this problem.

👀 **We will study LRU next!**
