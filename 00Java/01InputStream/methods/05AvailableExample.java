import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

public class AvailableExample {
    public static void main(String[] args) {
        try (InputStream is = new FileInputStream("example.txt")) {
            System.out.println("Available bytes: " + is.available());
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
