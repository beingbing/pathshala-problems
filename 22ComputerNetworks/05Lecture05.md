## 📶 Multiplexing – Efficient Use of Shared Communication Medium

### 🔧 The Real-World Problem

Suppose you’re setting up a network in a neighborhood. You have:

- A **main router** that connects the area to the outside world.
- **4 lanes**, each with **3 houses**.

#### 🧱 Option 1: One wire per house
Too expensive and inefficient —
- Wastage of resources (wires going too far for few users)
- Underutilization (some users might barely use the connection)

#### 🔀 Option 2: One common wire per lane
Each lane shares one wire that connects to the main router.  
From there, smaller wires split into each house.

✅ This is more efficient.  
❌ But it introduces a new problem: **signal collision**  
If multiple users send data at the same time, signals might **interfere**, leading to **data corruption**.

---

### 🎯 Enter Multiplexing

> **Multiplexing** is the technique used to allow multiple signals to share a single medium **without colliding**.

It answers the key question:
> _If multiple users share one communication line, how do we prevent their data from interfering with each other?_

---

### ⚙️ Types of Multiplexing

#### 1. **Frequency Division Multiplexing (FDM)**
- Each user is assigned a **different frequency range** to transmit their signal.
- Works like FM radio — many channels (stations) on different frequencies.
- Still not foolproof — overlapping signals or external interference can cause issues.

#### 2. **Time Division Multiplexing (TDM)**
- Each user is assigned a specific **time slot** in a **round-robin** fashion.
- Only one user sends data at a time, reducing the chance of collision.
- Efficient when users take turns quickly — feels simultaneous.
