import java.io.PipedReader;
import java.io.PipedWriter;
import java.io.IOException;

public class PipedReaderExample {
    public static void main(String[] args) {
        try {
            PipedWriter writer = new PipedWriter();
            PipedReader reader = new PipedReader(writer);

            Thread writerThread = new Thread(() -> {
                try {
                    writer.write("Hello from writer thread!");
                    writer.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            });

            Thread readerThread = new Thread(() -> {
                try {
                    int ch;
                    while ((ch = reader.read()) != -1) {
                        System.out.print((char) ch);
                    }
                    reader.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            });

            writerThread.start();
            readerThread.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
