public class DaemonThread {
    public static void pause() {
        try {
            Thread.sleep(5_000);
            System.out.println("woke up from sleep");
        } catch (InterruptedException ex) {
            System.out.println("Thread woken up by interruption");
        }
    }
    
    public static void main(String[] args) {
        var job = new Thread(() -> pause()); // by default user-defined threads are not daemon threads
        // job.setDaemon(true); // main thread do not wait for daemon thread to finish and exits
        System.out.println("1: " + job.getState());
        job.start(); // state = NEW
        System.out.println("2: " + job.getState()); // state = RUNNABLE
        System.out.println("method finished");
        System.out.println("3: " + job.getState()); // state = TIMED_WAITING
    }
}
