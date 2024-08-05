import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class ObjectOutputStreamExample {
    public static void main(String[] args) {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("sample.dat"))) {
            // Create sample objects
            MyObject obj1 = new MyObject(11, "John Doe", 30, 60000);
            MyObject obj2 = new MyObject(12, "Jane Smith", 25, 65000);
            MyObject obj3 = new MyObject(13, "Emily Johnson", 40, 72000);
            MyObject obj4 = new MyObject(14, "Michael Brown", 35, 68000);
            MyObject obj5 = new MyObject(15, "Jessica Davis", 28, 63000);

            // Serialize objects
            oos.writeObject(obj1);
            oos.writeObject(obj2);
            oos.writeObject(obj3);
            oos.writeObject(obj4);
            oos.writeObject(obj5);

            System.out.println("Objects have been serialized to sample.dat");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
