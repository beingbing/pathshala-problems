# Code submission flow

> Note: In discussions, if the interviewer requests emphasis on a specific part of the
> architecture, prioritize that. Otherwise, begin with what you're confident about.

In discussion of submission service -

<samp> ~~we spawn 1 thread/submission in the same machine for execution.~~ </samp>

Q. Is Thread a good idea, does it have a downside ?

A. As all spawn Threads share memory allocated to the parent process. Thus, Threads do not have
ability of independent and isolated execution. so if one thread goes haywire and consumes excessive
memory, it affects others, leading to potential runtime errors. Hence, using processes for running
submitted code is more reliable and preferable.

<samp>- We will spawn 1 process/submission in the same machine for execution</samp>

But, process only have independent execution ability. They are not isolated, as multiple processes
can modify same document at a given time, As FS is shared among processes. So, to be exclusively
isolated, every process needs to be on a separate machine. But, we are accepting 30 req/sec, hence
we will need 30 machines each second, which is too far fetched. Hence, we can go with Virtualization.
Whose better alternative is Containerisation.

<samp>- We will spawn 1 container/process for execution</samp>

Q. Will we run 30 containers/second on a single machine ?

A. Considering memory, each submission is 512 MB (0.5 GB), and a machine typically has 16 GB RAM.
Therefore, a single machine can handle 30 submissions simultaneously.

However, considering CPU usage, each machine has 8 cores. and assuming each process takes 1 second,
processing 30 submissions would require at least 4 seconds. Hence, to handle 30 submissions/second,
we would need at least 4 machines. And we can manage this setup using Kubernetes.

<samp>- We will have Kubernetes cluster of atleast 4 machines</samp>

Q. Will we create Container for a submission as soon as it is received ?

A. Creating 30 containers per second is impractical due to the time-consuming nature of it. Instead,
we'll first store incoming requests in DB. These requests will then be placed in a broker queue.
Runners/workers will pick up requests from this queue once they have finished handling their current
tasks and are ready to create new containers. Workers will save completed tasks back in DB.

<samp>- Kafka Queue and Consumers to Create Containers Asynchronously</samp>

Now, our current Architecture is scalable, reliable and highly available.

Q. Will we have only 1 server accepting the requests ?

A. The server accepts requests, stores them in the database, and returns a generated ID. To handle
30 requests per second during peak times, we need at least 4 server replicas running concurrently,
assuming an 8-core machine where all cores are dedicated to the server process. A load balancer
will distribute the requests evenly among these replicas using a Round Robin approach.

<samp>- Load Balancer manage 4 server replicas with Round Robin approach</samp>

So, here we discussed, code submission, processing, generating results and storing it back in DB.
Next we will discuss, how stored calculated result can be sent back to the requester.
