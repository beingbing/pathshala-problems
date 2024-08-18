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

# Thread safety
Ensuring that threads do not interfere with each other's results and lead to wrong results. For that we limit or organize access available to data for threads. For this tools availabe in Java are -
- java.util.concurrent.atomic package for making operations on a variable atomic
- A monitor/locking-system that support mutual exclusion on a group of commands or methods

Two ways to implement locking-system are -
- using `synchroized` keyword on a method/object wrapping a group of commands (implicit monitor lock)
- using `ReentrantLock` object wrapping a group of commands

### Note:
1. always synchronize/monitor the execution of threads, if implemented at the time of the thread creation, then it won't work.
2. The object on which the lock is applied should be accessible to all the threads.
3. synchroized keyword makes thread BLOCKED and let them wait, but what if we want the Thread to perform some other task and not stay blocked/waiting. That's why `ReentrantLock` is preferred in that case, as it gives us more control over threads execution process and mutual exclusion.

### Reentrancy
It is a property of locks where the thread that currently holds the lock can re-enter the same lock without getting blocked. The lock keeps track of how many times the same thread has acquired it, and the thread must release the lock the same number of times to fully unlock it.

# CyclicBarrier
It is a synchronization facilitator that allows a set of threads to wait for each other to reach a common barrier point. It is used in scenarios where you have multiple threads performing parallel tasks, and you want them to reach a certain point before any of them proceeds further. Once all participating threads have reached the barrier, the barrier is "broken," and all threads are released to continue their execution. It can take an optional `Runnable` task that is executed once per barrier point, after the last thread reaches the barrier but before the threads are released

It is called "Cyclic" because of reusability. You can define multiple such barriers, once a barrier is released, another can be worked on. If you want a one-time use synchronization mechanism then go with `CountDownLatch`.

# Concurrent Collection
In-memory information holding data-structures interaction with concurrent threads may have Memory Consistency errors. They occur due to the complex interaction between threads, the CPU, and memory, particularly when optimizing compilers and hardware updation optimizations come into play. Concurrent Collections use data synchronization techniques, such as volatile variables, locks, or other low-level concurrency primitives to prevent issues that arise from these CPU/compiler instruction reordering, caching, and visibility of updates across threads.

We should use a concurrent collection whenever multiple threads modify a collection outside a synchronized block even if we do not expect a concurrency problem. List of Classes are -
- `ConcurrentHashMap` - a thread-safe alternative to HashMap that allows high concurrency without locking the entire map.
- `CopyOnWriteArrayList` - a thread-safe alternative to ArrayList for scenarios where reads are more frequent than writes.
- `CopyOnWriteArraySet` - a thread-safe alternative to HashSet for scenarios where reads are more common than writes.
- `ConcurrentSkipListMap` - a thread-safe, sorted map with better scalability than TreeMap in a concurrent environment.
- `ConcurrentSkipListSet` - a thread-safe, sorted set with better scalability than TreeSet in a concurrent environment.
- `LinkedBlockingQueue` - a thread-safe, blocking queue that can be bounded or unbounded.
- `ConcurrentLinkedQueue` - a thread-safe, unbounded, non-blocking queue for high-concurrency environments
- `DelayQueue` - a thread-safe, unbounded blocking queue that holds elements until a delay period has expired.
- `PriorityBlockingQueue` - a thread-safe, unbounded blocking queue that orders elements according to their natural ordering or a provided comparator.
- `ArrayBlockingQueue` - a thread-safe, bounded blocking queue with a fixed capacity.

To obtain synchronized (thread-safe) versions of existing non-concurrent collection objects. Use below methods -
- `public static <T> Collection<T> synchronizedCollection(Collection<T> c)`
- `public static <T> List<T> synchronizedList(List<T> list)`
- `public static <T> Set<T> synchronizedSet(Set<T> s)`
- `public static <T> SortedSet<T> synchronizedSortedSet(SortedSet<T> s)`
- `public static <K, V> Map<K, V> synchronizedMap(Map<K, V> m)`
- `public static <K, V> SortedMap<K, V> synchronizedSortedMap(SortedMap<K, V> m)`
- `public static <K,V> NavigableMap<K,V> synchronizedNavigableMap(NavigableMap<K,V> m)`
- `public static <T> NavigableSet<T> synchronizedNavigableSet(NavigableSet<T> s)`

# Liveness
An application's ability to execute a process on time. Threading problems which can impact Liveness are -

### Deadlock
Deadlock happens when two or more threads are blocked forever, each waiting for the other to release a resource they need. Thread A locks Resource 1 and waits for Resource 2, while Thread B locks Resource 2 and waits for Resource 1. Neither thread can proceed.

### Starvation
Thread starvation occurs when a thread is perpetually denied access to resources because other threads are constantly taking the resources it needs.

### Livelock
Livelock is similar to deadlock, but instead of being stuck permanently, the threads keep changing their state in response to each other, but they still cannot make progress. Two threads keep yielding to each other, thinking the other will make progress, but both are stuck in a loop of yielding. They keep running but are not doing any useful work.

# Parallel Streams
A stream in Java is a sequence of elements supporting sequential and parallel aggregate operations. Parallel streams are a way to parallelize stream operations, allowing operations on collections to be executed simultaneously across multiple threads.

### Create a parallel stream
- Create a parallel stream from a collection using `parallelStream()`
```java
List<Integer> list = Arrays.asList(1, 2, 3, 4, 5);
list.parallelStream().forEach(System.out::println);
```
- Convert a sequential stream to a parallel stream using `stream().parallel()`
```java
List<Integer> list = Arrays.asList(1, 2, 3, 4, 5);
list.stream().parallel().forEach(System.out::println);
```
