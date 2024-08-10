import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;

// Checks whether the stream is ready to be read. A stream is ready if the 
// read() method can return without blocking. This is particularly useful 
// in non-blocking I/O operations.
// Use Case: Checking if data is available before attempting to read, especially 
// in interactive applications.
public class ReadyExample {
    public static void main(String[] args) {
        try (Reader reader = new FileReader("example.txt")) {
            if (reader.ready()) {
                int ch;
                while ((ch = reader.read()) != -1) {
                    System.out.print((char) ch);
                }
            } else {
                System.out.println("Stream not ready for reading.");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
