import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.AsynchronousFileChannel;
import java.nio.channels.CompletionHandler;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

public class AsyncFileChannelWithCompletionHandler {

    public static void main(String[] args) {
        Path filePath = Paths.get("example.txt");

        // Writing to a file asynchronously using CompletionHandler
        try (AsynchronousFileChannel fileChannel = AsynchronousFileChannel.open(filePath, StandardOpenOption.WRITE, StandardOpenOption.CREATE)) {
            ByteBuffer buffer = ByteBuffer.allocate(1024);
            buffer.put("Hello, this is an example of writing asynchronously using CompletionHandler.".getBytes());
            buffer.flip();

            fileChannel.write(buffer, 0, buffer, new CompletionHandler<Integer, ByteBuffer>() {
                @Override
                public void completed(Integer result, ByteBuffer attachment) {
                    System.out.println("Bytes written: " + result);
                }

                @Override
                public void failed(Throwable exc, ByteBuffer attachment) {
                    System.out.println("Write operation failed: " + exc.getMessage());
                }
            });

            // Perform some other tasks while the file is being written

        } catch (IOException e) {
            e.printStackTrace();
        }

        // Reading from a file asynchronously using CompletionHandler
        try (AsynchronousFileChannel fileChannel = AsynchronousFileChannel.open(filePath, StandardOpenOption.READ)) {
            ByteBuffer buffer = ByteBuffer.allocate(1024);

            fileChannel.read(buffer, 0, buffer, new CompletionHandler<Integer, ByteBuffer>() {
                @Override
                public void completed(Integer result, ByteBuffer attachment) {
                    System.out.println("Bytes read: " + result);
                    attachment.flip();
                    while (attachment.hasRemaining()) {
                        System.out.print((char) attachment.get());
                    }
                }

                @Override
                public void failed(Throwable exc, ByteBuffer attachment) {
                    System.out.println("Read operation failed: " + exc.getMessage());
                }
            });

            // Perform some other tasks while the file is being read

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
