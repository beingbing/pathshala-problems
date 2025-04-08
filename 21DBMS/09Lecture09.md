## 📊 Grouping & Aggregation in SQL

When analyzing data, we often need **summarized insights**—like totals, averages, or maximums. SQL provides **aggregation functions** for this, and we group data using the `GROUP BY` clause.

---

### 🔢 Aggregation Functions

Common aggregate functions:
- `SUM()` – Total of values
- `AVG()` – Average
- `MAX()` – Maximum
- `MIN()` – Minimum
- `COUNT()` – Number of rows

---

### 👥 GROUP BY – Forming Groups

`GROUP BY` is used to group rows based on one or more columns. Aggregations are then applied **per group**.

📌 **Example:**

**Tables:**
- `Users(UID, email, name)`
- `Payments(email, PID, pDate, duration)`

👉 Goal: For each email, compute the **total subscription duration**.

```sql
SELECT email, SUM(duration)
FROM Payments
GROUP BY email;
```

**Output:**
```
abc@gmail.com   120
def@gmail.com    37
```

📝 **Only two types of columns allowed in the SELECT when using `GROUP BY`:**
1. Grouping column(s)
2. Columns with aggregate functions

---

### 🧮 GROUPING BY MULTIPLE COLUMNS

You can group by more than one column for finer granularity.

```sql
SELECT email, SUM(duration)
FROM Payments
GROUP BY email, MONTH(pDate);
```

---

### 💡 Real-World Example

**Q:** Given `CITY` and `COUNTRY` tables, find the **average city population** per continent (rounded down):

```sql
SELECT COUNTRY.Continent, FLOOR(AVG(CITY.Population))
FROM CITY
JOIN COUNTRY ON CITY.CountryCode = COUNTRY.Code
GROUP BY COUNTRY.Continent;
```

---

### 🧪 Filtering Groups with `HAVING`

`HAVING` filters **groups** after aggregation—unlike `WHERE`, which filters **rows before grouping**.

📌 Example:

```sql
SELECT email, SUM(duration)
FROM Payments
GROUP BY email
HAVING MAX(YEAR(pDate)) >= 2020;
```

- First, group by `email`
- Only keep groups where the latest payment is in or after 2020
- Then, compute the total duration for those groups

---

### 🔍 WHERE vs HAVING

| Clause  | Filters | Applies To |
|---------|---------|------------|
| `WHERE` | Rows    | Before grouping |
| `HAVING`| Groups  | After grouping  |

📌 Example using `WHERE`:

```sql
SELECT email, SUM(duration)
FROM Payments
WHERE YEAR(pDate) = 2020
GROUP BY email;
```

- Filters out all payments not in 2020 **before** grouping.
- Groups the remaining by `email`, then sums.

---

### 💡 Advanced Example

**Q:** For each cohort, find the **maximum problems solved** by any student, but **only include cohorts** with at least 5 students.

```sql
SELECT cohort, MAX(problem_solved)
FROM Users
GROUP BY cohort
HAVING COUNT(DISTINCT UserID) >= 5;
```
