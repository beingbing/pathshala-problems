import java.io.OutputStreamWriter;
import java.io.FileOutputStream;
import java.io.IOException;

// It is essential for writing text data to any output stream, like network connections or binary files,
// where encoding is crucial, such as UTF-8 or ISO-8859-1.
public class OutputStreamWriterExample {
    public static void main(String[] args) {
        try (OutputStreamWriter writer = new OutputStreamWriter(new FileOutputStream("output.txt"), "UTF-8")) {
            writer.write("This text will be written in UTF-8 encoding.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
