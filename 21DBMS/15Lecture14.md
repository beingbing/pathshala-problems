## 🔄 Conflict Serializability (CS)

Conflict Serializability ensures that even if multiple transactions are interleaved, the final outcome remains the same as if they were executed one after another — i.e., in **some serial order**.

To check this, we analyze **conflicts** between operations across transactions.

---

### 🧨 When Do Conflicts Occur?

Conflicts only happen when:
- Two **different transactions** access the **same data item**
- **At least one** of the accesses is a **write**

| Operation Pair        | Conflict? | Reason                                  |
|-----------------------|-----------|------------------------------------------|
| `read(A)` & `read(A)` | ❌ No     | Both just reading — no problem           |
| `read(A)` & `write(A)`| ✅ Yes    | One writes, may affect what the other reads |
| `write(A)` & `read(A)`| ✅ Yes    | Same as above, order matters             |
| `write(A)` & `write(A)`| ✅ Yes   | Overwrites may happen in wrong order     |

---

### 🔁 Conflict Equivalence

Two schedules are **conflict equivalent** if:
- They involve the **same operations**
- The **order of conflicting operations** is the same

👉 You can transform one into another using **only non-conflicting swaps** of adjacent operations.

If a schedule `S` is conflict equivalent to some **serial schedule**, we say:

> **S is Conflict Serializable**

---

### 🧪 Conflict Serializability Test

Let’s understand with a simple example:

```
Schedule S:           Schedule S′ (serial):
T1: read(A)           T1: read(A)
T1: write(A)          T1: write(A)
T2: read(A)           T1: read(B)
T2: write(A)          T1: write(B)
T1: read(B)           T2: read(A)
T1: write(B)          T2: write(A)
T2: read(B)           T2: read(B)
T2: write(B)          T2: write(B)
```

- `S` can be transformed into serial schedule `S′` via **non-conflicting adjacent swaps**
- Therefore, `S` is **conflict serializable**

---

### 🧠 Key Idea

If you can reorder a schedule to form a serial schedule by only swapping non-conflicting operations, the schedule is **conflict serializable**.

This guarantees **isolation** — even though operations are interleaved, the result is the same as a clean, serial run.

---

### ❓ So, how to check if a given schedule is conflict serializable?

➡️ **Construct a Precedence Graph (also called Serialization Graph):**
1. Create a **node for each transaction**
2. For each conflict, draw a **directed edge**:
   - From T₁ to T₂ if an operation in T₁ **conflicts** with and **precedes** an operation in T₂

✔️ If the graph has **no cycles** → the schedule is **conflict serializable**  
❌ If there is a **cycle** → the schedule is **not conflict serializable**

