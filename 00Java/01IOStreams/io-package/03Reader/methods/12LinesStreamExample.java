import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.stream.Stream;

// Stream<String> lines() (Java 8+)
// This method returns a Stream of lines read from the input stream, allowing for efficient 
// processing of text using the Java Streams API.
// Processing large text files using functional programming techniques, such as filtering, 
// mapping, and collecting data from each line.
public class LinesStreamExample {
    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new FileReader("example.txt"))) {
            Stream<String> lines = reader.lines();
            lines.filter(line -> line.contains("important"))
                 .forEach(System.out::println);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
