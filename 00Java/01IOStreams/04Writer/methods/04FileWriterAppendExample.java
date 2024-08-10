import java.io.FileWriter;
import java.io.IOException;

// Method: Constructors that specify the file and append mode
// Reason for Creation: The FileWriter class provides constructors that allow specifying whether
// the writer should append to the file or overwrite it. This is particularly useful for log files
// or other scenarios where data should be added to the end of a file.
// Use Case: Writing to files where either appending or overwriting behavior is required
public class FileWriterAppendExample {
    public static void main(String[] args) {
        try (FileWriter writer = new FileWriter("output.txt", true)) { // Appends to the file
            writer.write("This will be appended to the file.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
