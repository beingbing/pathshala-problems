import java.io.OutputStreamWriter;
import java.io.FileOutputStream;
import java.io.IOException;

// Reason for Creation: The getEncoding() method returns the name of the character encoding being used by the
// OutputStreamWriter. This is important when you need to know or verify the encoding used to write data,
// especially in internationalized applications.
// Use Case: Ensuring that text is written in the correct encoding, particularly when dealing with multiple
// languages or external systems.
public class OutputStreamWriterGetEncodingExample {
    public static void main(String[] args) {
        try (OutputStreamWriter writer = new OutputStreamWriter(new FileOutputStream("output.txt"), "UTF-8")) {
            writer.write("Hello, World!");
            System.out.println("Encoding used: " + writer.getEncoding());  // Outputs: "Encoding used: UTF-8"
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
