# Maintainability of Design - Microservices

Everything that we derived so far is -

## requirements -
- 30 req/sec
- R:W::1:1
- data to store - 3MB / req ~ 8TB / day

## Backend APIs -
```
submission_id submitCode(language, code, code_input);
```
- stores code in DB and generate a submission_id, and return it.
- spun a new thread to execute code with given code_input
- new thread will generate code_output and will store that in DB.

###
---
###

```
code_output getResult(submission_id);
```
- until we get a code_output in response 'your submission is in queue' will be displayed on FE.
- and regular polling will be done to check if an output is generated or not.
- backend will check in DB if an output is present.

###
---
###

```
unique-URL-for-code generateUrl(submission_id);
```
- backend will generate a unique URL and save it against submission_id in DB
- for URL generation we can use consistent hashing.

###
---
###

```
{code, language, code_input, (if execution is done then code_output as well)} getSubmission(unique_url);
```
- backend first extract submission_id against unique_url
- all details will be queried against the submission_id and returned in response.

> **Note:** Ensuring reliability, Maintainability and scalability while writing these APIs.

## But lets first talk about Microservices -
A common backend handling all this services is not practical. So, will be dividing them into
separate microservices, so, we will have,
- submission service
- result fetcher service
- url service
Now, all these services will be deployed on a separate machine.
similarly,
we will be dividing our DBs as well, hence we will get -
- submission DB
- result DB
- URL DB

so, our result thread spun by /getResult API will now be putting execution results in results DB.
and, our /getSubmission API will first get submission_id from URL DB, then fetch submitted code
from submission DB and result of submission from result DB.

###
---
###

Let's now focus on our submission service and submission DB.
