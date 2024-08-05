import java.io.FilterOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.FileOutputStream;

public class FilterOutputStreamExample extends FilterOutputStream {

    public FilterOutputStreamExample(OutputStream out) {
        super(out);
    }

    @Override
    public void write(int b) throws IOException {
        super.write(Character.toUpperCase(b));
    }

    public static void main(String[] args) {
        try (OutputStream os = new FilterOutputStreamExample(new FileOutputStream("output.txt"))) {
            os.write("Hello, Sam!".getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
