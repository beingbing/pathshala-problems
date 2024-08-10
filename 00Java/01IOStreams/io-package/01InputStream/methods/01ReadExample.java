import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

public class ReadExample {
    public static void main(String[] args) {
        try (InputStream is = new FileInputStream("example.txt")) {
            int data = is.read(); // Reads the next byte of data from the input stream.
                                  // Returns -1 if the end of the stream is reached.
            while (data != -1) {
                System.out.print((char) data);
                data = is.read();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
