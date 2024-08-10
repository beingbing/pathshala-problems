import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class DataOutputStreamExample {
    public static void main(String[] args) {
      // To write primitive Java data types (e.g., int, float, double) to an output stream in
      // bytes format
        try (DataOutputStream dos = new DataOutputStream(new FileOutputStream("data.bin"))) {
            dos.writeInt(123);
            dos.writeFloat(3.14f);
            dos.writeUTF("Hello Samar");
            dos.writeInt(456);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
