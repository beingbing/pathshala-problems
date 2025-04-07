## 🏗️ Creating Tables in SQL

To define a new table in SQL, we use the `CREATE TABLE` command:

```sql
CREATE TABLE Users (
    email VARCHAR(50) NOT NULL,
    first_name VARCHAR(20),
    marks INT DEFAULT 0,
    userID INT,
    PRIMARY KEY (userID),
    UNIQUE(email)
);
```

### 📌 Attribute Definition Syntax:

Each attribute is defined as:

```
attribute_name  data_type  [constraints]
```

Examples:
- `email VARCHAR(50) NOT NULL`
- `marks INT DEFAULT 0`

---

## 🧾 Data Types (Domains) in SQL

| Category         | Examples                                                                 |
|------------------|--------------------------------------------------------------------------|
| Numeric          | `INT`, `SMALLINT`, `FLOAT`, `DOUBLE PRECISION`, `DECIMAL(p, s)`          |
| Character        | `CHAR(n)` (fixed size), `VARCHAR(n)` (variable), `TEXT`                  |
| Boolean          | `BOOLEAN` (TRUE/FALSE)                                                   |
| Date/Time        | `DATE`, `TIME`, `TIMESTAMP WITH TIME ZONE`                              |
| Others (limited) | `JSON`, `ARRAY` (supported in some DBMS like PostgreSQL)                 |

---

## ✅ Constraints

Constraints define rules for the data:

| Constraint     | Meaning                                                        |
|----------------|----------------------------------------------------------------|
| `NOT NULL`     | Column must have a value                                       |
| `DEFAULT val`  | Automatically uses `val` if no input is given                  |
| `UNIQUE`       | No two rows can have the same value(s) in this column/set      |

Example of a composite unique constraint:
```sql
UNIQUE(email, phoneNumber)
```

---

## 🔑 Understanding Keys in DBMS

### 1. Super Key
- A set of attributes that uniquely identifies a row.
- May contain extra (non-minimal) attributes.

### 2. Candidate Key
- A **minimal super key** (i.e., no redundant columns).
- A table can have **multiple** candidate keys.

Example:
- ✅ `(email, phoneNumber)` → Candidate Key  
- ❌ `(userID, firstName)` → Not minimal if `userID` is enough

### 3. Primary Key
- One candidate key is chosen as the **primary identifier** for a row.
- Cannot be NULL or duplicated.

```sql
PRIMARY KEY(userID)
```

### 4. Foreign Key
- Used to **establish relationships** between tables.
- Points to a **primary key** in another table.

```sql
CREATE TABLE User_Payment_Map (
    UID INT NOT NULL,
    PID INT NOT NULL,
    PRIMARY KEY (UID, PID),
    FOREIGN KEY (UID) REFERENCES Users(userID),
    FOREIGN KEY (PID) REFERENCES Payments(paymentID)
);
```

---

## 🧠 Representing IDs in Tables

To uniquely identify rows, IDs can be managed in two main ways:

| Method           | Notes                                                                 |
|------------------|-----------------------------------------------------------------------|
| Auto-incremented | Useful and easy, but needs **atomicity** to avoid race conditions     |
| UUID             | Random large strings (universally unique); avoids sync issues         |

Example (PostgreSQL):
```sql
id UUID DEFAULT gen_random_uuid()
```
