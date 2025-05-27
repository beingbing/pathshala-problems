# 🚦 Backend Reliability: REST APIs
Now that we've covered how to design a **reliable and scalable database tier**, let’s shift focus to the **backend tier** of our system architecture.

## ⚠️ Reliability Challenges in Backend
A key challenge in backend systems is the **single point of failure**—if a backend server crashes, client requests fail.
But here’s the good news:
* Unlike databases, **backend servers don’t maintain persistent state**.
* Any client action that changes state should result in an update **stored in the database**, not the backend server.

## 🧭 Stateless Backend & REST APIs
Since the backend should not maintain state, we use **REST APIs** (Representational State Transfer).
* **REST APIs are stateless**—each client request contains all the information the server needs to process it.
* This design ensures backend reliability because any replica of the backend can handle the request independently.

## 🔁 Ensuring Backend Reliability
To address the single point of failure:
- **Replicate the backend servers**—run multiple instances of the same backend.
- Use a **load balancer** to distribute client requests evenly across these instances.
- Clients interact only with the load balancer, unaware of backend replicas.
- If one backend server fails, the load balancer routes requests to other available replicas.
