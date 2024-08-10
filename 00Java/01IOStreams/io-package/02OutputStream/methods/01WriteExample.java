import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

public class WriteExample {
    public static void main(String[] args) {
        try (OutputStream os = new FileOutputStream("example.txt")) {
            os.write('H');
            os.write('e');
            os.write('l');
            os.write('l');
            os.write('o');
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
