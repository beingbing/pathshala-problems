import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.FileOutputStream;

public class PrintStreamExample {
    public static void main(String[] args) {
        // as DataOutputStream writes data after converting in bytes-array format which is not human readable
        // hence, this PrintStream was created to print Java Primitive-types as they are used in code.
        try (PrintStream ps = new PrintStream(new FileOutputStream("output.txt"))) {
            ps.println("Hello, World!");
            ps.printf("Number: %d%n", 123);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
