# Basic System Design

let's delve into the design of our backend servers, focusing on the APIs:

```
submission_id submitCode(language, code, code_input);
```
- backend server will first run the code to generate an output against given input, then save it
against a unique submission_id in DB, and respond with both output and submission_id.
- we will make two APIs, one for generating unique submission_id and one for submitting the code.
- we won't make client to wait for indefinite time when code is getting processed, as soon as
code is submitted, we will display a message that 'your code is in queue' and keep polling to
check if code execution is done or not.
- so to summarise, journey of this API will be to get the code in request, save it in DB against
a unique ID and get that unique ID in response to client. And spawn another thread to run the
code against given language compiler. Once the thread completes execution it will store output
in DB.
- then, client will keep polling against that submission_id to check if an output is generated.

###
---
###

```
code_output getResult(submission_id);
```
- client will poll using submission_id to this API to check if a code_output is generated and
stored in the DB. As soon as a result is found, it will be returned to the client, stopping
the polling process.
- this process will ensure that user is able to do other stuff on the website while output is
generated. screen is not hanged while waiting for the code output.
- FE connection with backend is broken as soon as a submission_id is generated, then repeatedly
FE will establish a connection to poll, and keep checking for output in background.
