import java.io.IOException;
import java.net.URI;
import java.nio.file.*;
import java.util.HashMap;
import java.util.Map;

// NIO 2 allows the integration of custom file systems or working with non-standard 
// file systems through the FileSystem and FileSystems classes

public class ZipFileSystemExample {

    public static void main(String[] args) {
        String zipFilePath = "example.zip";

        Map<String, String> env = new HashMap<>();
        env.put("create", "true");

        URI uri = URI.create("jar:file:/" + Paths.get(zipFilePath).toUri().getPath());

        try (FileSystem zipfs = FileSystems.newFileSystem(uri, env)) {
            Path externalFile = Paths.get("example.txt");
            Path pathInZipfile = zipfs.getPath("/example.txt");

            // Copy a file into the ZIP file system
            Files.copy(externalFile, pathInZipfile, StandardCopyOption.REPLACE_EXISTING);
            System.out.println("File copied into the ZIP file system.");

            // List the contents of the ZIP file system
            Files.walk(zipfs.getPath("/"))
                    .filter(Files::isRegularFile)
                    .forEach(System.out::println);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
