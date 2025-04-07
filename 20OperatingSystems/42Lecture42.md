### 🧠 Reader-Writer Problem (Synchronization)

A classic concurrency issue:  
We have a **shared resource** (like a file or database), and multiple **reader** and **writer** threads want access.

---

### ❓Who Needs Synchronization?

| Pair             | Synchronization Needed? | Why |
|------------------|--------------------------|-----|
| Reader vs Reader | ❌ No                    | Multiple readers can read simultaneously without conflict |
| Writer vs Reader | ✅ Yes                   | A writer modifying while a reader is reading can cause inconsistency |
| Writer vs Writer | ✅ Yes                   | Only one writer can write at a time to avoid corruption |

---

### ✅ Reader-Priority Solution

We allow **multiple readers** but only **one writer** at a time.  
To prevent conflicts, we use:
- A **mutex** `mutx` to protect the shared `readerCount`
- A **lock** `w_or_r` to ensure writers get exclusive access

#### 🔁 Logic:

```c
semaphore mutx = 1;        // For readerCount access
semaphore w_or_r = 1;      // Writer or first reader gets this
int readerCount = 0;
```

#### 🧑‍🏫 Reader:

```c
wait(mutx);
readerCount++;
if (readerCount == 1)
    wait(w_or_r);    // First reader blocks writers
signal(mutx);

// Reading...

wait(mutx);
readerCount--;
if (readerCount == 0)
    signal(w_or_r);  // Last reader allows writers
signal(mutx);
```

#### ✍️ Writer:

```c
wait(w_or_r);

// Writing...

signal(w_or_r);
```

---

### ⚠️ Problem: **Writers Can Starve**

If readers keep arriving back-to-back, **writers may never get a turn** — known as **writer starvation**.

---

### 🔁 Writer-Priority Idea

To prevent starvation, we give **priority to writers**.  
If a writer is waiting:
- Block new incoming readers
- Let existing readers finish
- Then allow the writer to proceed

Implementing this requires:
- Tracking waiting writers
- Blocking new readers when writers are queued

This is more complex, but it ensures **fairness**.

You’re encouraged to try implementing the **writer-preferred solution** yourself!
