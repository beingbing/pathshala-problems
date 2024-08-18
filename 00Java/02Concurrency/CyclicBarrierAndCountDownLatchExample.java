import java.util.concurrent.CountDownLatch;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;

public class CyclicBarrierAndCountDownLatchExample {
    
    private void removeLions() {
        System.out.println("Removing lions");
    }
    
    private void cleanPen() {
        System.out.println("Cleaning the pen");
    }
    
    private void putFood() {
        System.out.println("Put food for lions");
    }
    
    private void addLions() {
        System.out.println("Adding lions");
    }
    
    public void performTask(CountDownLatch latch, CyclicBarrier barrier) {
        try {
            removeLions();
            latch.countDown(); // meeting point for first barrier
            cleanPen();
            barrier.await(); // meeting point for second barrier
            putFood();
            barrier.await();
            addLions();
        } catch (Exception e) {
            System.out.println("exception is thrown");
        }
    }
    
    public static void main(String[] args) {
        ExecutorService service = Executors.newFixedThreadPool(4);
        
        CountDownLatch latch = new CountDownLatch(4);
        CyclicBarrier barrier = new CyclicBarrier(4, () -> System.out.println("*** involved in cleaning and preparing food"));
        // we created two CyclicBarrier because we needed to define a runnable once barried is breached
        
        try {
            CyclicBarrierExample manager = new CyclicBarrierExample();
            
            for (int i = 0; i < 4; i++)
                service.submit(() -> manager.performTask(latch, barrier));
        } finally {
            service.shutdown();
        }
    }
}
