## 🔄 Nested (Sub)Queries in SQL

When solving complex problems in SQL, it's often helpful to **break them down into smaller queries**—this is where **nested queries** (also called **subqueries**) come in. A subquery is simply a query inside another query.

---

### 🧱 Basic Structure & Execution

Nested queries are executed **bottom-up**:
- The **innermost query runs first**, and its result is used by the outer query.

📌 Example:

**Q:** Find the **name of the person with the maximum problems solved in each cohort.**

```sql
SELECT name
FROM Users
WHERE (problem_solved, cohort) IN (
    SELECT MAX(problem_solved), cohort
    FROM Users
    GROUP BY cohort
);
```

---

## 🔍 Working with Subqueries

### 1. `IN` Clause
Checks if a value (or tuple) **exists in the result of a subquery**.

```sql
SELECT name
FROM Users
WHERE email IN (
    SELECT email
    FROM Subscribers
);
```

---

### 2. Set Comparison Operators: `=`, `>`, `<`, `<=`, `>=`, `<>`

These can be combined with:

- `ANY`: True if **comparison is true for at least one value** in the subquery.
- `ALL`: True if **comparison is true for all values** in the subquery.

📌 Example:

**Q:** Find users from cohort 1 who solved **fewer problems than anyone** in cohort 2.

```sql
SELECT email
FROM Users
WHERE cohort = 1
  AND problem_solved < ANY (
      SELECT DISTINCT problem_solved
      FROM Users
      WHERE cohort = 2
  );
```

> Use `> ALL (...)` to find users who solved **more than all** others in the subquery.

---

## 🔁 Correlated Subqueries

So far, we’ve looked at **uncorrelated** subqueries (inner query runs independently). Now, let’s talk about **correlated** subqueries.

### 🔄 What’s a Correlated Subquery?

A correlated subquery **depends on a value from the outer query**. It’s re-evaluated for **every row** of the outer query.

---

### 3. `EXISTS` / `NOT EXISTS`

These check **whether a subquery returns any rows**.

📌 Example:

**Q:** Select students who have watched **at least one video** on `'trees'`.

```sql
SELECT name, email
FROM Users
WHERE EXISTS (
    SELECT *
    FROM video_tracker
    WHERE topic = 'trees'
      AND video_tracker.email = Users.email
);
```

- `EXISTS` returns true if **any row** is returned from the inner query.
- `NOT EXISTS` returns true if **no row** is returned.

---

### ✅ When to Use What?

| Use Case                          | Use This        |
|----------------------------------|-----------------|
| Check if value exists in result  | `IN`            |
| Compare with one or more values  | `ANY`, `ALL`    |
| Check if rows exist (fast)       | `EXISTS`        |
| Compare groups of values         | Nested with `GROUP BY` |
