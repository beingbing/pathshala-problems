## 🔗 Functional Dependencies (FDs)

A **Functional Dependency (FD)** describes a relationship between attributes in a table. It's a fundamental concept used in normalization and designing a good database schema.

---

### 🧠 What is a Functional Dependency?

**Notation**:  
```
X → Y
```

Where:
- `X` and `Y` are sets of attributes (i.e., columns)
- This means: **If two rows have the same values for X, they must also have the same values for Y**

➡️ In simpler terms:  
**X determines Y**  
Knowing X is enough to uniquely identify Y.

> Example:  
If `roll_no → name`, then for every student with the same `roll_no`, the `name` must be the same.

---

### ⚠️ One-Way Relationship

Just because `X → Y` holds, it doesn’t mean `Y → X` does.  
FDs are **not necessarily reversible**.

---

### 🔑 Role of FDs in Candidate Keys

Candidate keys are **minimal sets of attributes** that can uniquely identify every row in a table.

So by definition:
> **A candidate key functionally determines all other attributes in the table.**

Formally:
```
Candidate Key → All other attributes
```

This is how **FDs help define keys** and guide normalization.

---

### 📎 Types of Functional Dependencies

1. **Trivial FD**  
   ```
   X → Y, where Y ⊆ X
   ```
   Example:  
   `roll_no, name → roll_no`  
   ✔️ Always holds and doesn’t tell us much new.

2. **Non-Trivial FD**  
   ```
   X → Y, where Y ⊈ X
   ```
   Example:  
   `roll_no → name`  
   ✔️ More meaningful; helps in normalization.
