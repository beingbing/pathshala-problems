# 📐 **Designing a URL Shortener – Back-of-the-Envelope Calculations**
When designing a **URL shortener system** (like Bitly), we need to estimate the scale of usage and data production to ensure the system can handle the expected load.

## 🌍 **Estimated User Base**
* **India**: \~100,000 users
* **Global**: \~10 million users

This gives us a **large, globally distributed user base**, with the system likely experiencing **higher load in certain regions**.

## 📊 **Traffic Estimates**
* **Monthly Write Requests (New Shortened URLs)**: \~10 million
* **Monthly Read Requests (URL Expansions)**: \~100 million
* **Read/Write Ratio**: 10:1 (a read-heavy system)

This highlights that the system needs to **optimize for read performance** while still efficiently handling writes.

## 🗂️ **Data Storage Calculations**

1️⃣ **URL Storage Requirements**
* **Long URL size**: Up to 1024 bytes (1 KB)
* **Short URL format**: e.g., `bit.ly/abc123` (\~13 characters or 13 bytes)
* **Metadata**: Creation & expiration timestamps (8 bytes each → 16 bytes total)
* **Total data per URL**: \~1.29 KB

2️⃣ **Monthly Data Production**
* \~10 million new URLs × 1.29 KB = **12.9 GB per month**

3️⃣ **Annual Data Production**
* 12.9 GB/month × 12 = **\~150 GB/year**

4️⃣ **10-Year Data Estimate**
* \~150 GB/year × 10 = **\~1.5 TB over 10 years**

🔍 **Observation**:
We need **expiration and cleanup mechanisms** to remove old/expired URLs, as continuously searching through **1.5 TB** of stale data would hurt performance.

## 🔑 **Unique Short Code Space**
* **Character Set**: \[A-Z, a-z, 0-9] → 62 possible characters
* **Short Code Length**: 6 characters → **62⁶ ≈ 56.8 billion combinations**
  This is **more than enough** to uniquely represent billions of URLs while keeping short codes concise.

## ⚙️ **Request Load per Second**
* **Write Requests**: \~3 writes/second (10 million writes per month)
* **Read Requests**: \~30 reads/second (100 million reads per month)
  This manageable load allows scaling with **horizontal replication and caching**.

## 🖥️ **Server Requirements**
* **Assumption**: Each server handles \~10 threads of concurrent requests.
* **Server Setup**: Likely need **2–3 application servers** behind a **load balancer** to distribute traffic.
* **Database Replication**: 2–3 replicas for **redundancy** and **load balancing** to prevent bottlenecks.
