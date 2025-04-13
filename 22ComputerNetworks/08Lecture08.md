## ⚠️ Error Control – Handling Data Corruption in Transmission

When data travels over a medium, it can get **corrupted due to interference** like electrical noise or magnetic fields. The **Data Link Layer** ensures that such errors are detected and possibly corrected before the data is used.

There are **two main types of transmission errors**:

---

### 1. 🔹 Single Bit Error  
Only **one bit** is altered during transmission.  
**Example:**  
Original → `110110101`  
Received → `110100101` (a single bit flipped)

🛠 **Solution: Parity Bit**
- A simple error detection technique.
- Count the number of 1s in the message:
  - If **even**, add a `0` as the parity bit.
  - If **odd**, add a `1` as the parity bit.
- Receiver checks parity. If it doesn’t match the expected parity, an error is detected.

> 📌 Good for detecting single-bit errors, but **fails for burst errors**.

---

### 2. 🔸 Burst Error  
**Two or more bits** are altered, typically due to **electromagnetic interference** (e.g., from heavy machinery nearby).

🛠 **Solution: Cyclic Redundancy Check (CRC)**
- A more robust method for detecting burst errors.
- Process:
  1. **Sender and receiver agree** on a generator number (a binary polynomial).
  2. Sender performs a **modulo-2 division** (XOR-based) of the message by the generator.
  3. The **remainder** (called the CRC) is appended to the message.
  4. Receiver redoes the same division; if remainder ≠ 0, an error is detected.

> ✅ CRC is not foolproof, but **extremely effective**—the chances of undetected errors are **very low**.
