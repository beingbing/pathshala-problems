import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

public class WriteByteArrayExample {
    public static void main(String[] args) {
        byte[] data = "Hello, World!".getBytes();
        try (OutputStream os = new FileOutputStream("example.txt")) {
            os.write(data);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
