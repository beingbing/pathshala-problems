import java.io.IOException;
import java.io.PushbackReader;
import java.io.StringReader;

public class PushbackReaderExample {
  // Extends FilterReader to allow "pushing back" or "unreading" characters, which can 
  // be useful for parsers that need to read ahead but might need to return characters to the stream.
    public static void main(String[] args) {
        String input = "abcde";
        try (PushbackReader reader = new PushbackReader(new StringReader(input))) {
            int ch = reader.read();
            if ((char) ch == 'a') {
                System.out.println("Found 'a', pushing it back");
                reader.unread(ch);
            }

            while ((ch = reader.read()) != -1) {
                System.out.print((char) ch);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
