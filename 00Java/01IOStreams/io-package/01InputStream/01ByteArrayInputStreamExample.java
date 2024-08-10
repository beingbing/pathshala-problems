import java.io.ByteArrayInputStream;
import java.io.IOException;

public class ByteArrayInputStreamExample {
    public static void main(String[] args) {
        String data = "A-a_Z+z*0&1";
        byte[] byteArray = data.getBytes(); // convert String into a byte array
      // byte array is converting each character of a string into an array element
        
        for (int j = 0; j < byteArray.length; j++) {
            System.out.println(byteArray[j]);
        }
        
        System.out.println("=================");

        try (ByteArrayInputStream byteArrayInputStream = new ByteArrayInputStream(byteArray)) {
            int ch;
            while ((ch = byteArrayInputStream.read()) != -1) {
                System.out.println(ch);
                System.out.println((char) ch);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
