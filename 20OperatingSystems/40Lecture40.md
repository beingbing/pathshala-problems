## 🔒 Monitors – A Better Way to Handle Synchronization

### 🧩 Recap: The Semaphore Problem

We’ve seen how **semaphores** can help solve synchronization problems by controlling access to critical sections (CS). But semaphores come with their own set of challenges:

---

### ⚠️ When Semaphores Become a Problem

1. **Overuse of Shared Semaphores**

   - Sometimes, the **same semaphore** is used to guard **multiple unrelated critical sections**.
   - As a result, if one thread enters any of those CS, **others are unnecessarily blocked**, even if they could have run safely in parallel.
   - 🐢 This leads to **performance bottlenecks** and bugs caused by poor concurrency design.

2. **Lack of Clear Association Between Semaphores and CS**

   - Semaphore usage is **manual** and depends on **correct coding practice**.
   - A developer might correctly synchronize `deposit()`, but **forget to protect `withdraw()`**, which accesses the same shared data.
   - 💥 This inconsistency can break mutual exclusion and lead to **race conditions**.

---

### 💡 Why Developers Prefer Monitors

To avoid such issues, developers often use **monitors**, which provide a **higher-level, structured way** to handle synchronization.

---

## ✅ What Is a Monitor?

A **monitor** is like a class that combines:

1. **Shared Data** – that needs synchronization  
2. **Functions** – that operate on the shared data  
3. **Built-in Synchronization Logic** – to manage thread access  

```java
monitor Account {
    double balance;

    void deposit(double amount) {
        // code
    }

    void withdraw(double amount) {
        // code
    }
}
```

### 🔐 How It Works

- Only **one thread** can execute **any function** of a monitor at a time.
- If a thread is inside `deposit()`, no other thread can enter `withdraw()` or any other method until the first thread exits.
- 🧘 This **automatically enforces mutual exclusion** across all relevant operations on the shared data.
