import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
import java.nio.CharBuffer;

public class ReadCharBufferExample {
    public static void main(String[] args) {
        CharBuffer buffer = CharBuffer.allocate(100);
        try (Reader reader = new FileReader("example.txt")) {
            reader.read(buffer);
            buffer.flip(); // Prepare the buffer for reading
            System.out.println(buffer.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
