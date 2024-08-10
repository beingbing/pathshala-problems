import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;

public class ObjectInputStreamExample {
    public static void main(String[] args) {
      // to read serialized object from an input stream
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream("sample.dat"))) {
            // Read objects
            MyObject obj1 = (MyObject) ois.readObject();
            MyObject obj2 = (MyObject) ois.readObject();
            MyObject obj3 = (MyObject) ois.readObject();
            MyObject obj4 = (MyObject) ois.readObject();
            MyObject obj5 = (MyObject) ois.readObject();

            // Print objects
            System.out.println("Read objects:");
            System.out.println(obj1);
            System.out.println(obj2);
            System.out.println(obj3);
            System.out.println(obj4);
            System.out.println(obj5);
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}

class MyObject implements java.io.Serializable {
    int id, age, salary;
    String name;

    public MyObject(int id, String name, int age, int salary) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.salary = salary;
    }

    @Override
    public String toString() {
        return "MyClass{id=" + id + ", name='" + name + '\'' + ", age='" + age + '\'' + ", salary='" + salary + '\'' + '}';
    }
}
