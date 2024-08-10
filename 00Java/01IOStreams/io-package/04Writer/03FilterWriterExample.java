import java.io.FilterWriter;
import java.io.IOException;
import java.io.Writer;

// Custom FilterWriter that converts all characters to lowercase
public class LowerCaseWriter extends FilterWriter {

    protected LowerCaseWriter(Writer out) {
        super(out);
    }

    @Override
    public void write(int c) throws IOException {
        super.write(Character.toLowerCase(c));
    }

    @Override
    public void write(char[] cbuf, int off, int len) throws IOException {
        for (int i = 0; i < len; i++) {
            cbuf[off + i] = Character.toLowerCase(cbuf[off + i]);
        }
        super.write(cbuf, off, len);
    }

    @Override
    public void write(String str, int off, int len) throws IOException {
        super.write(str.toLowerCase(), off, len);
    }
}

public class FilterWriterExample {
    public static void main(String[] args) {
        try (Writer writer = new LowerCaseWriter(new FileWriter("output.txt"))) {
            writer.write("Hello, World!");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
