import java.io.PipedWriter;
import java.io.PipedReader;
import java.io.IOException;

public class PipedWriterExample {
    public static void main(String[] args) {
        try (PipedWriter writer = new PipedWriter(); PipedReader reader = new PipedReader(writer)) {
            Thread writerThread = new Thread(() -> {
                try {
                    writer.write("Hello from writer thread!");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            });

            Thread readerThread = new Thread(() -> {
                try {
                    int data;
                    while ((data = reader.read()) != -1) {
                        System.out.print((char) data);
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            });

            writerThread.start();
            readerThread.start();

            writerThread.join();
            readerThread.join();
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
