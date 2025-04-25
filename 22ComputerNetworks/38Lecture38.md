# 🌐 What Happens When You Open a Website in a Browser?

When you type a URL (like `www.example.com`) into your browser, a complex but efficient process unfolds behind the scenes:

---

### 1. 🔍 Domain Name Resolution (DNS Lookup)
- The browser first **contacts a DNS server (on port 53)** to convert the domain name into an IP address.
- A **DNS Recursive Resolver (DRR)** takes charge:
  - It queries **Root Servers**, **TLD Servers** (like `.com`), and **Authoritative Name Servers** step-by-step.
  - Once it finds the correct IP address for the domain, it returns it to the browser.

> Think of DNS as asking "Where can I find `example.com`?" and being directed through a chain of informed contacts.

---

### 2. 🔐 Establishing a Secure Connection (TCP + TLS Handshake)
- The browser initiates a **TCP connection to IP:443**, the default port for HTTPS.
- A **TCP three-way handshake** takes place to establish a reliable connection.
- Then, a **TLS handshake** ensures the connection is **encrypted and secure**, verifying the server’s identity using its SSL/TLS certificate.

---

### 3. 📥 Requesting the Web Page
- After the connection is secured, the browser sends an **HTTP GET request** for the web page.
- The server processes this request and responds with **HTML, CSS, JS, and media files**.

---

### 4. 🧱 Rendering the Page
- The browser parses the HTML and builds a **DOM (Document Object Model)**.
- It applies styles (CSS), executes scripts (JavaScript), and renders the visual content on your screen.

---

### 5. 🔁 Backend Communication (After Load)
- Once the page is rendered, the **frontend (UI)** may make **asynchronous requests (e.g., via AJAX, fetch, WebSocket)** to communicate with the backend for dynamic data (like chat messages, profile updates, etc.).

---

### 6. ❌ Closing the Connection
- Depending on HTTP version (e.g., HTTP/1.1 or HTTP/2), the connection may be kept alive for further use or closed after the response is complete.

---

## ⚡ Browser Cache

- Browsers **cache** resources (like images, stylesheets, or entire pages) from frequently visited sites to speed up future visits.
- If a cached page is available, the browser may **serve it instantly** without reaching out to the server.
- However, cached content can become **stale**. So, browsers often check with the server (using headers like `ETag` or `Last-Modified`) to see if updates are needed.

---

### 🧠 TL;DR Summary
> Type URL → DNS Lookup → TCP + TLS Handshake → HTTP Request → DOM Rendering → Backend Interaction → Cache Management