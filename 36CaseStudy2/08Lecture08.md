# Async Processing

One of the commonly used system design pattern in system architecture problems where heavy
processing is involved for meeting incoming request requirement is Async processing.

Why we switch to Async processing instead of conventional Synchronised processing ?
Conventional Synchronous processing will keep the request waiting until processing is done, which
will block the Client and it will look hanged hence giving bad user experience.

What does Async processing do differently ?
It decouples req/res cycle from actual processing task, by providing acknowledgment of receiving
the request in response and saving the requested task in DB with 'INIT' status.

Now, the stored process in DB will trigger a CDC (change data capture) event, which will pick the
request and insert it into a Service (Message) Broker, which is basically a queue holding all
the incoming requests, from which a pool of Threads (called Workers/Runners) working on incoming
requests independently but parallel will pick the request one by one and start working on the
requirements.

Once the processing is done, then final result is again stored by the Thread process in DB with
'Done' status. Then again this will emit a CDC event which will push the processed response into a
Broker queue. Which will then again picked up by a Worker and forwarded to Client.

Now, a processed reaching Client can happen in multiple following ways -
1. Short polling request from Client, will check status of stored request with high frequency. If
   the status is 'Done' then response with actual result is returned. (not recommended, as status
   check request can be large)
2. Long polling requests from Client. Same as Short polling but incoming status check requests have
   larger time gap between consequent requests. (always chosen over Short polling)
3. WebSocket will establish a Duplex channel between Client and Server, as soon as status 'Done'
   CDC event is triggered, Worker forwards the result via channel
4. SSE will itself send the response with actual result without Client requesting for it again.
   Initiated from Server end. (newest approach, most optimal)

Note: if an event is sent from Server to Client it is called SSE. If an event is sent from one
Server to another then it is called WebHook.


Client  ----------request---------->  Server
    A   <---------response----------
    |                                   |
    |                                   |
    |                                   |
    |                                   V
    -------------CDC-----------------  DB  ------CDC------> Broker ----INIT----> Worker
                                          <-----------------DONE----------------
