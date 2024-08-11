import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.Pipe;

public class NioPipeExample {

    public static void main(String[] args) throws IOException {
        // Create a new Pipe
        Pipe pipe = Pipe.open();

        // Create a thread to write data to the pipe
        Thread writerThread = new Thread(() -> {
            try {
                Pipe.SinkChannel sinkChannel = pipe.sink();
                ByteBuffer buffer = ByteBuffer.allocate(64);

                buffer.clear();
                buffer.put("Hello, this is a message from the writer thread.".getBytes());

                buffer.flip();
                while (buffer.hasRemaining()) {
                    sinkChannel.write(buffer);
                }
                System.out.println("Message sent by the writer thread.");
            } catch (IOException e) {
                e.printStackTrace();
            }
        });

        // Create a thread to read data from the pipe
        Thread readerThread = new Thread(() -> {
            try {
                Pipe.SourceChannel sourceChannel = pipe.source();
                ByteBuffer buffer = ByteBuffer.allocate(64);

                int bytesRead = sourceChannel.read(buffer);
                while (bytesRead > 0) {
                    buffer.flip();
                    while (buffer.hasRemaining()) {
                        System.out.print((char) buffer.get());
                    }
                    buffer.clear();
                    bytesRead = sourceChannel.read(buffer);
                }
                System.out.println("\nMessage received by the reader thread.");
            } catch (IOException e) {
                e.printStackTrace();
            }
        });

        // Start both threads
        writerThread.start();
        readerThread.start();

        // Wait for both threads to finish
        try {
            writerThread.join();
            readerThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
