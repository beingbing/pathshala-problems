# Functional & Non-Functional Requirements

### Design an online IDE like ideone.com

#### Functional Requirements:
1. /submitCode API
    - Input: Code language, Code content, Input provided
    - Output: submission_id

2. /getResult API
    - Input: submission_id
    - Output: code_output

3. ability to share code and its output using a unique URL.

#### Non-Functional Requirements:
1. submitted code should be highly available.
2. results should be consistent. Same output for same input.
3. performance - code execution should be quick.
4. security - user code should be sandboxed. Code submitted should not be allowed to access other users submitted code.
5. Time and memory limits should be applied to code.
