import java.io.StringReader;
import java.io.IOException;

public class StringReaderExample {
    public static void main(String[] args) {
        String input = "This is a test string.";
        try (StringReader reader = new StringReader(input)) {
            int ch;
            while ((ch = reader.read()) != -1) {
                System.out.print((char) ch);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
