# Locale
The `java.util.Locale` class in Java represents a specific geographical, political, or cultural region, enabling the localization of text, numbers, dates, and operations by adapting to different languages, countries, regional preferences and even a language variant (e.g., dialects).

#### A Locale object typically consists of:
- **Language:** A two- or three-letter lowercase ISO 639 code (e.g., "en" for English, "fr" for French represented as Locale.en / Locale.ENGLISH or Locale.fr).
- **Country:** A two-letter uppercase ISO 3166 code (e.g., "US" for the United States, "FR" for France represented as Local.US or Locale.FR).
- **Variant:** A code for variations that are not covered by language and country, such as different dialects or script variations (e.g., Locale("fr", "CA") represents French in Canada).

## Creating a Locale instance
1. Using Predefined Constants:
```java
Locale locale = Locale.US; // English in the United States
```
2. Using Constructors:
```java
Locale locale = new Locale("en", "GB"); // English in Great Britain
```
3. Using Builder Pattern:
```java
Locale locale = new Locale.Builder().setLanguage("fr").setRegion("CA").build(); // French in Canada
```

## Common Methods in Locale
- `getLanguage()`: Returns the language code.
- `getCountry()`: Returns the country code.
- `getDisplayLanguage()`: Returns the name of the language in a display-friendly format.
- `getDisplayCountry()`: Returns the name of the country in a display-friendly format.
- `getDisplayName()`: Returns a full display name of the locale (language, country, variant).
- `toString()`: Returns a string representation of the locale (language, country, variant).
```java
import java.util.Locale;

public class LocaleExample {
    public static void main(String[] args) {
        Locale locale = new Locale("en", "US");
        System.out.println("Language: " + locale.getLanguage());   // Output: en
        System.out.println("Country: " + locale.getCountry());     // Output: US
        System.out.println("Display Language: " + locale.getDisplayLanguage()); // Output: English
        System.out.println("Display Country: " + locale.getDisplayCountry());   // Output: United States
    }
}
```
