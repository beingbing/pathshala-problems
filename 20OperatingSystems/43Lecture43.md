## 🍽️ Dining Philosophers Problem – Explained

A classic synchronization problem involving **five philosophers** sitting around a **round table**. Each philosopher alternates between **thinking** and **eating**.

Between each pair of adjacent philosophers lies **one chopstick**, shared between the two.  
So, there are **5 philosophers** and **5 chopsticks** (one between each pair).

### 🔄 Eating Condition

For a philosopher to eat, they must **pick up both the chopsticks**—the one on their **left** and the one on their **right**.

This setup introduces a need for careful synchronization to avoid:

- **Deadlocks**: All philosophers pick up their left chopstick and wait indefinitely for the right one.
- **Starvation**: A philosopher may never get a chance to eat.

---

## 🧩 Basic Semaphore Solution (⚠️ Unsafe)

```cpp
Semaphore chopstick[5];

// Each philosopher i:
while (true) {
    // Thinking
    wait(chopstick[i]);                // Pick left
    wait(chopstick[(i+1)%5]);          // Pick right
    // Eat
    signal(chopstick[i]);              // Put left
    signal(chopstick[(i+1)%5]);        // Put right
}
```

### 🚨 Problem:
If **all 5 philosophers** pick up their **left chopstick** simultaneously, none can pick up their right—**deadlock** occurs.

---

## ✅ Deadlock-Free Solutions

### 1. **Allow Only 4 Philosophers at the Table (Easiest)**
Use a **counting semaphore** (`maxAllowed = 4`) to limit concurrent philosophers attempting to eat.

```cpp
Semaphore chopstick[5];
Semaphore room = 4; // only 4 philosophers allowed to try eating

while (true) {
    wait(room);                      // enter room
    wait(chopstick[i]);
    wait(chopstick[(i+1)%5]);
    // Eat
    signal(chopstick[i]);
    signal(chopstick[(i+1)%5]);
    signal(room);                    // leave room
}
```

### 2. **Asymmetric Solution (Break Symmetry)**
Let one philosopher (say, philosopher 0) pick **right first**, then **left**, while others do the opposite.

```cpp
if (i == 0) {
    wait(chopstick[(i+1)%5]);  // right
    wait(chopstick[i]);        // left
} else {
    wait(chopstick[i]);        // left
    wait(chopstick[(i+1)%5]);  // right
}
// Eat
```

This prevents the circular wait condition, which is necessary for deadlock.

---

### 3. **Pick Up Both Chopsticks Together (Atomic Request)**
Use a **mutex** or monitor to ensure both chopsticks are picked up together or none at all.

Example:
```cpp
synchronized(lock) {
    while (!leftAvailable || !rightAvailable) wait();
    // Pick both chopsticks
}
// Eat
synchronized(lock) {
    // Release both chopsticks
    notifyAll();
}
```
