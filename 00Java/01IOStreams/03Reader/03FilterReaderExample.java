import java.io.FilterReader;
import java.io.IOException;
import java.io.Reader;
import java.io.StringReader;

class UpperCaseReader extends FilterReader {
    protected UpperCaseReader(Reader in) {
        super(in);
    }

    @Override
    public int read() throws IOException {
        int c = super.read();
        return (c == -1 ? c : Character.toUpperCase((char) c));
    }
}

public class FilterReaderExample {
    public static void main(String[] args) {
        try (UpperCaseReader reader = new UpperCaseReader(new StringReader("hello, world!"))) {
            int ch;
            while ((ch = reader.read()) != -1) {
                System.out.print((char) ch);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
