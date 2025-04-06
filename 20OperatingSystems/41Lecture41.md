## 🧵 Bounded Buffer Problem (Producer-Consumer)

A classic **synchronization** problem where multiple threads (producers and consumers) share a **fixed-size buffer**.

---

### 📦 Problem Setup

We have:

- A **bounded buffer** (circular array) of size `BUFFER_SIZE`
- Two types of threads:
  - **Producer**: generates data and puts it into the buffer.
  - **Consumer**: takes data from the buffer and uses it.

#### Shared Variables

- `in` → Index where the next item will be **inserted**.
- `out` → Index where the next item will be **removed**.
- `counter` → Number of **items currently in the buffer**.

#### Buffer Behavior

- If `counter == BUFFER_SIZE`, the buffer is **full** → producer must wait.
- If `counter == 0`, the buffer is **empty** → consumer must wait.
- Indices wrap around using `(index + 1) % BUFFER_SIZE` to simulate a circular buffer.

---

### ❌ Problem in Multi-threaded Code

Basic implementation without synchronization:

```cpp
// Producer
while (true) {
    // produce item
    while (counter == BUFFER_SIZE); // busy wait
    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
    counter++;
}

// Consumer
while (true) {
    while (counter == 0); // busy wait
    item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    counter--;
    // consume item
}
```

🛑 **Issues**:
- `counter++` and `counter--` are **not atomic** → race condition.
- Multiple threads accessing `buffer`, `in`, `out`, and `counter` concurrently → inconsistent state.
- Busy waiting (spinning in loops) is inefficient.

---

### ✅ Correct Solution with Semaphores & Mutex

To ensure synchronization, we use:

- `mutex` → for **mutual exclusion** (to protect shared data).
- `empty` → counting semaphore for **available empty slots** (initialized to `BUFFER_SIZE`).
- `full` → counting semaphore for **filled slots** (initialized to `0`).

#### Updated Producer

```cpp
while (true) {
    // produce item
    wait(empty);         // wait for empty slot
    wait(mutex);         // enter critical section

    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
    counter++;

    signal(mutex);       // exit critical section
    signal(full);        // signal a full slot
}
```

#### Updated Consumer

```cpp
while (true) {
    wait(full);          // wait for at least one item
    wait(mutex);         // enter critical section

    item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    counter--;

    signal(mutex);       // exit critical section
    signal(empty);       // signal an empty slot

    // consume item
}
```

### 🧼 Clean Abstraction Tip

In real-world code, it’s better to avoid manually managing `counter` when you're already using `full` and `empty` semaphores—they **implicitly track** buffer usage.

---

### ✅ Correct Solution with Monitor

Assume we have a circular buffer of size `BUFFER_SIZE`, with `in`, `out`, and a counter.

```java
monitor BoundedBuffer {
    final int BUFFER_SIZE = 10;
    Item[] buffer = new Item[BUFFER_SIZE];
    int in = 0, out = 0, count = 0;

    condition notFull, notEmpty;

    public void insert(Item item) {
        while (count == BUFFER_SIZE)
            notFull.wait(); // wait until space is available

        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        count++;

        notEmpty.signal(); // notify a waiting consumer
    }

    public Item remove() {
        while (count == 0)
            notEmpty.wait(); // wait until item is available

        Item item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;

        notFull.signal(); // notify a waiting producer

        return item;
    }
}
```

- **Wait Conditions**:
  - `notFull.wait()` suspends the producer if the buffer is full.
  - `notEmpty.wait()` suspends the consumer if the buffer is empty.
- **Signals**:
  - `notFull.signal()` wakes up a blocked producer when a slot becomes free.
  - `notEmpty.signal()` wakes up a blocked consumer when an item is available.


---

### 🧠 Analogy

Think of a **monitor** as a "room with a lock":
- Only one person (thread) can be inside.
- If they can’t proceed (e.g., buffer is full/empty), they **wait in a queue**.
- When they leave and things change, they **notify others** waiting on specific conditions.
