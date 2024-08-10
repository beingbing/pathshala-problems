import java.io.FileWriter;
import java.io.IOException;

public class FileWriterExample {
    public static void main(String[] args) {
        try (FileWriter writer = new FileWriter("output.txt")) {
            writer.write("This text will be written to the file output.txt");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
