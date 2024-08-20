# ResourceBundle
The `java.util.ResourceBundle` class separately store locale-sensitive text and components from the main application logic. It is typically a set of key-value pairs. You might have resource bundles as -
- `MessagesBundle_en_US.properties`
```properties
greeting=Hello
farewell=Goodbye
```
- `MessagesBundle_fr_FR.properties`
```properties
greeting=Bonjour
farewell=Au revoir
```
- in-code -
```java
import java.util.ListResourceBundle;

public class MessagesBundle_fr_FR extends ListResourceBundle {
    @Override
    protected Object[][] getContents() {
        return new Object[][] {
            {"greeting", "Bonjour"},
            {"farewell", "Au revoir"}
        };
    }
}
```
```java
public class MyClassBundle_da extends ListResourceBundle {
    protected Object[][] getContents() {
        return new Object[][] {
            { "price", 75.00 },
            { "currency", "DKK" }
        };
    }
}
```

## Types of `ResourceBundle`
Java provides two main subclasses of `ResourceBundle`:
- **PropertyResourceBundle:** Manages resources stored in `.properties` files.
- **ListResourceBundle:** Manages resources in a Java class, typically used when resources are stored in code rather than in external files.

## Creating a `ResourceBundle`
- Using `getBundle()` (The `ResourceBundle` class first looks for a `ListResourceBundle` and, if not found, defaults to a `PropertyResourceBundle`)
```java
import java.util.Locale;
import java.util.ResourceBundle;

public class ResourceBundleExample {
    public static void main(String[] args) {
        // Load the resource bundle for French locale
        Locale locale = new Locale("fr", "FR");
        ResourceBundle bundle = ResourceBundle.getBundle("MessagesBundle", locale);

        // Retrieve and print the localized messages
        String greeting = bundle.getString("greeting");
        String farewell = bundle.getString("farewell");

        System.out.println(greeting); // Output: Bonjour
        System.out.println(farewell); // Output: Au revoir
    }
}
```

### ResourceBundle fallback mechanism when searching for resources:
- It first looks for the most specific bundle (e.g., MessagesBundle_fr_FR.properties).
- If not found, it checks the less specific one (e.g., MessagesBundle_fr.properties).
- If still not found, it defaults to the base bundle (MessagesBundle.properties).

## Advanced features
- Parameterizing Messages with `MessageFormat`
Often, messages contain placeholders for dynamic data. MessageFormat allows you to format and replace placeholders within a message.
```properties
welcome=Welcome, {0}!
```
```java
import java.text.MessageFormat;
import java.util.Locale;
import java.util.ResourceBundle;

public class MessageFormatExample {
    public static void main(String[] args) {
        Locale locale = new Locale("en", "US");
        ResourceBundle bundle = ResourceBundle.getBundle("MessagesBundle", locale);
        
        String pattern = bundle.getString("welcome");
        String formattedMessage = MessageFormat.format(pattern, "John");
        
        System.out.println(formattedMessage); // Output: Welcome, John!
    }
}
```
- Using `ResourceBundle.Control`
It allows you to customize how resource bundles are loaded, including specifying different formats (e.g., XML) or loading bundles from non-standard locations.
```java
import java.util.Locale;
import java.util.ResourceBundle;

public class CustomControlExample {
    public static void main(String[] args) {
        Locale locale = new Locale("en", "US");
        ResourceBundle.Control control = ResourceBundle.Control.getControl(ResourceBundle.Control.FORMAT_DEFAULT);
        ResourceBundle bundle = ResourceBundle.getBundle("MessagesBundle", locale, control);

        String greeting = bundle.getString("greeting");
        System.out.println(greeting);
    }
}
```
