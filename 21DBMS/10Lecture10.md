## 🔗 Joins in SQL

Joins are used to **combine data from two or more tables** based on a related column between them. This allows us to ask questions that span multiple tables.

### 🧠 How Joins Work

When two tables are joined, **each row of the first table is compared with every row of the second**. If the **join condition** matches (usually on a common key), the resulting row is included in the output.

📌 Example:

```sql
SELECT *
FROM Topics
JOIN Videos ON Topics.TID = Videos.TID
WHERE name = 'arrays';
```

Here, we're selecting all topic-video pairs where the topic name is `'arrays'`.

---

## 🌍 Real Example

**Q:** Given `CITY` and `COUNTRY` tables, find the **total population of cities in Asia**.

- Matching keys: `CITY.CountryCode` = `COUNTRY.Code`

```sql
SELECT SUM(CITY.Population)
FROM CITY
JOIN COUNTRY ON CITY.CountryCode = COUNTRY.Code
WHERE COUNTRY.Continent = 'Asia';
```

---

## 🔄 Types of Joins

### 1. **INNER JOIN** (or just `JOIN`)
- Returns **only matching rows** from both tables.
- If a row exists in one table but not in the other, it is **excluded**.

📌 Think of it as: "Only where both sides agree."

```sql
SELECT *
FROM A
JOIN B ON A.ID = B.ID;
```

---

### 2. **LEFT JOIN** (or `LEFT OUTER JOIN`)
- Returns **all rows from the left table**.
- If there's no match in the right table, the result will contain **NULLs** for right-table columns.

📌 Left table is prioritized.

```sql
SELECT *
FROM Topics
LEFT JOIN Videos ON Topics.TID = Videos.TID;
```

---

### 3. **RIGHT JOIN** (or `RIGHT OUTER JOIN`)
- Opposite of LEFT JOIN.
- Returns all rows from the **right table**, with NULLs if no match in the left.

📌 Right table is prioritized.

---

### 4. **FULL OUTER JOIN**
- Returns **all rows from both tables**.
- Where there’s no match, NULLs are used for the missing side.

📌 Includes everything from both sides, matched and unmatched.

```sql
SELECT *
FROM A
FULL OUTER JOIN B ON A.ID = B.ID;
```

> Note: Not all DBMS support `FULL OUTER JOIN` natively (e.g., MySQL), but it can be simulated using `UNION`.

---

### 5. **NATURAL JOIN**
- Automatically joins tables on all columns with the **same name**.
- You **don’t specify the join condition**.

📌 Use with caution: if multiple columns share the same name unintentionally, it may cause unexpected results.

```sql
SELECT *
FROM A
NATURAL JOIN B;
```
