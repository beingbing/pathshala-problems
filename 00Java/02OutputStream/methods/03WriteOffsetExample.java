import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

public class WriteOffsetExample {
    public static void main(String[] args) {
        byte[] data = "Hello, World!".getBytes();
        try (OutputStream os = new FileOutputStream("example.txt")) {
            os.write(data, 7, 5); // Writes "World"
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
