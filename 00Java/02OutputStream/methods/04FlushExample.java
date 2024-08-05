import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

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
