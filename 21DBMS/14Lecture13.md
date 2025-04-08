## 🛡️ Isolation & Transaction Schedules

When multiple transactions run **concurrently** (e.g. in different threads), they may access or modify the same data in a database. To ensure that each transaction behaves as if it ran alone, we enforce the **Isolation** property.

> **To ensure isolation**, a schedule must be equivalent to a serial schedule.

That way, even if transactions are running in parallel for performance, the **consistency and correctness** of the system remain intact.

---

## 🧩 What is a Schedule?

A **schedule** is the actual sequence in which operations from multiple transactions **interleave** during execution.

Example (simplified):
- T1: Read(X), Write(X)
- T2: Read(Y), Write(Y)

Possible **interleaved schedule**:
```
T1: Read(X)
T2: Read(Y)
T2: Write(Y)
T1: Write(X)
```

---

## ✅ What Makes a Schedule Valid?

To preserve **isolation**, a schedule must be **equivalent to some serial schedule** (i.e. one where transactions run one after another, without overlap).

> A **serial schedule** executes all operations of one transaction before starting another.

So, the goal is:
> Even if transactions interleave, the **end result** and **effect** must be the same as if they ran serially.

---

## 🔁 Schedule Equivalence

Two schedules are **equivalent** if they produce the same **final state** of the database and give the same results for all transactions.

There are two main ways to check for equivalence:

### 1. **Conflict Serializability** (Most Common)

- Focuses on **conflicting operations**:
  - Two operations **conflict** if they:
    - Belong to different transactions
    - Access the same data item
    - At least one is a **write**

- A schedule is **conflict serializable** if it can be transformed into a serial schedule by **swapping non-conflicting operations**.

### 2. **View Serializability** (More Permissive)

- Two schedules are **view equivalent** if:
  - They read the **same initial values**
  - Every read operation reads the **same value** it would in the other schedule
  - The final writes to data items are from the **same transactions**

- View serializability allows more flexibility but is **harder to test** in practice.
