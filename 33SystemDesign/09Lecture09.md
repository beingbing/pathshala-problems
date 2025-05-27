# 🌐 **Polling and WebSockets**
Now that we’ve explored asynchronous communication and backend scalability, let’s shift focus to **how responses are delivered to clients** once the backend is ready.

## 🔄 **Polling Mechanism**
After the backend acknowledges a request (e.g., with a token), the client starts periodically checking ("polling") for the status of its request.

### 📡 **Types of Polling**
1. **Short Polling** (Rarely Used)
* The client sends requests at fixed intervals ("Is it ready?").
* If the response isn’t ready, it receives a "not yet" message.
* **Drawbacks:**
  * Too short an interval leads to unnecessary network traffic.
  * Too long an interval delays responses.
  * Inefficient because each request requires a new TCP connection (DNS lookup, handshake, SSL/TLS).

2. **Long Polling**
* The client sends a request, and the server **holds it open** until the response is ready or the client times out.
* Once ready, the server responds, and the client processes the result.
* The connection remains open (persistent) but consumes minimal resources, as long as the server efficiently manages thousands of idle connections.
* **Benefits:**
  * Near real-time updates with fewer requests.
  * Reduces network load compared to short polling.
* **Challenges:**
  * The system must efficiently manage many open connections.
  * Poorly designed setups can overload servers.
* **Technical Note:**
  * Long polling uses **HTTP Keep-Alive** to reuse TCP connections, avoiding the overhead of frequent handshakes.

## 🔁 **From Polling to Persistent Communication: WebSockets**
While long polling improved response delivery by keeping connections open, it was still half-duplex:
* **Client requests** updates, **server responds**.

This inspired a more advanced approach:
* Why not maintain a **permanent, full-duplex connection** where **both client and server can send messages at any time**?

Enter **WebSockets**:
* Establishes a **permanent, bidirectional (full-duplex) connection** over a single TCP socket.
* Both the client and the server can **send and receive messages** independently and asynchronously.
* **Common Use Cases:**
  * Real-time notifications (e.g., chat apps, stock tickers).
  * Live dashboards and multiplayer games.

## 🧠 **WebSocket Challenges**
* Each WebSocket connection ties up server resources (memory, threads, sockets).
* Load balancers (LBs) struggle with WebSockets because:
  * LBs excel at routing **stateless, short-lived requests**.
  * WebSockets are **stateful, persistent**, making it hard to reassign connections to different servers.
* In high-traffic environments (thousands of simultaneous connections), special architectures are required (e.g., sticky sessions, dedicated WebSocket servers, horizontal scaling).
