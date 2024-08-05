import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;

public class MarkExample {
    public static void main(String[] args) {
        byte[] data = "Hello, World!".getBytes();
        try (InputStream is = new ByteArrayInputStream(data)) {
            System.out.print((char) is.read()); // Read 'H'
            is.mark(10); // Mark this position with how many bytes you want to read from this position
            for (int i = 0; i < 5; i++) {
                System.out.print((char) is.read());
            }
            is.reset(); // Reset to marked position
            for (int i = 0; i < 5; i++) {
                System.out.print((char) is.read());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
