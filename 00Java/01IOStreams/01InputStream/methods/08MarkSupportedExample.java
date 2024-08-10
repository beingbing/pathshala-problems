import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.io.IOException;

public class MarkSupportedExample {
    public static void main(String[] args) {
        byte[] data = "Hello, World!".getBytes();
        try (InputStream is = new ByteArrayInputStream(data)) {
            System.out.println("Mark supported: " + is.markSupported());
            if (is.markSupported()) {
                is.mark(10);
                for (int i = 0; i < 5; i++) {
                    System.out.print((char) is.read());
                }
                is.reset();
                for (int i = 0; i < 5; i++) {
                    System.out.print((char) is.read());
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
