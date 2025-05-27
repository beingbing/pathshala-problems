# 🏗️ **Maintainability & Microservices: Designing an Online IDE**

## 🔍 **Our Current Understanding**
So far, we’ve established:

* 📈 **Traffic**:
    * \~30 requests per second
    * Read\:Write ratio ≈ 1:1

* 💾 **Data Volume**:
    * Each request produces \~3MB of data
    * Daily total = \~8TB (for code, inputs, and outputs)

## 🧩 **Backend APIs (Recap)**
1️⃣ **`submitCode(language, code, code_input)`**
* Saves the code in the DB and returns a unique `submission_id`.
* Launches a background thread to execute the code asynchronously.
* Stores the output in the DB once execution completes.

2️⃣ **`getResult(submission_id)`**
* Client polls this API to check if code output is ready.
* Until the result is available, responds with "Your submission is in queue."

3️⃣ **`generateUrl(submission_id)`**
* Generates a unique, shareable URL for a given submission.
* Stores the URL mapped to `submission_id` in the DB.
* Consistent hashing can be used for generating unique URLs.

4️⃣ **`getSubmission(unique_url)`**
* Extracts the `submission_id` linked to the `unique_url`.
* Retrieves submission details (code, language, input) and output (if ready) from the DB.

## 🚦 **Why Microservices?**
A **monolithic backend** handling all of this isn’t scalable or maintainable. To improve:
* **Reliability** – Isolate failures to specific services.
* **Scalability** – Scale services independently based on load.
* **Maintainability** – Easier updates and debugging per service.

## 🛠️ **Proposed Microservice Architecture**
We’ll **divide responsibilities** into three distinct microservices:

- **Submission Service**
  * Handles code submissions and input storage.
- **Result Fetcher Service**
  * Executes code asynchronously.
  * Stores execution output separately.

- **URL Service**
  * Manages unique URL generation and retrieval.

## 🗃️ **Decoupled Data Storage**
To complement our microservices, we’ll **split the database** into separate, specialized DBs:
* **Submission DB**: Stores code, language, and input linked to `submission_id`.
* **Result DB**: Stores execution output linked to `submission_id`.
* **URL DB**: Stores mappings between `submission_id` and `unique_url`.

## 🔄 **Revised Data Flow**
* `/submitCode`: Saves submission in Submission DB and initiates code execution.
* Execution thread stores output in Result DB (instead of the same DB).
* `/getSubmission(unique_url)`:
    1. Retrieve `submission_id` from URL DB.
    2. Fetch code and input from Submission DB.
    3. Fetch result (if ready) from Result DB.

## 🎯 **Conclusion**

By splitting the system into microservices with dedicated DBs, we achieve:

* **Higher scalability** – services can scale based on usage.
* **Improved maintainability** – changes to one service won’t disrupt others.
* **Reliability** – isolated failures don’t affect the whole system.
