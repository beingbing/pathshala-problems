import java.io.StringWriter;

public class StringWriterExample {
    public static void main(String[] args) {
        StringWriter writer = new StringWriter();
        writer.write("Hello, World!");
        writer.write(" This is a StringWriter example.");
        String result = writer.toString();
        System.out.println(result); // Outputs: "Hello, World! This is a StringWriter example."
    }
}
