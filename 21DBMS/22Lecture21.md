## 🧱 Third Normal Form (3NF)

After achieving **Second Normal Form (2NF)**, we move to the next step in normalization: eliminating **transitive dependencies**.

---

### 🔗 What Is a Transitive Dependency?

A **transitive dependency** exists when:

If  
```
X → Y   (X determines Y)  
and  
Y → Z   (Y determines Z)  
```

Then indirectly,  
```
X → Z  
```

This indirect relationship is called **transitive** — because `Z` depends on `X` through `Y`.

---

### 🧠 Why Are Transitive Dependencies Bad?

They lead to:
- **Redundancy**: repeated data
- **Update anomalies**: updating one piece of data may require many changes
- **Insertion/deletion anomalies**: difficult to insert or remove data independently

---

### ✅ What Is 3NF?

A relation (table) is in **Third Normal Form (3NF)** if:
1. It is already in **2NF**, and  
2. **No non-prime attribute** is **transitively dependent** on any **candidate key**

In other words:
- **Every non-prime attribute** must depend **only** on a candidate key — **not through** another non-prime attribute.

---

### 🔧 How to Fix It?

If you spot a transitive dependency like:

```
X → Y → Z  
```

Then:
- Create a separate table for `Y → Z`
- Keep `X → Y` in another table

This decomposition **removes the transitive link** and brings the schema into 3NF.

---

### ⏭ What’s Next?

Even after applying **1NF**, **2NF**, and **3NF**, some **edge cases** can still slip through — like certain anomalies related to overlapping candidate keys.

For that, we go deeper into **Boyce-Codd Normal Form (BCNF)** — covered in the next section.
