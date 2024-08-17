import java.lang.Runnable;
import java.lang.Thread;

public class Main {
	public static void main(String[] args) {
	    Runnable printInventory = () -> System.out.println("Printing inventory");
	    Runnable printRecords = () -> {
	        for (int i = 0; i < 3; i++) {
	            System.out.println("Printing record: " + i);
	        }
	    };
	    
	    Runnable printContext = () -> System.out.println("Printing context");
	    
	    
		System.out.println("Start");
		new Thread(printInventory).start();
		new Thread(printRecords).start();
		new Thread(printContext).start();
		System.out.println("end");
	}
}
