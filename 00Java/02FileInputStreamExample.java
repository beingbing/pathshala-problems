import java.io.FileInputStream;
import java.io.IOException;

public class FileInputStreamExample {
    public static void main(String[] args) {
      // 1. establish a connection between file and program
      // 2. read one character at a time by making System read-call without loading 
      //    complete file in memory, similar to if you were reading from a byte-array
      //    one character at a time.
        try (FileInputStream fileInputStream = new FileInputStream("example.txt")) {
            int ch;
            while ((ch = fileInputStream.read()) != -1) {
                System.out.print(ch + " ");
                System.out.println((char) ch);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
