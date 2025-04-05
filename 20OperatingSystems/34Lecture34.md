### 🧮 **Semaphores: Extending Mutexes for Flexible Synchronization**

After understanding mutexes (which allow *only one* thread to access the critical section), we need a mechanism that allows **multiple** concurrent accesses — that’s where **semaphores** come in.

---

### 🔑 **What is a Semaphore?**

- A **semaphore** is an **integer variable** managed atomically by the OS.
- It supports two atomic operations:
    - **wait()** (also called P or down)
    - **signal()** (also called V or up)

---

### 🚦 **General Usage (for managing multiple entries)**

Semaphores are initialized with a value representing the **maximum number of concurrent accesses** allowed.

```cpp
semaphore s = k;   // allow up to k processes

wait(s) {
    if (s <= 0) {
        put process in waiting queue;
    } else {
        s--;      // atomic decrement
    }
}

signal(s) {
    s++;          // atomic increment
    if (processes are waiting)
        wake one up;
}
```

- If `s > 0`: process enters the **critical section**.
- If `s <= 0`: process is **blocked** and added to the **waiting queue**.

✅ This solves the problem where we want to allow a limited number of processes to access a shared resource concurrently.

---

### 📡 **Use Case 2: Interprocess Communication (IPC)**

Semaphores are also used to enforce **execution ordering** between processes.

**Example:**  
We want `p2` to execute `s2` *only after* `p1` has executed `s1`.

```cpp
semaphore s = 0;

Process p1:
    s1;
    signal(s);    // notify that s1 has finished

Process p2:
    wait(s);      // wait until p1 signals
    s2;
```

- `s = 0` initially → `p2` blocks.
- Once `p1` finishes `s1`, it signals `s`, allowing `p2` to proceed.

🔄 This is a **clean alternative** to message-passing for IPC coordination.

---

### ⚠️ **Problems with Semaphore-Based Synchronization**

#### 1. **Deadlock**

Occurs when two or more processes wait *forever* for each other to release resources.

**Example:**

```cpp
Process p1:             Process p2:
wait(r1);               wait(r2);
wait(r2);               wait(r1);    // now both are blocked
```

- `p1` holds `r1` and waits for `r2`.
- `p2` holds `r2` and waits for `r1`.

🛑 **Neither can proceed.**

---

#### 2. **Priority Inversion**

Occurs when a **low-priority** process holds a lock needed by a **high-priority** process, but is preempted by **medium-priority** processes.

**Example:**

- `L` (Low) enters critical section.
- `H` (High) is blocked waiting for the same resource.
- Meanwhile, `M` (Medium) keeps running, delaying both.

🧨 This delays `H` even though it has the highest priority.

---

### 🛠️ **Solution: Priority Inheritance**

To fix priority inversion:

> If a high-priority process is waiting on a resource held by a low-priority process, **boost the priority** of the low-priority process temporarily.

- Now `L` runs with higher priority.
- Releases lock sooner → `H` gets in faster.
