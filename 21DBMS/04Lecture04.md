## 📊 Entity-Relationship Diagram (ERD)

**Purpose**:  
Before designing database tables, we first **visually map out the system** using an ER diagram. This helps define **what data we need to store** and **how entities relate to each other**.

---

### 🎯 Problem Statement Example  
**Design a Renaissance Dashboard** that includes:
- Course sections
  - Modules
    - Videos
    - Assignments (Questions)
- Users with subscriptions and payment history
- Video progress tracking (% watched)
- User code submissions with verdicts

---

## ✅ Step 1: Identify Entities

**Entity = Real-world object (noun) we need to store data for.**

From the problem:
- **User**
- **Section**
- **Module**
- **Video**
- **Assignment**
- **Question**
- **Submission**
- **Verdict**
- **Payment**
- **Subscription Model**

---

## ✅ Step 2: Define Attributes

**Attributes = Properties/information related to an entity.**

### Examples:
- **User**: name, email, phone number, college, graduation year  
- **Question**: ID, name, difficulty level, link, author  
- **Submission**: code, time, language  
- **Video Tracking**: % watched (derived attribute)

### Types of Attributes:

| Type               | Example                            |
|--------------------|-------------------------------------|
| Simple             | `email`, `ID`                       |
| Composite          | `fullName` = firstName + lastName   |
| Derived            | `% solved` = solved/total × 100     |

### Based on Quantity:

| Category           | Example                            |
|--------------------|-------------------------------------|
| Single-valued      | `college name`                     |
| Multi-valued       | `phoneNumbers` (could be multiple) |
| Nullable           | `middleName` (optional)            |

---

## ✅ Step 3: Define Relationships

**Relationships = Actions or associations between entities.**

From the problem:
- A **User** makes a **Payment**
- A **User** subscribes to a **Subscription Plan**
- A **Module** contains **Videos** and **Assignments**
- An **Assignment** contains multiple **Questions**
- A **User** makes **Submissions** for **Questions**
- A **User** watches a **Video** (track % watched)
- Each **Submission** has a **Verdict**

---

## 🖼️ ER Diagram Representation Rules

| Element         | Shape            |
|------------------|------------------|
| Entity           | **Rectangle**     |
| Attribute        | **Oval**          |
| Relationship     | **Diamond**       |
| Attribute of Relationship | Connected to diamond |

### 💡 Note:
- Relationships can have their **own attributes**, e.g.:
  - **"Makes"** (between User and Payment) → may include `timestamp`, `amount`.

---

## ✨ Summary

To design any database:

1. **Extract entities** (nouns from the problem)
2. **List attributes** for each entity
3. **Identify relationships** between entities
4. **Visualize** the ER diagram using:
   - Rectangles for Entities
   - Ovals for Attributes
   - Diamonds for Relationships
