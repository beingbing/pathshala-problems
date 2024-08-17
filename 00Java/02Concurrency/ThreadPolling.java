public class ThreadPolling {
    
    private static int counter = 0;
    
    public static void main(String[] args) {
        
        final Thread mainThread = Thread.currentThread();
        
        new Thread(() -> {
            for(int i = 0; i < 1_000_000_000; i++) counter++;
            mainThread.interrupt(); // to wake up main thread
        }).start();
        
        // while(counter < 1_000_000_000) {
        //     System.out.println("Reached: " + counter);
        // }
        // implementing loop like this will tie up active CPU resources, that's a bad practice
        
        while(counter < 1_000_000_000) {
            System.out.println("Reached: " + counter);
            try {
                Thread.sleep(5_000); // sending main thread into deep sleep
                System.out.println("woke up from sleep");
            } catch (InterruptedException e) {
                System.out.println("Thread woken up by interruption");
            }
        }
        
        System.out.println("finally reached: " + counter);
    }
}
