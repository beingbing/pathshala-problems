import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.IOException;

// designed to provide methods for writing formatted text. It includes methods for 
// printing primitive types, objects, and strings with optional automatic flushing.
// It's a commonly used class for writing text data with a variety of formatting options.
//  Writing formatted output, like logs, reports, or console output, where different
// data types need to be written in a human-readable format.
public class PrintWriterExample {
    public static void main(String[] args) {
        try (PrintWriter writer = new PrintWriter(new FileWriter("output.txt"))) {
            writer.println("Hello, World!");
            writer.printf("The value of pi is approximately %.2f", Math.PI);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
