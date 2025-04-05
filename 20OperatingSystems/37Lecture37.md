## 🕸️ Deadlock Avoidance Using Resource Allocation Graph (RAG)

### 🎯 Goal of Deadlock Avoidance

Instead of letting a deadlock happen and handling it later, **avoidance** ensures that the system **never enters an unsafe state**.

> ⚠️ Idea: **Deny resource requests that might lead to deadlock in the future.**

One fundamental approach to avoidance is using a **Resource Allocation Graph (RAG)**.

---

### 📊 What Is a Resource Allocation Graph?

A **Resource Allocation Graph** is a visual tool to model the interaction between **processes** and **resources**.

#### 🧩 Components:
- **Nodes**:  
  - **Processes** (e.g., `P1`, `P2`)  
  - **Resources** (e.g., `R1`, `R2`)

- **Edges**:  
  - **Request Edge (Wait Edge)**:  
    - From **process to resource** (`P1 → R1`)  
    - Indicates that a process is *waiting* for a resource.
  - **Assignment Edge (Hold Edge)**:  
    - From **resource to process** (`R1 → P1`)  
    - Indicates that a resource is *allocated* to a process.
  - **Claim Edge (Dashed Line)**:  
    - From **process to resource**  
    - Declares that the process **may request** this resource in the future (but hasn't yet).

---

### 🔁 Detecting Deadlocks in RAG

- If the graph contains a **cycle**, it may indicate a **deadlock**.
- In systems where **each resource has only one instance**, a cycle **definitely means deadlock**.

---

### 🛑 How RAG Avoids Deadlock

1. **Before granting a resource**, the OS:
   - Checks whether converting a **claim edge** to a **request edge** would create a cycle.
   - If a cycle is formed ➡️ **deny the request** (to stay in a safe state).

2. **Stricter Policy (Used by Some OSes):**
   - A process must **declare all required resources upfront** (via claim edges).
   - The OS evaluates the **entire graph** — including future requests — to decide:
     - Whether allowing the process to run could *eventually* lead to deadlock.
     - If yes, it’s not even allowed to start.

---

### 📌 Limitations of RAG

- This approach is suitable **only when each resource has a single instance**.
- In real-world systems with **multiple instances of resources**, RAG can't accurately model all scenarios.

➡️ That’s where **Banker’s Algorithm** comes in — a more generalized avoidance technique that handles multiple instances.
