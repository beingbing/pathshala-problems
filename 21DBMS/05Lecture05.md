## 🔗 Types of Relationships in ER Diagrams

In an **Entity-Relationship (ER) Diagram**, relationships describe **how entities are associated** with each other. The **type of relationship** is determined by **cardinality**—which tells us how many instances of one entity relate to another.

---

### 1️⃣ Cardinality Types

**Cardinality** defines the number of instances involved in a relationship. There are four common types:

| Type             | Description                                  | Example                          |
|------------------|----------------------------------------------|----------------------------------|
| One-to-One       | One entity instance maps to one of another   | Person ↔ Passport                |
| One-to-Many      | One entity maps to multiple of another       | Teacher → Students               |
| Many-to-One      | Many entities relate to one instance         | Employees → Department           |
| Many-to-Many     | Many instances map to many others            | Students ↔ Courses               |

---

### 2️⃣ ER Diagram Notation for Cardinality

- **One**: Represented by a **directed arrow (→)** from the relationship diamond to the entity.
- **Many**: Represented by a **simple line (—)** (no arrow).

This helps visually indicate the **type of association** between entities in the diagram.

---

### 3️⃣ Roles in Relationships

Every connection in a relationship can have **roles**, which describe the **context or function** each entity plays.

For example:
- In a `manages` relationship between **Employee** and **Department**, roles could be:
  - *manager* (Employee)
  - *managedDept* (Department)

Roles clarify the **semantic meaning** of relationships.

---

### 4️⃣ Participation: Total vs Partial

**Participation** describes **whether every instance of an entity is involved** in a relationship.

| Type               | Notation         | Description                                       |
|--------------------|------------------|--------------------------------------------------|
| Total Participation | **Double Line**  | Every entity must participate                    |
| Partial Participation | **Single Line**  | Only some instances are involved                 |

📝 **Note**: Sub-entities usually participate **totally**, while super-entities participate **partially** in relationships.

---

### 5️⃣ Degree of Relationships

While most relationships are **binary** (involving two entities), relationships can be of **higher degree**:

| Degree       | Example                              |
|--------------|--------------------------------------|
| Binary       | Student ↔ Course                     |
| Ternary      | Doctor ↔ Patient ↔ Medication        |
| Quaternary   | Supplier ↔ Product ↔ Store ↔ Region  |

> 🔍 **Best Practice**: Try to convert higher-degree relationships into multiple **binary relationships** where possible. It simplifies the schema and improves clarity.
