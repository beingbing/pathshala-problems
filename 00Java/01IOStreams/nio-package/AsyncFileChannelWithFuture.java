import java.io.File;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.nio.ByteBuffer;
import java.nio.channels.AsynchronousFileChannel;
import java.nio.file.StandardOpenOption;
import java.util.concurrent.Future;
import java.util.concurrent.ExecutionException;

// AsynchronousFileChannel in Java NIO 2 provides the ability to perform file I/O operations asynchronously, 
// meaning the file operations can be performed without blocking the calling thread.

public class AsyncFileChannelWithFuture {
  public static void main(String[] args) {
    Path filePath = Paths.get("source.txt");

    // Writing to a file asynchronously using Future
    try (AsynchronousFileChannel writeChannel = AsynchronousFileChannel.open(filePath, StandardOpenOption.WRITE, StandardOpenOption.CREATE)) {
        ByteBuffer buffer = ByteBuffer.allocate(1024);
        buffer.put("Hello, this is an example of writing asynchronously using Future.".getBytes());
        buffer.flip();

        Future<Integer> future = writeChannel.write(buffer, 0);
        
        // Perform some other tasks while the file is being written
        while (!future.isDone()) {
            System.out.println("Writing to file...");
        }

        System.out.println("Bytes written: " + future.get());
    } catch (IOException | InterruptedException | ExecutionException e) {
        e.printStackTrace();
    }

    // Reading from a file asynchronously using Future
    try (AsynchronousFileChannel readChannel = AsynchronousFileChannel.open(filePath, StandardOpenOption.READ)) {
      ByteBuffer buffer = ByteBuffer.allocate(1024);
      Future<Integer> result = readChannel.read(buffer, 0); // Reading data via `Future`
      // Second parameter is the byte position in the file to start reading from.
      while (!result.isDone()) {
        System.out.println("Reading file asynchronously...");
      }

      Integer bytesRead = result.get();
      System.out.println("Read " + bytesRead + " bytes from the file.");

      buffer.flip();
      while (buffer.hasRemaining()) {
        System.out.print((char) buffer.get());
      }

    } catch (IOException | InterruptedException | ExecutionException e) {
      e.printStackTrace();
    }
  }
}
