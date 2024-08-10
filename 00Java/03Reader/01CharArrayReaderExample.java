import java.io.CharArrayReader;
import java.io.IOException;

public class CharArrayReaderExample {
    public static void main(String[] args) {
        char[] chars = "Hello, world!".toCharArray();
        try (CharArrayReader reader = new CharArrayReader(chars)) {
            int ch;
            while ((ch = reader.read()) != -1) {
                System.out.print((char) ch);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
