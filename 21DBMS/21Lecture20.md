## 🧱 Second Normal Form (2NF)

After ensuring a table is in **First Normal Form (1NF)** (i.e., no repeating or non-atomic values), we aim for **Second Normal Form**, which eliminates certain types of partial dependencies.

---

### ✅ What is 2NF?

A table is in **2NF** **if**:
1. It is already in **1NF**, **and**
2. **Every non-prime attribute** is **fully functionally dependent** on the **entire candidate key**, not just part of it.

---

### 📌 Key Definitions

- **Candidate Key**: A minimal set of attributes that can uniquely identify a row.
- **Prime Attribute**: An attribute that is part of **any** candidate key.
- **Non-Prime Attribute**: An attribute **not** part of **any** candidate key.
- **Partial Dependency**: When a **non-prime attribute** depends on **part of a candidate key**.

2NF **removes partial dependencies**.

---

### 🔍 Why Is This Important?

Partial dependencies lead to **data anomalies**:
- **Redundancy**
- **Update anomalies** (multiple updates needed)
- **Insertion anomalies** (can't insert data unless full key is known)
- **Deletion anomalies** (losing more info than intended)

---

### 🧾 Example

Let’s say we have a `user_payment` table:

| UID | Name | Email | PID | PDate | PAmount |
|-----|------|-------|-----|--------|---------|

- **Candidate Keys**:
  - `UID` uniquely identifies the user → `UID → Name, Email`
  - `PID` uniquely identifies a payment → `PID → PDate, PAmount`

This table is **not in 2NF**, because:
- `UID` determines `Name`, `Email` (user info)
- `PID` determines `PDate`, `PAmount` (payment info)

But in this design:
- `UID` and `PID` are being stored together even though they belong to **separate entities**
- `Name` and `Email` are **non-prime attributes** dependent on **part** of the key (UID), not on the whole

➡️ This is a **partial dependency** — violating 2NF

---

### 🔧 How to Fix It? — Decomposition

Break the table into two:

#### `User` Table  
| UID | Name | Email |

#### `Payment` Table  
| PID | UID (FK) | PDate | PAmount |

- Here, `UID` in the Payment table is a **foreign key** referencing the User table
- We eliminate partial dependencies
- Each table now cleanly represents **one entity**: user or payment

---

### ✅ Result

- **Each non-prime attribute now depends on the whole candidate key**
- **Redundancy is reduced**
- **Anomalies are eliminated**
- The schema is now in **2NF**
