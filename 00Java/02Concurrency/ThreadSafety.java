import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;

public class ThreadSafety {

    // private int sheepCount = 0;
    
    // private void incrementAndReport() {
    //     System.out.print((++sheepCount) + " "); // increment operator is not thread safe, read-write operations involved are not atomic
    // }
    // when thread safety needs to be ensured for a single variable, we can use atomic classes
    
    // In the original code using int, multiple threads could simultaneously read the 
    // value of sheepCount, increment it, and then write it back. Since these operations
    // are not atomic, this can lead to incorrect increments, where some increments might be lost.
    // AtomicInteger solves this by providing atomic methods like incrementAndGet(),
    // which ensures that the increment operation is done as a single, indivisible action.
    // This means that when one thread is incrementing the value, no other thread can
    // intervene until the increment is complete.
    
    // but still it didn't work and we got following output -
    // 7 5 6 2 1 8 4 10 9 3 
    // if you observe carefully, we fixed atomic increment, as there are no repeated numbers anymore.
    // but threads are still concurrent and anyone of them can give output before any other.
    // hence, now only the order of printing the number is not sequential.
    
    // so, we solved our initial problem of making operations on a variable thread safe but then 
    // we realized that we need to revisit our problem statement and tweak it according to our needs.
    // we do not only wanted atomic operations on a variable, we want to execute a group of
    // statements to be performed attomically, which means along with atomic operations on a variable
    // printing of new value of variable should also be attomic and should have been clubbed with
    // those operations. But AtomicInteger is not made for this.

    // private AtomicInteger sheepCount = new AtomicInteger(0);
    
    // private void incrementAndReport() {
    //     System.out.print(sheepCount.incrementAndGet() + " ");
    // }
    
    private int sheepCount = 0;
    
    private void incrementAndReport() {
        synchronized(this) { // this will execute a group of statements mutually exclusively and atomically for each thread
            System.out.print((++sheepCount) + " ");
        }
    }
    
    // another way of synchronizing and ensuring atomicity along with mutual exclusion during multi threading
    private synchronized void incrementAndReport() {
        System.out.print((++sheepCount) + " ");
    }
        
    public static void main(String[] args) {
        ExecutorService service = Executors.newFixedThreadPool(20);
        
        ThreadSafety manager = new ThreadSafety();

        try {
            for (int i = 0; i < 10; i++)
                service.submit(() -> manager.incrementAndReport());
        } finally {
            service.shutdown();
        }
        
        // Wait for all tasks to finish
        // while (!service.isTerminated()) {
            // Busy-wait or better use awaitTermination
        // }

        // Check final count
        // System.out.println("\nFinal sheep count: " + manager.sheepCount.get());
    }
}
