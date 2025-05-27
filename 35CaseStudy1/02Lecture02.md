# 🌐 **Designing a URL Shortener (like Bitly)**

## 📚 **Functional Requirements**
At its core, the system provides two main operations:

### 1️⃣ **Shorten URL (Write Operation)**
* **Input**: A long URL (e.g., `https://example.com/feedback-form`)
* **Output**: A shortened URL (e.g., `https://bit.ly/abc123`)

**Key Features**:
* **Limited Length**: Short URLs should be concise (e.g., 6–10 characters), making them easy to share.
* **Uniqueness**: Each long URL must map to a unique short code. Collisions should be avoided, often by generating unique IDs or using hashing with collision resolution.
* **Expiration Support**: Optionally, users can set expiry times for short URLs (e.g., a feedback form link that expires after a week).
* **User Authorization**: Certain short URLs may be restricted to authorized users (e.g., internal surveys), requiring authentication or access controls.

### 2️⃣ **Expand URL (Read Operation)**
* **Input**: A short URL (e.g., `https://bit.ly/abc123`)
* **Output**: The original long URL (e.g., `https://example.com/feedback-form`)

The system should **quickly map short URLs back to their original long URLs**, even under high load.

## ⚙️ **Non-Functional Requirements**
These requirements define **how the system should perform** to meet user expectations:
* **Target User Base**:
  * Primarily intended for organizations like **colleges or corporate departments**.
  * Typical use cases include sharing **feedback forms, surveys, or promotional links**.

* **High Availability & Low Latency**:
  * Both shortening and expanding operations must be **fast and always available**, even during peak usage.
  * Low latency ensures **quick redirections and URL generation**, enhancing user experience.

* **Eventual Consistency**:
  * While it’s ideal for data (short URL ↔ long URL mapping) to be instantly consistent across all servers, the system can **tolerate eventual consistency**.
  * This means that **after a write operation**, there may be a brief window where some replicas haven’t updated, but they’ll catch up.
