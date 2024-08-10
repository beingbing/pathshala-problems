import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class BufferedWriterExample {
    public static void main(String[] args) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("output.txt"))) {
            writer.write("This is a large amount of text that would benefit from buffering.");
            writer.newLine();
            writer.write("BufferedWriter reduces the number of I/O operations.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
