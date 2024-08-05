import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

public class ReadOffsetExample {
    public static void main(String[] args) {
        byte[] buffer = new byte[10];
        try (InputStream is = new FileInputStream("example.txt")) {
            int bytesRead = is.read(buffer, 0, buffer.length);
            while (bytesRead != -1) {
                System.out.write(buffer, 0, bytesRead);
                System.out.println();
                bytesRead = is.read(buffer, 0, buffer.length);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
