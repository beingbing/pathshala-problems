### **Mutex Locks: Ensuring Safe Entry to Critical Section**

Previously, we saw that **Peterson's solution** works only for two threads. To scale concurrency control for any number of threads, we use **mutexes**.

---

### 🧠 **What is a Mutex?**

- **Mutex** stands for **Mutual Exclusion**.
- It is a **special lock variable** provided by the OS.
- Operations on mutexes are **atomic**, meaning updates happen as a single, indivisible step.

---

### 🔁 **How Mutex Works**

Only one thread can hold the mutex at a time — like having a **single key to a room**:

```cpp
acquire() {
    while (!available);   // spinlock: wait until lock is free
    available = false;    // acquire the lock (atomic)
}

release() {
    available = true;     // release the lock
}
```

### 🧩 Real-World View

- **`available = true`** → Lock is free.
- **`available = false`** → Lock is held.

When a thread **acquires** the mutex, others **wait**. Once released, the waiting threads race to grab it.

---

### ✅ **Evaluating Mutex Against Key Synchronization Criteria**

| Property            | Status       | Explanation                                                                 |
|---------------------|--------------|------------------------------------------------------------------------------|
| **Mutual Exclusion**| ✅ Satisfied | Only one thread can enter the critical section at a time.                   |
| **Progress**        | ✅ Satisfied | If no thread is in the CS, one will be allowed to enter.                    |
| **Bounded Waiting** | ❌ Not Guaranteed | A thread may be repeatedly overtaken (starvation possible).               |

---

### ⛔ **Problem: Starvation due to Race**

With the naive spinlock version, threads endlessly loop waiting for the lock, and some may **never get in**. This violates **bounded waiting**.

---

### 📦 **Solution: Add a Queue**

To ensure fairness:
- Maintain a **queue** of waiting threads.
- When a thread tries to acquire a locked mutex, it gets added to the queue and **put to sleep** (no CPU wasted).
- Threads are **woken up in order** when the lock becomes available.

```cpp
acquire() {
    if (!available)
        add process to queue and put it to sleep;
    else
        available = false;
}

release() {
    if (queue is not empty)
        wake up the next process;
    else
        available = true;
}
```

This change ensures:
- ✅ **Bounded waiting** is satisfied.
- 💤 **Spinlock is avoided** — no unnecessary CPU cycles wasted.
- ⏳ Threads **wait efficiently** and fairly.

---

### 🚦 Why Mutex is for Single-Thread Access

Mutexes are designed to **allow only one** thread into the critical section at a time.

But what if you want to allow **up to 5 threads** to enter concurrently? For that, mutex isn’t sufficient.

---

### 🔄 **Enter Semaphores**

When you want to:
- Allow **multiple** threads (up to a limit) into a resource.
- Generalize beyond binary locking...

You need **semaphores**, which are like counters managing **how many threads can proceed** at once.

> Coming up next: **Semaphores** — the flexible cousin of mutexes.
