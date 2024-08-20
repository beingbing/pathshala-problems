# NumberFormat
It is an abstract class that provides the interface for formatting and parsing numbers. It supports locale-specific number formats, allowing your code to handle different conventions for decimal points, thousands separators, and even non-decimal number systems, without being dependent on any specific locale. Additionally, NumberFormat includes methods to determine available locales and their respective number format names. `NumberFormat` instances are not thread-safe. If you need to use a `NumberFormat` object across multiple threads, consider synchronizing access or using separate instances for each thread. It has 3 main subclasses - `ChoiceFormat`, `CompactNumberFormat`, `DecimalFormat`.

### Formatting Methods:
- `String format(double number)` - Formats a double value as a number.
 - `String format(long number)` - Formats a long value as a number.

### Parsing Methods:
- `Number parse(String source)` - Parses text from a string to produce a number.

### Factory Methods:
- `static NumberFormat getInstance()` - Returns a general-purpose number format for the default locale.
- `static NumberFormat getInstance(Locale locale)` - Returns a general-purpose number format for the specified locale.
- `static NumberFormat getCurrencyInstance()` - Returns a currency format for the default locale.
- `static NumberFormat getCurrencyInstance(Locale locale)` - Returns a currency format for the specified locale.
- `static NumberFormat getPercentInstance()` - Returns a percentage format for the default locale.
- `static NumberFormat getPercentInstance(Locale locale)` - Returns a percentage format for the specified locale.
- `static NumberFormat getIntegerInstance()` - Returns an integer format for the default locale.
- `static NumberFormat getIntegerInstance(Locale locale)` - Returns an integer format for the specified locale.

### Customization Methods:
- `setMaximumFractionDigits(int newValue)` - Sets the maximum number of digits allowed in the fraction portion.
- `setMinimumFractionDigits(int newValue)` - Sets the minimum number of digits allowed in the fraction portion.
- `setGroupingUsed(boolean newValue)` - Sets whether or not grouping will be used (e.g., thousands separator).
- `setParseIntegerOnly(boolean value)` - Sets whether only integers should be parsed.
  
## Examples:
### 1. Types of Formatting -
```java
import java.text.NumberFormat;

public class NumberFormattingExample {
    
    public static void main(String[] args) {
        // General Number Formatting: Formats numbers in a locale-specific manner.
        NumberFormat numberFormat = NumberFormat.getInstance();
        System.out.println(numberFormat.format(12345.6789));    // output: 12,345.679
        
        // Currency Formatting: Formats numbers as currency values
        NumberFormat currencyFormat = NumberFormat.getCurrencyInstance();
        System.out.println(currencyFormat.format(12345.6789));  // output: $12,345.68
    
        // Percentage Formatting: Formats numbers as percentages
        NumberFormat percentFormat = NumberFormat.getPercentInstance();
        System.out.println(percentFormat.format(0.75));         // output: 75%
    
        // Integer Formatting: Formats numbers without fraction digits
        NumberFormat integerFormat = NumberFormat.getIntegerInstance();
        System.out.println(integerFormat.format(12345.6789));   // output: 12,346
    }

}
```

### 2. Locale-Specific Formatting
```java
import java.text.NumberFormat;
import java.util.Locale;

public class NumberFormattingExample {
    
    public static void main(String[] args) {
        double amount = 12345.678;
        NumberFormat usFormat = NumberFormat.getCurrencyInstance(Locale.US);
        System.out.println(usFormat.format(amount));     // output: $12,345.68

        NumberFormat franceFormat = NumberFormat.getCurrencyInstance(Locale.FRANCE);
        System.out.println(franceFormat.format(amount)); // output: 12 345,68 €
        
        NumberFormat ukFormat = NumberFormat.getCurrencyInstance(Locale.UK);
        System.out.println(ukFormat.format(amount));    // output: £12,345.68

        NumberFormat jpFormat = NumberFormat.getCurrencyInstance(Locale.JAPAN);
        System.out.println(jpFormat.format(amount));    // output: ￥12,346
    }
}
```

### 3. Parsing Numbers
```java
import java.text.NumberFormat;
import java.text.ParseException;
import java.util.Locale;

public class NumberFormattingExample {
    
    public static void main(String[] args) {
        try {
            NumberFormat format = NumberFormat.getInstance();
            Number number = format.parse("12,345.67");
            System.out.println(number.byteValue());     // 57
            System.out.println(number.doubleValue());   // 12345.67
            System.out.println(number.floatValue());    // 12345.67
            System.out.println(number.intValue());      // 12345
            System.out.println(number.longValue());     // 12345
            System.out.println(number.shortValue());    // 12345
        } catch (ParseException e) {
            e.printStackTrace();
        }
    }
}
```

### 4. Customizing NumberFormat
```java
import java.text.NumberFormat;
import java.text.ParseException;
import java.util.Locale;

public class NumberFormattingExample {
    
    public static void main(String[] args) {
        // Fraction Digits: Control how many digits appear after the decimal point
        NumberFormat format = NumberFormat.getInstance();
        format.setMaximumFractionDigits(2);
        System.out.println(format.format(12345.6789));  // 12,345.68

        // Grouping Separator: Decide whether to use grouping separators like commas
        format.setGroupingUsed(false);
        System.out.println(format.format(12345.6789));  // 12345.68
    }
}
```

# DecimalFormat
 It provides greater control over formatting numbers, allowing you to specify custom patterns for formatting decimal numbers and handles locale-specific symbols like decimal separators, grouping separators, currency symbols, etc.

### Pattern Symbols:
- `0` - Digit (shows a digit, or zero if none).
- `#` - Digit (shows a digit, or nothing if none).
- `.` - Decimal separator.
- `,` - Grouping separator.
- `¤` - Currency symbol.
- `%` - Percentage.
- `E` - Scientific notation.

### Example:
```java
import java.text.DecimalFormat;
import java.util.Locale;

public class NumberFormattingExample {
    
    public static void main(String[] args) {
        double number = 1234567.8934;
        
        DecimalFormat df = new DecimalFormat("#,###.00");
        System.out.println(df.format(number));          // Output: 1,234,567.89

        DecimalFormat dfCurrency = new DecimalFormat("¤ #,###.00");
        System.out.println(dfCurrency.format(number));  // Output: $ 1,234,567.89 (default locale)
    }
}
```
