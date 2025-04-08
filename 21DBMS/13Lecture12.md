## 🔄 What is a Transaction?

A **transaction** is a logical unit of work in a database. It typically involves a sequence of operations (like `INSERT`, `UPDATE`, or `DELETE`) that should be treated as a **single, atomic operation**. ACID ensures database operations remain **reliable**, **predictable**, and **safe**—even in the face of failures or concurrent use.

**Key idea:**  
> Either **all** operations in the transaction succeed together, or **none** should take effect.

---

## 🔒 Why Do We Need Transactions?

To ensure:
- **Data integrity** even during system crashes (e.g. power failure).
- **Correctness** in concurrent environments (when multiple users are accessing the database simultaneously).

---

## ✅ ACID Properties

To guarantee safe and reliable transactions, databases follow **ACID** properties:

### 1. **Atomicity** – *All or Nothing*

- A transaction must be **atomic**—either all changes are made, or none are.
- If a failure occurs mid-way, the database uses **rollback** to undo any partial changes.

### 2. **Consistency** – *From Valid to Valid*

- Transactions must **maintain database integrity**.
- Data should move from **one consistent state to another**.
- Includes:
  - **Explicit consistency**: via constraints (e.g. primary key, foreign key, NOT NULL).
  - **Implicit consistency**: via business logic (e.g. money debited from one account must be credited to another).

> If consistency rules are not satisfied, the transaction is **rolled back**.

### 3. **Isolation** – *No Interference*

- Concurrent transactions should not **interfere** with each other.
- Each transaction must behave as if it is the **only one running**.
- Ensures **intermediate states are invisible** to other transactions.

> Most complex to implement due to the challenges of concurrency.

### 4. **Durability** – *Changes Persist*

- Once a transaction is **committed**, its changes must **survive system crashes**.
- Even power failures or system reboots should not lose committed data.
- Usually achieved via **logging and disk writes**.

---

## ⚙️ Transaction Lifecycle

A transaction goes through several states:

```
         +-------------------+
         |    ACTIVE         | ← transaction starts
         +-------------------+
                   |
                   v
         +-------------------+
         | PARTIALLY COMMITTED | ← final statement executed
         +-------------------+
          /            \
         /              \
  failure           integrity checks pass
       \              /
        v            v
+---------------+   +----------------+
|    FAILED     |   |    COMMITTED   |
+---------------+   +----------------+
        |
        v
  +-------------+
  |   ABORTED   | ← after rollback
  +-------------+
```

---

## 💡 Ensuring Isolation: Scheduling

To maintain isolation:
- **Serial schedules** (run one transaction at a time) are safest, but slow.
- More efficient approaches (like **concurrent schedules**) rely on mechanisms like **locking, timestamps, or multiversion concurrency control (MVCC)** to maintain correctness.
