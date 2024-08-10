import java.io.CharArrayWriter;
import java.io.IOException;

public class CharArrayWriterExample {
    public static void main(String[] args) {
        CharArrayWriter writer = new CharArrayWriter();
        writer.write("This is an example of CharArrayWriter.");
        char[] result = writer.toCharArray();
        System.out.println(result); // Outputs the accumulated text as a char array
    }
}
