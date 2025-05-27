## Database Reliability: How to Handle Incomplete Transactions
Previously, we discussed what happens if a database server goes down. Now, let’s focus on what happens if a **server crashes during an ongoing transaction**—and how to **maintain atomicity** in such scenarios.

### The Problem:
A database system must satisfy the **ACID properties**:
* **A**: Atomicity (all or nothing)
* **C**: Consistency (valid state)
* **I**: Isolation (concurrent transactions don’t interfere)
* **D**: Durability (once committed, data stays committed)

Imagine:
* Account A = 100, Account B = 200
* A transaction starts: 
  - Subtract 20 from A → A = 80 
  - \[Software error occurs]
  - Add 20 to B → (this step never happens)

In this case, since the error was caught before completion, the database can **rollback** the partial changes, ensuring **atomicity**.

### But What If the Error is a Hardware Crash?
* Suppose the system crashes right after subtracting from A but before adding to B.
* When the system restarts, A is still at 80 and B at 200—**20 is lost**!
* **Atomicity is violated** because the rollback information was lost.

### The Solution: Write-Ahead Logs (WAL)
To ensure reliability, databases use **Write-Ahead Logs (WAL)**:
- Before making any changes to the database, the system **writes a log entry** describing the change.
- The log is stored on **durable storage (e.g., disk)**, not just in volatile memory (RAM).
- WAL helps the system **recover from crashes** by either rolling back incomplete transactions or reapplying committed ones.
- This mechanism is a **fundamental part of reliable transaction processing** in databases.

In our example:
* Before subtracting 20 from A, a log entry is written: "subtract 20 from A."
* If the system crashes, it can **recover** by looking at the logs:

        * **Incomplete transactions** (like this one) are **rolled back**.
        * If the log shows a completed transaction, it can **reapply** the changes if needed.

This ensures:
* **Atomicity** (either the entire transaction happens, or none of it does),
* and **Durability** (once the transaction is committed, it survives crashes).
