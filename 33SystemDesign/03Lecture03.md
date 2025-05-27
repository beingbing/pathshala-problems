# ⚖️ Load Balancing Algorithms
Now that we know **why load balancers are essential**, let’s explore **how they decide where to send each request**. Different load balancing algorithms cater to different traffic patterns and server capacities.

## 🔄 1️⃣ Round-Robin
Requests are distributed in a simple rotation, giving each backend server an equal share.
- Works well when servers are similar and requests are uniform.
- Drawbacks:
  * Doesn’t account for server capacity—weak servers may get overloaded, strong servers underused.
  * Doesn’t consider request weight—some servers may get hit with heavier requests.

## ⚖️ 2️⃣ Weighted Round-Robin
Each server is assigned a weight proportional to its capacity.
- More powerful servers handle more requests.
- Still doesn’t solve the "heavy request" issue.

## 🔎 3️⃣ Least Connections
Directs new requests to the server with the fewest active connections.
- Dynamic and responsive to server load.
- Doesn’t consider server capacity.

## 🔗 4️⃣ Weighted Least Connections
Combines least connections with server capacity weighting.
- Sends requests to servers with the lightest current load relative to their capacity.
- Balances both active connections and server strength.

## 🎲 5️⃣ Random (with Consistent Hashing)
Requests are distributed randomly, but with **consistent hashing** to ensure a client consistently connects to the same server when possible.
- Helps with sticky sessions (user always reaching the same server).
- Good for balancing traffic, especially in sharded or federated systems.

## 🌐 Where Does the Load Balancer Work?
* **Layer 4 (Transport Layer)** – Hardware-based LBs operate here. They work at the packet level, handling requests based on IP and port, without inspecting content. Fast but limited in logic.
* **Layer 7 (Application Layer)** – Software-based LBs (e.g., Nginx) operate here. They can read request content (e.g., HTTP headers), enabling smart routing decisions like Federation or Sharding. Slower but more flexible.
