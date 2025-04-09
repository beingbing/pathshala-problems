## 🔄 Recoverable & Cascadeless Schedules — Avoiding Dirty Rollbacks

In concurrent transactions, things can go wrong if one transaction **depends on** another that eventually **fails**. Let’s walk through the types of schedules and what issues they can cause.

---

### ❌ Non-Recoverable Schedule

Consider this example:

```
T1         T2
r(A)
w(A)
           r(A)
           commit
abort
```

Here’s the problem:
- `T2` **reads** a value written by `T1`.
- `T2` **commits** before `T1` finishes.
- Later, `T1` **aborts**, making `T2`'s commit invalid because it read an **uncommitted/dirty value**.

> 🧨 This is a **non-recoverable schedule**. Once `T2` commits, we can't undo it safely — breaking **durability** and **consistency**.

---

### ✅ Recoverable Schedule

To fix that, we require:

> A transaction should **commit only after** all transactions it depends on have **committed**.

So in a **recoverable schedule**, `T2` must **wait** for `T1` to commit before it can commit.

This way, if `T1` aborts, `T2` can also be rolled back safely — avoiding invalid state.

---

### 🔁 Cascading Rollback — The Ripple Effect

Now imagine this:

```
T1         T2         T3
r(A)
w(A)
r(B)
           r(A)
                      r(B)
abort
```

When `T1` aborts:
- `T2` must rollback (it read from `T1`)
- `T3` might also rollback (it read from `T2`)

> This chain reaction is called a **cascading rollback** — one failure leads to many rollbacks, potentially **undoing a large part** of the system’s work.

---

### 🛡️ Cascadeless Schedule

To prevent cascading rollbacks:

> Only **allow a transaction to read data** that was **written by a committed transaction**.

So if `T2` wants to read something from `T1`, it must **wait** until `T1` **commits**.

This ensures:
- No transaction reads uncommitted (dirty) data
- No chain reactions on abort

Hence:

> ✅ **Every cascadeless schedule is inherently recoverable**  
> ❌ But not every recoverable schedule is cascadeless
