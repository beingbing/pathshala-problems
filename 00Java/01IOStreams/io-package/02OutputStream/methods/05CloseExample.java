import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

public class CloseExample {
    public static void main(String[] args) {
        OutputStream os = null;
        try {
            os = new FileOutputStream("example.txt");
            os.write("Hello, World!".getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (os != null) {
                try {
                    os.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
