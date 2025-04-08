## 🛠️ CRUD Operations in SQL

SQL supports four main operations on data, often remembered as **CRUD**:

1. **C**reate → `INSERT`
2. **R**ead → `SELECT`
3. **U**pdate → `UPDATE`
4. **D**elete → `DELETE`

---

### 📥 1. INSERT – Creating Rows

Used to add new rows into a table:

```sql
INSERT INTO Users (email, userID, firstName)
VALUES 
    ('abc@gmail.com', 001, 'abc'),
    ('def@gmail.com', 002, 'def');
```

**Important notes:**
- If a column is not specified:
  - If it has a `DEFAULT`, that value is used.
  - If it's nullable, `NULL` is stored.
  - If it's `NOT NULL` without a default, **an error is thrown**.

---

### 📤 2. SELECT – Reading Rows

#### Basic Read:
```sql
SELECT email, name FROM Users;
```

#### Filtering Data with `WHERE`:
```sql
SELECT email, name 
FROM Users 
WHERE year_of_graduation = 2020;
```

**Note:**
- SQL uses `<>` for “not equal to”.
- Combine filters using `AND` / `OR`.

#### Pattern Matching with `LIKE`:
```sql
-- Match emails ending with "@gmail.com"
SELECT email FROM Users WHERE email LIKE '%@gmail.com';

-- Match names with exactly 5 characters
SELECT name FROM Users WHERE name LIKE '_____';
```
- `%` → matches any number of characters  
- `_` → matches a single character

#### Removing Duplicates with `DISTINCT`:
```sql
SELECT DISTINCT email, phoneNumber FROM Payments;
```
- Returns unique combinations of specified columns.

#### Sorting with `ORDER BY`:
```sql
SELECT * 
FROM Users 
WHERE cohort = 5 
ORDER BY problem_solved DESC, year_of_graduation ASC;
```

🧠 **Example**:  
Get names of students with marks > 75, ordered by last 3 characters of name, then by ID:

```sql
SELECT name 
FROM Students 
WHERE marks > 75 
ORDER BY RIGHT(name, 3), ID ASC;
```

#### Using `BETWEEN` for Range Filters:
```sql
-- Equivalent statements:
SELECT * FROM Users WHERE year_of_graduation BETWEEN 2020 AND 2022;
SELECT * FROM Users WHERE year_of_graduation > 2020 AND year_of_graduation < 2022;
```

#### Working with `NULL`:
- `=` and `<>` **do not work** on `NULL`.
- Use `IS NULL` or `IS NOT NULL` instead:

```sql
SELECT * FROM Users WHERE resume IS NOT NULL;
```

#### Renaming Output Columns with `AS`:
```sql
SELECT email, 
       (problem_solved * 100.0 / attempted_problem) AS percent_solved 
FROM Users 
WHERE cohort = 5;
```

---

### ✏️ 3. UPDATE – Modifying Rows

Used to change existing records:

```sql
UPDATE Users 
SET email = 'abc@gmail.com', phoneNumber = '1234' 
WHERE userID = 10;
```

---

### 🗑️ 4. DELETE – Removing Rows

Deletes rows matching the condition:

```sql
DELETE FROM Users WHERE userID = 4;
```

---

### 🔗 Set Operations: `UNION`, `INTERSECT`, `EXCEPT`

Used to combine results of two `SELECT` queries:

```sql
(SELECT email, name FROM Users WHERE year_of_graduation = 2020)
UNION
(SELECT email, name FROM Users WHERE problem_solved > 200);
```

| Operation     | Description                                                           |
|---------------|-----------------------------------------------------------------------|
| `UNION`       | Combines results, **removes duplicates**                              |
| `INTERSECT`   | Keeps **only common** rows between both results                       |
| `EXCEPT`      | Keeps rows from the **first query that aren’t in the second**         |

📝 **Important:**  
- The number and order of selected columns must be **identical** in both queries.
- Column data types should be **compatible**, else SQL throws an error.
