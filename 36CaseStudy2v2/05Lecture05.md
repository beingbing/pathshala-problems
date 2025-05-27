# 🧵 **Process vs Thread: Why Use Threads in the Submission Service?**
Before we dive into the **submission service**, let’s understand why we use **threads** instead of **processes** to handle code execution.

## 🖥️ **What Happens When a Computer Runs Code?**
A computer is a mix of hardware (CPU, RAM, etc.) controlled by an **operating system (OS)**. When you run a program (like Chrome), the OS:

- Loads the program’s binary into memory (RAM).
- Sets up a **Process Control Block (PCB)**, which holds:
  * Executable code
  * Required data
  * Heap (shared memory)
  * Stack (execution context)
- The OS allocates a **CPU core** to run the process. This **process** is a fully independent unit.

💡 **If we started a new process for every API request**, each would be completely isolated, needing its own memory space and core.

## 🧶 **What Are Threads?**
A **thread** is a lightweight unit of execution **within a process**.
* Threads in the same process **share the binary code, heap, and data**.
* Each thread has its own **stack** (to track its progress).
* A CPU core can handle many threads via **context switching** (rapidly switching between threads).

🔎 Key points:
* Threads are faster to create and switch between than processes.
* Threads share memory, which allows them to work on shared data but also introduces **race conditions** if not handled properly.

## 🆚 **Process vs Thread – Choosing the Right One**
When deciding between using a **new process** or a **thread**:

| Aspect                 | Process                               | Thread                           |
| ---------------------- | ------------------------------------- | -------------------------------- |
| **Memory & Resources** | Has separate memory (isolated)        | Shares memory (except stack)     |
| **Performance**        | Slower context switching              | Faster context switching         |
| **Data Access**        | Cannot access other processes’ data   | Can share data in same process   |
| **Use Case Example**   | Each Chrome tab is a separate process | Multiple threads in a single app |

In our system:
* We want to **reuse the existing process’s memory** for code execution (as the submission service runs within the backend server).
* Threads allow us to **quickly spawn execution units**, avoiding the overhead of creating a new process for each request.
* However, we must handle potential **race conditions** and synchronization issues due to shared memory.

## 🚀 **Conclusion**

For the **submission service**, spawning a **new thread** per submission lets us:
- Reuse existing resources (memory, heap).
- Respond faster (quick thread switching).
- Efficiently manage concurrent code execution.

If we used processes, we’d have more isolation but also more overhead and slower execution.
