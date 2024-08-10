import java.io.ByteArrayOutputStream;
import java.io.IOException;

public class ByteArrayOutputStreamExample {
    public static void main(String[] args) {
        try (ByteArrayOutputStream baos = new ByteArrayOutputStream()) {
            baos.write("Hello, Samar!".getBytes());
            byte[] byteArray = baos.toByteArray();
            System.out.println(new String(byteArray)); // Prints "Hello, World!"
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
