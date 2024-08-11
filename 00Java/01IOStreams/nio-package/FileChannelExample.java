import java.nio.channels.FileChannel;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.nio.ByteBuffer;
import java.io.IOException;
import java.nio.file.Path;

// A FileChannel cannot be set into non-blocking mode. It always runs in blocking mode.

public class FileChannelExample {
    public static void main(String[] args) {
        Path filePath = Paths.get("example.txt");

        // reading data when buffer capacity is less than file size
        try (FileChannel inChannel = FileChannel.open(filePath, StandardOpenOption.READ)) {

            //create buffer with capacity of 48 bytes
            ByteBuffer buf = ByteBuffer.allocate(48);
            int bytesRead = inChannel.read(buf); // read into buffer.

            while (bytesRead != -1) {
              System.out.println("Read " + bytesRead);

              //make buffer ready for read
              buf.flip(); // buf in which data is being written from file now will allow application read that data
        
              while(buf.hasRemaining()) {
                  System.out.print((char) buf.get()); // read 1 byte at a time
              }
        
              buf.clear(); // make buffer ready for writing
              bytesRead = inChannel.read(buf);
              System.out.println();
            }
        } catch (Exception e) {
            System.out.println("Exception: " + e.getMessage());
        }
        
        System.out.println("=================================++++++++++++++++++++++=================================");
        
        
        // writing (appending) data to the file
        String newData = "\nNew String to write to file..." + System.currentTimeMillis();
        
        try (FileChannel outChannel = FileChannel.open(filePath, StandardOpenOption.WRITE, StandardOpenOption.APPEND)) {
            ByteBuffer buffer = ByteBuffer.wrap(newData.getBytes("UTF-8"));
            outChannel.write(buffer);
            System.out.println("New content appended to the file.");
        } catch (IOException e) {
            e.printStackTrace();
        }
        
        System.out.println("=================================++++++++++++++++++++++=================================");
        
        // reading data when file can be completely put in buffer
        try (FileChannel inChannel = FileChannel.open(filePath, StandardOpenOption.READ)) {

            ByteBuffer buffer = ByteBuffer.allocate((int) inChannel.size());
            inChannel.read(buffer);

            buffer.flip(); // Switch buffer to read mode

            // Convert the content to a string
            String fileContent = new String(buffer.array(), "UTF-8");
            System.out.println("Original File Content:");
            System.out.println(fileContent);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
