import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.IOException;

public class BufferedInputStreamExample {
    public static void main(String[] args) {
      // Reading data from an outside input source (like file) using traditional FileInputStream alone
      // would make a System call everytime read() is invoked, which is expensive in terms of time.
      // Hence we wrote a wrapper which kept an in-memory byte-array (named it buffer) and filled it
      // completely in one go by reading larger chunks of data into memory. We termed this action as
      // data buffering. As a result, subsequent read() do not make System calls until byte-array
      // is exhausted. Thus, it was an optimization.
        try (BufferedInputStream bis = new BufferedInputStream(new FileInputStream("example.txt"))) {
            int data;
            while ((data = bis.read()) != -1) {
                System.out.print(data + " ");
                System.out.println((char) data);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
