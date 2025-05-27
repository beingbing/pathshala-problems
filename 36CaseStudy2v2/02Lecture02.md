# 📈 **Capacity Estimation for Online IDE**
Designing an online IDE requires estimating the expected load and data volume to ensure the system can handle user demands effectively.

## 👥 **User Load & Request Rate**
* **Daily Active Users**: 1,000,000
* **Submissions/User/Day**: 2
* **Total Daily Submissions**: 2,000,000
* **Write Request Rate**:
    * $\frac{2,000,000}{24 \times 60 \times 60} \approx 24$ requests/second
    * Rounded up to **\~30 write requests/second**
* **Execution Duration**:
    * Each submission takes up to **2 seconds** on average (some languages like Python may reach up to 10 seconds).

## 💾 **Data Storage Estimation**
Each submission stores three components:
- **Code File** (\~1 MB)
- **Input File** (\~1 MB)
- **Output File** (\~1 MB)

* **Total Data per Submission**: \~3 MB

If submissions are stored for **5 days**, then:
* **Total Submissions Over 5 Days**: $2,000,000 \times 5 = 10,000,000$
* **Total Storage**: $10,000,000 \times 3$ MB = **30 TB**

## 🔁 **Read/Write Ratio**
* The system is primarily **write-heavy** due to frequent code submissions.
* **Read Traffic** is minimal since shared code is viewed by at most **2 users per submission**.
* Approximate **Read\:Write Ratio**: **1:1** (low reads, dominated by writes).
