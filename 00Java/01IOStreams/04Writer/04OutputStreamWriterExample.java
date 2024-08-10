import java.io.OutputStreamWriter;
import java.io.FileOutputStream;
import java.io.IOException;

public class OutputStreamWriterExample {
    public static void main(String[] args) {
        try (OutputStreamWriter writer = new OutputStreamWriter(new FileOutputStream("output.txt"), "UTF-8")) {
            writer.write("This text will be written in UTF-8 encoding.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
