import java.lang.Runnable;
import java.lang.Thread;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Future;
import java.util.concurrent.TimeoutException;
import java.util.concurrent.TimeUnit;

public class ExecutorServiceThreadPolling {
    
    private static int counter = 0;
    
    public static void main(String[] args) {
        
        final Thread mainThread = Thread.currentThread();
        
        ExecutorService service = Executors.newSingleThreadExecutor();
        
        try {
            Future<?> result = service.submit(() -> {
                for(int i = 0; i < 1_000_000_000; i++) counter++;
                // mainThread.interrupt(); // to wake up main thread
            });

            result.get(1, TimeUnit.SECONDS); // main thread went to sleep for atleast 1 second, waiting for result.
            System.out.println("Reached !!");
        } catch (InterruptedException e) {
            System.out.println("Thread woken up by interruption");
        } catch (ExecutionException e) {
            System.out.println("Execution exception is thrown");
        } catch (TimeoutException e) {
            System.out.println("TimeoutException is thrown0");
        } finally {
            service.shutdown();
        }
        
        System.out.println("finally reached: " + counter);
    }
}
