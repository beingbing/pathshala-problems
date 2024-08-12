import java.io.File;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;

public class PathAndFileExample {
  public static void main(String[] args) {
    Path sourcePath = Paths.get("src", "main", "java", "source.txt"); // create Path object using factory method
    Path destinationPath = Paths.get("src", "destination", "source.txt");
    File destFile = destinationPath.toFile(); // io File and nio Path are mostly interchangeable
    System.out.println(destFile.getAbsolutePath());

    try {
        // check if file exsits
        Path path = Paths.get("src", "main", "java", "data/logging.properties");
        boolean pathExists = Files.exists(path, new LinkOption[]{LinkOption.NOFOLLOW_LINKS});
        System.out.println("does file represented by path exists ? - " + pathExists);
      
        // Copy file
        Files.copy(sourcePath, destinationPath, StandardCopyOption.REPLACE_EXISTING);
        System.out.println("File copied to: " + destinationPath);

        // get relative Path
        Path srcTodestPath = sourcePath.relativize(destinationPath); // path from src -> dest
        Path destToSrcPath = destinationPath.relativize(sourcePath); // path from dest -> src

        System.out.println("src -> dest path: " + srcTodestPath);
        System.out.println("dest -> src Path: " + destToSrcPath);

        // Move file to a new directory
        Path newDir = Paths.get("new_directory"); // absolute Path for new directory
        Files.createDirectories(newDir); // // create new directory at root
        Path movedPath = newDir.resolve("source.txt"); // get newDir path w.r.t ()
        Files.move(destinationPath, movedPath, StandardCopyOption.REPLACE_EXISTING);
        System.out.println("File moved to: " + movedPath);

        // Delete the moved file
        Files.delete(movedPath);
        System.out.println("File deleted from: " + movedPath);
    } catch (IOException e) {
        e.printStackTrace();
    }
  }
}
