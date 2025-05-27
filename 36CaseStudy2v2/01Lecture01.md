# 💻 **Online IDE: Functional & Non-Functional Requirements**

## 🎯 **Functional Requirements**
The system provides a simple workflow for code submission, execution, and result retrieval:

1️⃣ **/submitCode API**
* **Input**: Programming language, code content, optional user input.
* **Output**: `submission_id` (unique identifier for tracking this submission).

2️⃣ **/getResult API**
* **Input**: `submission_id`.
* **Output**: Execution result (e.g., output, errors).

3️⃣ **Code Sharing**
* Generate a **unique URL** to share the submitted code and its output with others.

## 🏗️ **Non-Functional Requirements**
The system should ensure **robustness, performance, and security**:

- **High Availability**: The IDE must be accessible with minimal downtime to handle user load effectively.
- **Consistency**: For the same code and input, the output must be deterministic and consistent across executions.
- **Performance**: Code submissions should execute and return results quickly, with minimal wait time for users.
- **Security & Isolation**:
  * User-submitted code should run in **sandboxed environments** to prevent unauthorized access to system resources or other users' code and data.
  * Proper resource limits (CPU, memory, execution time) must be enforced to mitigate abuse and denial-of-service attacks.
- **Time & Memory Limits**:
  * The system should impose limits on how long code can run and how much memory it can use, to prevent resource exhaustion and ensure system stability.
