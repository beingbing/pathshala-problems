import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.IOException;

// Reason for Creation: The print(Object obj) method writes the string representation of an object
// to the stream without a newline character. This method is convenient for printing a wide range
// of data types, including primitives, objects, and strings.
// Use Case: Logging, reporting, or any scenario where different data types need to be printed
// in a human-readable format without a newline.

// with new-line we have `void println(Object obj)`

// for formatted string, we have - void printf(String format, Object... args)
public class PrintWriterPrintExample {
    public static void main(String[] args) {
        try (PrintWriter writer = new PrintWriter(new FileWriter("output.txt"))) {
            writer.print(123);   // Prints the integer 123
            writer.print(" ABC"); // Prints the string " ABC"
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
