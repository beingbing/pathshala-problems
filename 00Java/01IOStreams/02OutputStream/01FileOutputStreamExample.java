import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

public class FileOutputStreamExample {
    public static void main(String[] args) {
        String data = "Hello, World!";
        try (OutputStream os = new FileOutputStream("output.txt")) {
            os.write(data.getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
