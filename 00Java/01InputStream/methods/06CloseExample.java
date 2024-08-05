import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

public class CloseExample {
    public static void main(String[] args) {
        InputStream is = null;
        try {
            is = new FileInputStream("example.txt");
            int data = is.read();
            while (data != -1) {
                System.out.print((char) data);
                data = is.read();
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (is != null) {
                try {
                    is.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
