## 🌐 Introduction to Computer Networks

At its core, **computer networking** is about enabling communication between computers. One common use of networks is **accessing webpages** hosted on other machines.

---

### 🧳 What Is Hosting?

**Hosting** means placing your website’s code (HTML, CSS, etc.) on a server — a computer that stays connected to the internet — and **making it publicly accessible**.

This allows users anywhere in the world to view your website using a browser.

---

### 🧭 How Do Browsers Access a Webpage?

When you enter a URL in your browser, this sequence typically happens:

1. **Locate the server**:  
   The browser finds the IP address of the server where the webpage is hosted (via DNS lookup).

2. **Establish a connection**:  
   A communication link is set up between your browser and the hosting server (usually using TCP/IP).

3. **Send a request**:  
   The browser sends an HTTP or HTTPS request asking for a specific resource (like a webpage or image).

4. **Receive a response**:  
   The server processes the request and sends back a response (e.g., an HTML file), which the browser renders for you.

---

### ⚙️ Key Concerns in Networking

When accessing any hosted resource, the two most important factors are:

- **Speed (Latency & Bandwidth)**:  
  How fast the connection is and how much data it can handle at once.

- **Reliability**:  
  Whether the data reaches its destination correctly and consistently, even if parts of the network fail.

---

### 📌 Summary

Networking makes remote access to resources possible. To load a webpage:
- Your browser **finds** the host,
- **Connects** to it,
- **Sends** a request,
- And **receives** a response — all while aiming for speed and reliability.
