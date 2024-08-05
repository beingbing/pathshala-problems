import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

public class SkipExample {
    public static void main(String[] args) {
        try (InputStream is = new FileInputStream("example.txt")) {
            is.skip(5); // Skip first 5 bytes
            int data = is.read();
            while (data != -1) {
                System.out.print((char) data);
                data = is.read();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
