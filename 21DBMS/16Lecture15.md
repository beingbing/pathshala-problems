## 🧭 Precedence Graph — Testing Conflict Serializability

When multiple transactions are interleaved, we want to check:  
**Can this interleaved schedule be safely transformed into a serial schedule?**

That’s where the **Precedence Graph** comes in.

---

### 🔍 Conflict Refresher

A **conflict** occurs when:
- Two operations from **different transactions**
- Access the **same data item**
- At least one operation is a **write**

In such cases, the **order matters**, and we **cannot swap** these operations while preserving correctness.

---

### 🕸 What Is a Precedence Graph?

A **Precedence Graph** (also called a **serialization graph**) is a **directed graph** used to test whether a schedule is **conflict serializable**.

**How it's built:**
1. **Each transaction = a node**
2. For **every pair of conflicting operations**:
   - If transaction `Ti` performs a conflicting operation **before** `Tj` on the same data item,
   - Add a **directed edge** from `Ti → Tj`

➡️ This edge signifies:  
**Ti must come before Tj in any equivalent serial schedule.**

---

### ✅ When is a Schedule Conflict Serializable?

Once the graph is built:

- **If the Precedence Graph is acyclic (i.e., a DAG):**  
  ✔️ The schedule **is conflict serializable**

- **If the graph has a cycle:**  
  ❌ The schedule **is NOT conflict serializable** — no valid serial order exists

---

### 🧠 Why This Works

Conflicting operations lock in a certain **execution order** between transactions.  
If those orderings form a **cycle**, then there’s no way to line up the transactions **serially** without breaking one of the dependencies.

---

### 🛠️ Finding the Equivalent Serial Schedule

If the graph is acyclic:
- Use **Topological Sort** on the graph nodes
- The result gives you one (or more) valid **serial schedules** equivalent to the original interleaved one

---

### 🧪 Example

Consider:

```
T1: read(A)
T2: write(A)
```

- `read(A)` (T1) and `write(A)` (T2) → conflict
- `read(A)` happens first → Add edge: **T1 → T2**

Repeat this process for all conflicting operations in the schedule to build the full graph.
