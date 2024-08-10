import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.SequenceInputStream;

public class SequenceInputStreamExample {
    public static void main(String[] args) {
        ByteArrayInputStream inputStream1 = new ByteArrayInputStream("Hello 123 ".getBytes());
        ByteArrayInputStream inputStream2 = new ByteArrayInputStream("Samar!".getBytes());

      // Used when you need to read from multiple input streams sequentially as if they were one.
        try (SequenceInputStream sequenceInputStream = new SequenceInputStream(inputStream1, inputStream2)) {
            int ch;
            while ((ch = sequenceInputStream.read()) != -1) {
                System.out.print((char) ch);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
