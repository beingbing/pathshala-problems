import java.io.IOException;
import java.nio.file.*;
import java.nio.file.attribute.BasicFileAttributes;
import java.nio.file.attribute.FileTime;

public class FileAttributeViewExample {

    public static void main(String[] args) {
        Path filePath = Paths.get("example.txt");

        try {
            // Retrieve basic file attributes
            BasicFileAttributes attributes = Files.readAttributes(filePath, BasicFileAttributes.class);

            System.out.println("Creation Time: " + attributes.creationTime());
            System.out.println("Last Modified Time: " + attributes.lastModifiedTime());
            System.out.println("Size: " + attributes.size() + " bytes");

            // Modify the last modified time
            FileTime newLastModifiedTime = FileTime.fromMillis(System.currentTimeMillis());
            Files.setLastModifiedTime(filePath, newLastModifiedTime);

            System.out.println("Updated Last Modified Time: " + Files.getLastModifiedTime(filePath));

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
