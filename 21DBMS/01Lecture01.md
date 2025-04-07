## 📊 Introduction to DBMS

### 🔢 Understanding the Basics

- **Data**: Raw, unprocessed facts.  
  _Example_: `"Samar"`, `"Cohort4"`, `200`

- **Information**: Meaningful sentences formed using data.  
  _Example_: `"Samar is a student of Cohort4 and scored 200 marks."`

- **Knowledge**: Conclusions drawn from information.  
  _Example_: `"Samar is one of the top scorers in Cohort4."`

---

## 🗃️ What Is a DBMS?

**DBMS (Database Management System)** is a software system designed to **store, organize, manage, and retrieve data** efficiently.

Applications built on top of a DBMS interact with it using **queries** (e.g., SQL queries) to extract useful information. The **interpretation of this information into knowledge** is up to the user.

---

## ❓ Why Not Use Other Storage Methods?

### Option 1: **Storing Data in RAM**
- RAM is **volatile** – all data is lost when the system shuts down.
- Not suitable for long-term storage.

### Option 2: **Storing Data in Files**
- **Complex and error-prone** to retrieve or update data.
- **Hard to scale** – every small change may require rewriting code.
- **Inefficient** in terms of time and processing.
- **Security** is difficult to enforce.

---

## ✅ Why Use a DBMS?

A DBMS solves all of the above problems by offering:
- **Persistent storage** (data is saved permanently).
- **Structured access** using queries.
- **Efficient data retrieval and modification**.
- **Security and user-level access control**.
- **Reduced redundancy and improved consistency**.
