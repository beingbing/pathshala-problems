import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.IOException;

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
