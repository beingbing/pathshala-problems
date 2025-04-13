## 📡 Connection-Oriented Routing (Virtual Circuit Routing)

Once data packets enter the **Network Layer**, they carry **destination IP addresses** that routers use to forward them through the internet. This is where **routing tables** and the **store-and-forward** technique come into play.

---

### 🧾 What’s a Routing Table?

Every router maintains a **routing table** that helps it decide where to send an incoming packet next.

- **Format**:  
  `Destination IP → Next hop (router)`

These tables are not static. Their entries are updated based on different routing strategies, one of which is **Connection-Oriented Routing**.

---

### 📦 Store and Forward Mechanism

Routers don’t just blindly pass packets. They:
1. **Store** the incoming packet temporarily.
2. **Forward** it to the next router as per the routing table.

This mechanism ensures reliability. If a packet gets lost after leaving a router, the router can **resend** it, maintaining robust transmission.

---

### 🔄 What is Connection-Oriented Routing?

Also called **Virtual Circuit Routing**, this method tries to establish a reliable path *before* sending actual data packets.

#### 🔍 Steps:
1. The source router **floods test packets** throughout the network to discover all possible paths to the destination.
2. The **destination replies with an ACK** only to the **first test packet** it receives.
3. This ACK **traces back** the exact path through routers to the original sender.
4. Each router on that path remembers the **next hop toward the destination** for that virtual connection.

This forms a **temporary logical path**, similar to a "virtual circuit."

---

### ⚙️ Key Properties

- This method **sets up a route before transmission**, unlike pure packet switching.
- **Routers store path info** only for the duration of the connection.
- It’s still **packet-switched**, not circuit-switched, because:
  - Packets can be of variable length.
  - Nodes (routers) are **shared** across multiple connections.
  - There’s **no dedicated bandwidth** like in traditional circuit switching.

---

### ⚠️ Drawbacks

- **Initial flooding** for path discovery causes overhead.
- **Dynamic network changes** (e.g., nodes joining/leaving) can break the chosen path, requiring rediscovery.
- Paths might become **non-optimal** over time.
