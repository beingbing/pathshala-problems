# 🌐 **Frontend System Design: Content Delivery Network (CDN)**
After covering the system design of the **database** and **backend server** tiers, let's move on to the **frontend server** — the layer responsible for delivering content to clients.

## 🚧 **Challenges in Frontend Scalability, Reliability & Maintainability**
The frontend typically serves **static content** (HTML, CSS, JavaScript, images) while dynamic data is fetched progressively from the backend. However, several challenges arise:
1. **High Latency**: Example: A user in India accessing a server located in the US experiences delays due to geographic distance.
2. **Data Localization**: Different countries may require custom pages, languages, or legal compliance.
3. **Responsive Design**: Different devices (desktops, tablets, phones) require content adapted to screen sizes.
4. **Real-Time Updates**: All clients, globally and regionally, need timely updates (e.g., promotions, UI changes, notifications).

## 🌍 **The Role of CDNs**
To address these challenges, we replicate static content in **region-specific locations**. This ensures:
- Low-latency access,
- Compliance with local regulations,
- Optimized content delivery for different screens.

This is where **Content Delivery Networks (CDNs)** like AWS CloudFront, Akamai, and others come into play. A **CDN** is a geographically distributed network of proxy servers that cache static content closer to users.

## 📦 **Types of CDNs**
CDNs can be broadly classified into **two types**, based on how they manage and update cached content:

### **1️⃣ Push CDN**
* The **origin server (main website)** actively **pushes updates** to all CDN edge servers as soon as changes are made.
* Useful for **planned updates**, like launching a new campaign or sale.
* Reduces the number of fetches from the origin server, as CDN servers always have the latest version.
* **Ideal for**:
  * Sites with **less frequent updates**
  * Smaller-scale businesses
- **Advantages**:
  * Faster content delivery (always updated at edges)
  * Minimal requests to the origin server

- **Disadvantages**:
  * Higher **storage requirements** on CDN edge servers
  * Potentially **higher costs**

### **2️⃣ Pull CDN**
* CDN edge servers **fetch content on-demand** from the origin server when a client requests a page.
* Once fetched, the content is cached for a set period (TTL - time to live).
* After TTL expires, the edge server re-fetches the content to ensure freshness.
* **Ideal for**:
  * Sites with **frequent updates**
  * High-traffic websites
- **Advantages**:
* Efficient storage (only cached content with recent requests)
* Better suited for **dynamic update needs**
- **Disadvantages**:
* More **origin server fetches**, even for content that hasn’t changed
* Slightly increased **latency** compared to push CDN
