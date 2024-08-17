# Introduction
CPU interaction with external reading/writing sources like DB, network and hard-disk tends to be slow and time-consuming as compared to internal processes. As a result, early systems seemed significantly slow, almost felt frozen when performing I/O operations, leading to inefficient utilization of CPU resource. Because, The CPU often spent considerable time waiting for these I/O operations to complete, rather than executing other tasks.

To address this issue, multi-threading allows a program to divide its execution into multiple concurrent threads. So, instead of blocking CPU main execution thread, we can spin up a side thread that can run independently. This enables the CPU to perform other computations or handle additional I/O requests while waiting for one operation to complete. This significantly improves overall performance and resource utilization by reducing idle CPU time and allowing for parallel execution of tasks.

# Threads
A thread is a scheduled execution of a task or group of tasks. After a thread is created, it is in one of six states.
- NEW: created but not started (`start()` will make this state to transition into RUNNABLE)
- RUNNABLE: running or able to run (additional resource requested - BLOCKED, `wait()` - WAITING, `sleep()` - TIMED_WAITING)
- BLOCKED: waiting to enter synchronized block ( resource granted - RUNNABLE)
- WAITING: waiting indefinetly to be notified (`notify()` - RUNNABLE)
- TIMED_WAITING: waiting a specified time (sleep time completed or Interrupted - RUNNABLE)
- TERMINATED: task completed (`run()` method completes or uncaught exception is thrown)

Use `getState()` to know current status of a Thread.

# Process
A process is a group of threads executing in a shared environment. By shared environment, we mean that the threads in the same process share the same memory space and can communicate directly with one another. By shared memory, we mean static variables, local variables passed to a thread and object instances. The property of executing multiple threads and processes at the same time is called concurrency.

How the system decide what to execute when there are more threads available than CPUs ?
A thread-scheduler employs a scheduling process to decide on which thread priority should be given.

# Polling
Polling is the process of intermittently checking data at some fixed interval. Used when one thread needs to wait for the results of another thread to proceed.

# ExecutorService / Executor
To better manage a pool of threads and reduce the overhead associated with thread creation and destruction. Executor is a simple interface that decouples task submission from task execution. ExecutorService provides more advanced functionalities like thread pools, task scheduling, and controlled shutdown. It has 3 implementation -
- `ExecutorService newSingleThreadExecutor()` - 
- `ExecutorService newCachedThreadPool()` - creates thread pool that creates new threads as needed but reuses previously constructed threads when they are available.
- `ExectorService newFixedThreadPool(int)` - creates thread pool that reuses fixed number of threads operating off shared unbounded queue.

Primary advantage it has over initiating and executing a Thrad manually is it has `submit()` which accepts `Callable` and return `Future`.

# ScheduledExecutorService
It allows tasks to be scheduled for future execution. Has 4 main methods -
- `<V> ScheduledFuture<V> schedule(Callable<V> callable, long delay, TimeUnit unit)`
- `ScheduledFuture<?> schedule(Runnable<V> command, long delay, TimeUnit unit)`
- `ScheduledFuture<?> scheduleAtFixedRate(Runnable command, long initialDelay, long period, TimeUnit unit)`
- `ScheduledFuture<?> scheduleWithFixedDelay(Runnable command, long initialDelay, long delay, TimeUnit unit)`

`ScheduledFuture` interface is identical to `Future` interface except it has `getDelay()`

Also, it has 2 implementation -
- `ScheduledExecutorService newSingleThreadScheduledExecutor()`
- `ScheduledExecutorService newScheduledThreadPool(int)`
