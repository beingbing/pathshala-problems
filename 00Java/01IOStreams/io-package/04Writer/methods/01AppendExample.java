import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

// Reason for Creation: This method appends a character sequence (like a String or 
// StringBuilder) to the writer. It's part of the Appendable interface, allowing 
// more flexible and intuitive string concatenation.
// Use Case: Appending strings or character sequences to a file or stream, useful 
// for building text documents dynamically.
// it has two more variations -
// `Writer append(CharSequence csq, int start, int end)` - writer.append("Hello, Beautiful World!", 7, 16);  // Appends "Beautiful"
// `Writer append(char c)` -  writer.append('A');
public class AppendExample {
    public static void main(String[] args) {
        try (Writer writer = new FileWriter("output.txt", true)) {
            writer.append("Hello, ");
            writer.append("World!");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
