## 🧱 Boyce-Codd Normal Form (BCNF)

Even after applying **3NF**, some anomalies may remain — especially when **overlapping candidate keys** exist. This is where **BCNF** provides a stricter check.

---

### 🧪 Example: Redundancy in 3NF

Consider a `gradeInfo` table:

```
rNo | name | email | grade | courseName | marks
```

**Candidate Keys:**
- (rNo, name)
- (name, email)
- (rNo, email)

This table may satisfy **2NF** and **3NF**, but still have **redundancy**, particularly in attributes like `name` and `email`. That’s because some attributes (like `email`) can still determine others — even if they’re not full candidate keys.

---

### 🔍 BCNF Rule

A table is in **BCNF** if **every functional dependency** follows this rule:

> **Left-hand side of every functional dependency must be a superkey.**

In simple terms:
- **Only candidate keys (or superkeys)** should determine other attributes.
- If **any non-key attribute (or part of a candidate key)** determines something else — that’s a violation.

---

### ✅ What to Do If BCNF Is Violated?

Whenever a **non-superkey** determines something:
- Decompose the table:
  - Move the violating dependency to a new table.
  - Use the **determinant** (the attribute(s) on the left side of the FD) as the **primary key** of the new table.

This eliminates redundancy and enforces the BCNF rule.

---

### ⚠️ A Practical Trade-off: Dependency Preservation

While BCNF ensures a cleaner schema, there’s a **catch**:

> **BCNF decomposition doesn’t always preserve all functional dependencies** from the original table.

And in some practical scenarios:
- **Preserving dependencies is crucial** for enforcing constraints via queries.
- So, we may **intentionally stop at 3NF** if BCNF breaks dependency preservation.

---

### 📝 Summary

| Form        | Fixes                         | Key Rule                                                                 |
|-------------|-------------------------------|--------------------------------------------------------------------------|
| 1NF         | Atomic values                 | No repeating groups or multi-valued attributes                          |
| 2NF         | Partial dependencies          | No non-prime attribute should depend on part of a candidate key         |
| 3NF         | Transitive dependencies       | Every non-prime attribute must depend only on a candidate key           |
| **BCNF**    | Overlapping candidate keys    | **Only superkeys should determine anything**                             |
