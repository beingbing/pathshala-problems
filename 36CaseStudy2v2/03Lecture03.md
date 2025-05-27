# 🖥️ **Basic System Design: Online IDE**
Let's focus on designing the **backend APIs** and **workflow** for handling code submissions and result retrieval efficiently.

## 1️⃣ **API: `submitCode(language, code, code_input)`**
* **Purpose**:
    * Accepts code, language, and optional input from the user.
    * Generates a unique `submission_id`.
    * Stores the submission details (code, input, language) in the **database** under `submission_id`.
    * **Asynchronous Execution**: Spawns a background thread to execute the code using the specified compiler and input.
    * Once execution completes, stores the output in the **database** under the same `submission_id`.

* **Client Experience**:
    * Instead of making the user wait indefinitely, the server immediately responds with a **"code queued" message** and the `submission_id`.
    * The user can continue other activities while the code runs in the background.

## 2️⃣ **API: `getResult(submission_id)`**
* **Purpose**:
    * The client **polls periodically** using `submission_id` to check if the code output is ready.
    * Once the execution completes and output is stored in the DB, the server returns the output, stopping the polling.

* **Client Experience**:
    * No need to keep the connection open while waiting for the output.
    * Frontend initiates periodic polls until the output is ready, allowing the user to multitask.

## 📝 **Workflow Summary**
1. **Code Submission**: Client sends code → Server saves code with unique `submission_id` → Spawns background thread for execution → Responds with `submission_id`.

2. **Code Execution**: Backend executes code in an isolated environment → Stores result in DB against `submission_id`.

3. **Result Retrieval**: Client polls `getResult(submission_id)` → Server checks DB for output → Returns output if ready.
