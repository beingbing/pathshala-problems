### **Concurrency vs Parallelism**  

Both **concurrency** and **parallelism** involve executing multiple tasks, but they differ in how they handle execution.  

---

### **Parallelism** 🚀  
**Definition:** Running **multiple independent processes** simultaneously on different CPU cores.  

✅ **How it works:**  
- Each process is assigned to a **separate CPU core** (if available).  
- If there are more processes than cores, the **scheduler** distributes CPU time among them.  

✅ **Example:**  
- Running a **web server, video player, and file download** at the same time, each handled by different cores.  

---

### **Concurrency** 🔄  
**Definition:** Running **multiple tasks of the same process** in an **interleaved** manner using **threads**.  

✅ **How it works:**  
- Uses **threads**, which share memory and exist within the same process.  
- The CPU **switches** between threads to give the illusion of simultaneous execution.  

✅ **Example:**  
- A **web browser** loading a webpage **while** allowing user interaction.  

---

### **Processes vs. Threads**  
| Feature       | Process 🖥  | Thread 🧵 |
|--------------|------------|------------|
| **Address Space** | Separate for each process | Shared within the same process |
| **Communication** | Needs **Inter-Process Communication (IPC)** | Direct memory access (faster) |
| **Overhead** | Higher (context switching is expensive) | Lower (less overhead) |
| **Isolation** | Independent (one crash won’t affect others) | Shared memory (bugs can affect all threads) |

---

### **Why Do We Need Concurrency If We Already Have Parallelism?**  

1️⃣ **Computational Speedup** 📈  
   - Some tasks (e.g., **Merge Sort**) can be **split into multiple threads** to run in parallel.  
   - Theoretical speedup from **O(n log n) to O(n)** (but limited by CPU core count).  
   - Excessive threads can **slow performance** due to context switching.  

2️⃣ **Background Processing** ⚙️  
   - Running tasks **asynchronously** without blocking the main process.  
   - Example: A **music app** playing a song while downloading another.  

3️⃣ **User Interaction** 🖱  
   - Humans are **slow** compared to computers.  
   - Example: A **text editor** autosaving while the user types.  
