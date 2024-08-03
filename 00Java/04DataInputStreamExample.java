import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

public class DataInputStreamExample {
    public static void main(String[] args) {
        // Q. why DataInputStream exists ?
        // A. A character data-type has direct representation when encoded into byte format,
        // you can directly access each byte in the byte array, and each byte represents a
        // part of the character data.
        // But bytes of Primitive data types like int, double, and float data-types do not
        // directly map to readable characters or text. They have specific internal representations
        // that do not map one-to-one with byte values in a straightforward manner. They represent
        // complex binary encodings that require special interpretation.
        
        // To remedy this we created DataInputStream. To allow reading Java's primitive data types
        // (e.g., int, float, double, char, boolean, etc.) directly from an input stream without needing
        // to write interpretation logic to parse them (otherwise data would become implementation
        // and interpretation specific and would have interoperability issues).
        
        /**
         * this simple char representation
        
        String data = "A-a_Z+z*0&1";
        byte[] byteArray = data.getBytes();
        for (byte b : byteArray) {
            System.out.println(b); // Prints byte values
        }
        
        for int will be how it is done -
        
        
        import java.nio.ByteBuffer;
        
        public class IntToByteArrayExample {
            public static void main(String[] args) {
                int number = 12345;
        
                // Convert int to byte array
                ByteBuffer buffer = ByteBuffer.allocate(4);
                buffer.putInt(number);
                byte[] byteArray = buffer.array();
        
                // Print byte array
                for (byte b : byteArray) {
                    System.out.println(b);
                }
        
                // Read int from byte array
                ByteBuffer bufferRead = ByteBuffer.wrap(byteArray);
                int readNumber = bufferRead.getInt();
                System.out.println("Read int: " + readNumber);
            }
        }

        
         * 
         */
         
         /*
         Below code would be a replacement for DataInputStream -

        import java.io.FileInputStream;
        import java.io.IOException;
        
        public class ManualPrimitiveReadExample {
            public static void main(String[] args) {
                try (FileInputStream fis = new FileInputStream("data.bin")) {
                    // Read int (4 bytes)
                    int intValue = (fis.read() << 24) | (fis.read() << 16) | (fis.read() << 8) | fis.read();
        
                    // Read double (8 bytes)
                    long longBits = 0;
                    for (int i = 0; i < 8; i++) {
                        longBits = (longBits << 8) | (fis.read() & 0xFF);
                    }
                    double doubleValue = Double.longBitsToDouble(longBits);
        
                    // Read boolean (1 byte)
                    boolean boolValue = (fis.read() != 0);
        
                    System.out.println("Read int: " + intValue);
                    System.out.println("Read double: " + doubleValue);
                    System.out.println("Read boolean: " + boolValue);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
         */
        
        
        try (DataInputStream inputStream = new DataInputStream(new FileInputStream("data.bin"))) {
            int intValue = inputStream.readInt();
            System.out.println("Int: " + intValue);
            
            float floatValue = inputStream.readFloat();
            System.out.println("Float: " + floatValue);
            
            double doubleValue = inputStream.readDouble();
            System.out.println("Double: " + doubleValue);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
