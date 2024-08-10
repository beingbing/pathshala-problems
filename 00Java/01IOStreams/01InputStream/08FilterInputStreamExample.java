import java.io.FilterInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.ByteArrayInputStream;

//  To provide a base class for creating input stream filters.
public class CapitalizingInputStream extends FilterInputStream {

    protected CapitalizingInputStream(InputStream in) {
        super(in);
    }

    @Override
    public int read() throws IOException {
        int c = super.read();
        if (c == -1) {
            return -1;
        }
        return Character.toUpperCase(c);
    }

    @Override
    public int read(byte[] b, int off, int len) throws IOException {
        int result = super.read(b, off, len);
        if (result == -1) {
            return -1;
        }
        for (int i = off; i < off + result; i++) {
            b[i] = (byte) Character.toUpperCase((char) b[i]);
        }
        return result;
    }

    public static void main(String[] args) {
        String input = "This is a test.";
        InputStream originalStream = new ByteArrayInputStream(input.getBytes());
        try (InputStream capitalizingStream = new CapitalizingInputStream(originalStream)) {
            int c;
            while ((c = capitalizingStream.read()) != -1) {
                System.out.print((char) c);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
