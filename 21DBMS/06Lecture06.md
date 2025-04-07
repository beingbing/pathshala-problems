## 🧩 Converting ER Diagrams to Tables (Relational Schema)

Transforming an **Entity-Relationship (ER) Diagram** into database tables is a systematic process that ensures the structure and relationships of data are preserved.

---

### 🔹 1. Entity → Table

Each **entity** becomes a **table**, and its **attributes** become **columns**.

Example:  
**Entity**: `User`  
**Table**: `User(id, email, firstName, lastName, phoneNumber)`

---

### 🔹 1.1 Attribute Types & How They Are Stored

| Attribute Type       | Storage Rule                                                                 |
|----------------------|-------------------------------------------------------------------------------|
| Simple Attribute     | Stored as a **single column**                                                 |
| Composite Attribute  | Broken into **multiple columns** (e.g., fullName → firstName + lastName)      |
| Derived Attribute    | **Not stored** (calculated on-the-fly, e.g., age from DOB)                   |
| Multi-valued Attribute | Stored in a **separate table** with foreign key reference to the main entity |

Example for multi-valued attribute:  
A user with multiple phone numbers would have a `UserPhones(userId, phoneNumber)` table.

---

### 🔹 2. Relationships → Foreign Keys / Mapping Tables

How to convert relationships depends on their **cardinality**:

| Relationship Type  | Implementation                                                                |
|--------------------|--------------------------------------------------------------------------------|
| One-to-One (1:1)   | Add foreign key of one entity in the other’s table (either side is fine)       |
| One-to-Many (1:N)  | Add foreign key of the **'one' side** into the **'many' side's** table         |
| Many-to-One (N:1)  | Same as above (direction flipped)                                              |
| Many-to-Many (M:N) | Create a **new mapping table** with two foreign keys                           |

Example for many-to-many:  
`Student_Course(studentId, courseId)` represents which students are enrolled in which courses.

---

### 🔹 3. Participation Constraints

Participation (whether total or partial) affects **nullability**:

| Participation Type  | Impact on Table                         |
|---------------------|------------------------------------------|
| Total Participation | Foreign key column is **NOT NULL**       |
| Partial Participation | Foreign key column is **nullable**       |

This ensures the relationship constraints are properly enforced at the schema level.
