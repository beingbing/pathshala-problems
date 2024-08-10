import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

// String readLine();
// This method reads a line of text from the input stream. A line is considered to be terminated 
// by any one of a line feed (\n), a carriage return (\r), or a carriage return followed immediately 
// by a line feed. (like, what normally happens in a text document.)
// Efficiently reading lines of text, such as from a file or user input, where each line represents a distinct data entry.
public class ReadLineExample {
    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new FileReader("example.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
