# Process vs Thread

Before delving deep into our submission service, as it will be spun an independent thread to
execute our submission code, so lets first understand as why we went with this approach. Why we
chose to have a new thread instead of starting a completely new process, for this lets understand
more about Threads and Processes, and how an actual computer executes our code -

### Process -

Computer is a set of Pieces of hardware, with an OS managing them and running programs on them. Any
program that we want to run (example, Google Chrome) will be first given to OS, which will convert
the binary code stored in memory into a process and give it a spun and space in RAM. In order to
provide execution space, which is termed as PCB (Process Control Block) and contains metadata of
the process which contains, CPU understandable binary code, necessary data, heap and stack memory
chunk. all this is given to CPU and then a process starts.

In short, application which needs to be run, is converted into a PCB in RAM by OS and given to CPU,
which allots a Core and starts its execution, which is termed as a Process.

Now, assume that whenever an API receives a requests, a process starts. Which is a completely
independent entity.

### Thread -

A Thread is a lightweight process, that means, among threads; binary code, necessary data and heap
memory is shared. They are provided a separate context only in terms of stack memory which tracks
their execution progress. A Core can have numerous Threads, getting executed via parallelism
simultaneously by context switching. In which single core switches context among running threads
to complete all of them. This context switching can happen at any point in a Thread execution
cycle and is dependent on Core not on Threads. So, Threads do not have separate PCBs among
themselves, they all live in a single PCB, working on common Heap memory only distinguished by a
separate stack. Hence, they all have shared resources in Heap and are working on executing same
process binary code but with separate stack memory context.

### To make a decision between Process and Thread -
to understand what will you need, you can use below
parameters -
- **Core requirement and shared resources:** Ponder if the execution which needs to be done, will need
a separate PCB or an existing PCB can be used. If yes, then run in same Core by choosing Thread
otherwise start a process and give it to a new Core. But keep in mind, if a new Process is started
then it can not access anything from the process which started it.
- **speed and scheduling:** context switching between Threads is quick and fast as compared to context
switching between Processes.
- **data synchronisation and race condition:** Threads have everything shared among themselves except
stack memory, hence, they can interfere in each other's execution, and we will need to handle racing
condition for shared resources or need to establish synchronisation which makes handling threads
very complicated and bug prone.

example, every Tab of a Chrome Browser is a separate process.
