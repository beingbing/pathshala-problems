## 🧱 Good vs Bad Database Design — Why Normalize?

When designing a database, structure matters. Poor design can lead to inefficiency, anomalies, and data corruption. Let’s understand this through an example:

---

### 📉 Example of a Bad Design

**Table: `student_dept`**

| r.no. | name | marks | dept_name | hod     | office_no |
|-------|------|--------|-----------|---------|------------|
| 101   | A    | 90     | CSE       | Dr. Rao | 402        |
| 102   | B    | 85     | CSE       | Dr. Rao | 402        |
| 103   | C    | 88     | ECE       | Dr. Singh| 403        |

🔍 **Issues with this design**:
- **Redundancy**: Repeating department info (HOD, office) for every student
- **Insertion anomaly**: You can’t store a new department until a student joins it
- **Deletion anomaly**: Removing the last student may also remove department data
- **Update anomaly**: Updating HOD info means updating multiple rows
- **Expensive transactions**: Due to repeated updates across rows

---

### ✅ Better Design (Normalized)

**Separate tables**:

**`student`**

| r.no. | name | marks | dept_name |
|-------|------|--------|-----------|
| 101   | A    | 90     | CSE       |
| 102   | B    | 85     | CSE       |

**`department`**

| dept_name | hod      | office_no |
|-----------|----------|------------|
| CSE       | Dr. Rao  | 402        |
| ECE       | Dr. Singh| 403        |

🎯 **Advantages**:
- Reduces **data duplication**
- Prevents anomalies
- Ensures easier and cheaper updates
- Improves consistency and scalability

---

## 🔧 How to Transform a Bad Design into a Good One?

1. **Start by collecting all data** into one large table (even if redundant)
2. **Decompose** this table into smaller, related tables to eliminate redundancy

### Decomposition Types:
- **Lossy Decomposition**: Some information is lost (❌ not acceptable)
- **Lossless Decomposition**: No information is lost (✅ preferred)

---

## 🧩 Enter Normalization

To guide this decomposition, we follow a set of rules called **Normal Forms (NF)**. These help us shape our tables to avoid anomalies and preserve data integrity.

> Think of **normal forms** as **checkpoints** — each one fixes certain types of problems.

---

### 🔹 1NF — First Normal Form

> **Rule**: Every attribute must be **atomic** (i.e., no multi-valued or composite fields)

Example violation:

| r.no. | name | subjects       |
|-------|------|----------------|
| 101   | A    | Math, Physics  |

✅ To fix:
Split values into separate rows or move to a new table with one subject per row.

---

### 🧠 Key Insight

> **Normalization** is not just about splitting tables — it’s about organizing data to remove redundancy, maintain consistency, and support scalable, efficient transactions.

We’ll explore deeper normal forms (2NF, 3NF, BCNF...) next, which give us precise criteria for how and when to decompose a table.
