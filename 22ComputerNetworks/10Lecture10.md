## ⚖️ Access Control – Avoiding Signal Collisions

When multiple devices share the same communication channel, **collisions** can occur if two or more devices transmit at the same time.

Access control mechanisms help to:
- **Avoid collisions** in the first place.
- **Detect and handle** collisions if they happen.

---

### 🛂 Centralized Access Control

In these methods, a **central authority or mechanism** controls who gets to send data.

---

#### 1. 🗳 Polling (Used in Bus Topology)

- One node is assigned as the **Polling Manager**.
- When any node wants to send data, it sends a **poll request** to the manager.
- The manager decides **which node gets access**, and replies with a **permission (poll grant)**.
- This ensures only one node sends at a time, avoiding collisions.

> ❓ What if poll requests themselves collide?  
Not a major issue—polling can be retried.

**Drawback:**
- Managing and maintaining a polling manager can be **costly** and introduces a **single point of failure**.

---

#### 2. 🔁 Token-Based Access (Used in Ring/Star Topologies)

- A special control frame called a **token** circulates the network.
- Only the node **holding the token** can transmit data.
- After transmission, the token is passed to the next node.

**In star topology**, a **token manager** might control circulation.

> 🧠 Assumption: All nodes behave **fairly** and don’t hold onto the token longer than needed.

**Drawbacks:**
- If the token is **lost or corrupted**, it must be regenerated.
- **Slower in low traffic** conditions due to unnecessary waiting.

---

### 🌐 Decentralized Access Control

Here, no central authority is used. Nodes coordinate access themselves.

---

#### 3. 🌋 Pure ALOHA

- Nodes transmit data **whenever they want**.
- After sending, the node **waits for an ACK** from the receiver.
- If no ACK is received (collision assumed), the node waits for a **random time** before retrying.

**Drawbacks:**
- **Double bandwidth usage** (send + ACK).
- **High collision probability**, especially in busy networks.
- Can lead to **network congestion spiral**: more collisions → more retransmissions → more collisions.
- **Inefficient** due to long wait times even when the network is idle.

---

#### 4. ⏱ Slotted ALOHA

- Time is divided into **fixed time slots (T)**.
- A node can **only send at the start of a time slot**.
- Slot duration is designed such that a message sent in slot T exits the network before slot T+1.

**Advantage over Pure ALOHA:**
- **Reduces chances of collision** by aligning transmissions.

**Drawback:**
- Still not very efficient in **high-traffic environments**.

---

#### 5. 📡 CSMA/CD (Carrier Sense Multiple Access with Collision Detection)

Used in **wired Ethernet networks**.

**How it works:**
1. Node **senses** the channel before transmitting.
2. If the channel is **busy**, it waits.
3. If the channel is **idle**, it transmits.
4. While transmitting, it continues to **monitor for collisions**.
5. If a collision is detected, it:
   - **Stops transmission**
   - **Sends a jamming signal**
   - **Waits a random time** before retrying

**Drawbacks:**
- Still possible for **two nodes to transmit simultaneously** if they both sense an idle channel at the same time.
- **Less effective** in long-distance networks due to **propagation delay**.

---

### 🧠 Quick Summary

| Technique       | Centralized? | Key Idea                          | Efficient In           | Drawbacks                                  |
|----------------|--------------|-----------------------------------|------------------------|--------------------------------------------|
| Polling        | ✅ Yes       | Manager gives permission          | Controlled environments| Overhead, single point of failure          |
| Token Ring     | ✅ Yes       | Token grants access               | Fair sharing of access | Token loss, unnecessary waits              |
| Pure ALOHA     | ❌ No        | Send anytime, wait for ACK        | Low-traffic networks   | High collisions, inefficient               |
| Slotted ALOHA  | ❌ No        | Send at fixed time slots          | Better than ALOHA      | Still inefficient in busy networks         |
| CSMA/CD        | ❌ No        | Sense channel before sending      | Wired LANs (Ethernet)  | Can't prevent all collisions               |
