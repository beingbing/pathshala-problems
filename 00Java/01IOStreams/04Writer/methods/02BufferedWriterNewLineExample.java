import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

// Reason for Creation: The newLine() method writes a platform-dependent line separator to
// the stream. It abstracts away the differences between operating systems (e.g., \n on Unix/Linux, \r\n on Windows).
// Use Case: Writing text files or logs where new lines are needed, ensuring compatibility
// across different operating systems.
public class BufferedWriterNewLineExample {
    public static void main(String[] args) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("output.txt"))) {
            writer.write("First line");
            writer.newLine();  // Adds a new line based on the platform
            writer.write("Second line");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
