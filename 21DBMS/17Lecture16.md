## 👀 View Serializability — Beyond Conflict Checks

### 🔍 The Problem with Conflict Serializability

**Conflict serializability** is a commonly used test for correctness, but it's also a **stricter condition** than necessary. There are some valid schedules that fail conflict checks but still behave correctly — that’s where **View Serializability** comes in.

---

### 📉 Example: Not Conflict Serializable

Consider this schedule:

```
T1        T2
r(Q)      
          w(Q)
w(Q)
```

This schedule is **not conflict serializable**:
- `T2` writes to `Q` before `T1` writes, and you can't swap `T2`'s write with either `T1`'s read or write without changing the behavior.
- So, it fails the conflict serializability test.

But does that mean it’s invalid?

Let's analyze:
- If `T1` runs before `T2`, the final value will be from `T2`
- If `T2` runs before `T1`, then `T1`'s read would reflect the value written by `T2`, which it doesn’t

Hence, **this schedule is not equivalent to any serial schedule** — so it's **not view serializable either**.

---

### ✅ But What If It *Is* Valid?

Now take this schedule:

```
T1        T2        T3
r(Q)
          w(Q)
w(Q)
                    w(Q)
```

- It’s still **not conflict serializable** due to the non-swappable writes
- But let’s see what really happens:
  - `T1` reads the initial value of `Q`
  - Final value is written by `T3`
  - Intermediate writes from `T2` and `T1` are overwritten and don't affect the outcome

Now compare this with a serial schedule like:

```
T1 → T2 → T3
```

- `T1` reads the initial value ✅
- Final value is from `T3` ✅
- No read-from dependencies are violated ✅

So even though it **fails the conflict check**, it **behaves exactly like** a serial schedule → it's **view serializable**.

---

### 🧠 View Serializability: Definition

A schedule `S` is **view serializable** if it's **view equivalent** to some serial schedule `S'`.

**Two schedules are view equivalent if:**
1. **Initial Reads Match**: Any transaction reading the initial value in `S` also reads the initial value in `S'`.
2. **Read-From Match**: If `Ti` reads a value written by `Tj` in `S`, it does so in `S'` as well.
3. **Final Writes Match**: The transaction that performs the **last write** on each data item is the same in both `S` and `S'`.

---

### ⚖️ Conflict vs View Serializability

| Conflict Serializability | View Serializability |
|--------------------------|----------------------|
| Easy to check (linear time using precedence graph) | Hard to check (NP-complete) |
| Stricter — may reject valid schedules | More general — accepts all valid serial-equivalent schedules |
| Fails with **blind writes** (writes not based on reads) | Handles blind writes gracefully |

---

### 📌 Key Takeaway

> **Conflict Serializability** is a practical approximation of **View Serializability** — it’s easier to verify but may reject some valid interleavings.

Since **view serializability checking is NP-complete**, most systems rely on **conflict serializability** for practical enforcement.

