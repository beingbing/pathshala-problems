import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.TimeUnit;

// this program will produce either if or else depending
// which thread acquire the lock first
public class LockExample {

    public static void printHello(Lock lock) {
        try {
            lock.lock();
            System.out.println("Hello after locking ");
        } finally {
            lock.unlock();
            System.out.println("leaving after unlocking");
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Lock lock = new ReentrantLock();
        
        new Thread(() -> printHello(lock)).start();
        
        // if (lock.tryLock()) {
        //     System.out.println("Entered after acquiring the lock!!");
        //     lock.unlock();
        //     System.out.println("Lock released now!!");
        // } else {
        //     System.out.println("unable to acquire the lock, won't try again!!");
        // }
        
        // another variant with more control
        if (lock.tryLock(3, TimeUnit.SECONDS)) {
            System.out.println("Entered after acquiring the lock!!");
            lock.unlock();
            System.out.println("Lock released now!!");
        } else {
            System.out.println("unable to acquire the lock, won't try again!!");
        }
    }
}
