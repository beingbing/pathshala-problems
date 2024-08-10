import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

// Reason for Creation: it flushes the stream, ensuring that all buffered data is written to the
// underlying device. It is crucial for writers that buffer data (e.g., BufferedWriter) to ensure
// that data is not stuck in the buffer and is written out promptly.
// Use Case: Ensuring that all data is written out, especially in scenarios where the writer is closed
// immediately after writing, or when the data needs to be visible to readers before the stream is closed.
public class FlushExample {
    public static void main(String[] args) {
      // Flushes the output stream and forces any buffered output bytes to be written out.
        try (OutputStream os = new BufferedOutputStream(new FileOutputStream("example.txt"))) {
            os.write("Hello, World!".getBytes());
            os.flush(); // Ensure data is written to file
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
