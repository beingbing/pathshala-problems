import java.lang.Runnable;
import java.lang.Thread;
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;

public class Main {
	public static void ExecutorServiceMultiThreading(String[] args) {
	    Runnable printInventory = () -> System.out.println("Printing inventory");
	    Runnable printRecords = () -> {
	        for (int i = 0; i < 3; i++) {
	            System.out.println("Printing record: " + i);
	        }
	    };
	    
	    Runnable printContext = () -> System.out.println("Printing context");
	    
	    ExecutorService service = Executors.newFixedThreadPool(5);
	    
		try {
		    System.out.println("Start");
    		service.execute(printInventory);
    		service.execute(printRecords);
    		service.execute(printContext);
    		System.out.println("end");
		} catch (RejectedExecutionException ex) { // when ExecutorService is shutdown and we try to assign new tasks
		    System.out.println("new tasks attempted to get executed when already service is starting shutting down");
		} finally {
		    service.shutdown(); // if not for this, application will keep on running without doing anything
		    // do not allow any new task to be scheduled
		    // `isShutDown()` - true : if shut down triggered (service might still be working on ongoing tasks)
		    // `isTerminated()` - true - once all active tasks after shutting down also completes
		    // service.shutdownNow(); // to shutdown instantly and stop already tasks as well
		}
	}
}
