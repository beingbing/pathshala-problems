import java.nio.channels.FileChannel;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.nio.ByteBuffer;

public class FileChannelExample {
    public static void main(String[] args) {
        try (FileChannel inChannel = FileChannel.open(Paths.get("example.txt"), StandardOpenOption.READ)) {

            ByteBuffer buf = ByteBuffer.allocate(48);
            int bytesRead = inChannel.read(buf);

            while (bytesRead != -1) {
              System.out.println("Read " + bytesRead);

              buf.flip(); // buf in which data is being written from file now will allow application read that data
        
              while(buf.hasRemaining()) {
                  System.out.print((char) buf.get());
              }
        
              buf.clear();
              bytesRead = inChannel.read(buf);
              System.out.println();
            }
        } catch (Exception e) {
            System.out.println("Exception: " + e.getMessage());
        }
    }
}
