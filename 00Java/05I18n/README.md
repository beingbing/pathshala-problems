# Internationalization (i18n) and Localization (L10n)
Internationalization (i18n) is the process of designing a Java application to support multiple languages, number formats, date formats, and other locale-specific preferences. Localization (L10n) is the adaptation of the application to a specific user's language, region, and formatting preferences.

#### To internationalize a Java application:
- **Handle International Input:** This includes managing various languages, character encodings, number formats, and date/time formats. Input can come from forms, service calls (e.g., SOAP, REST), or files.
- **Handle International Output:** This covers the display of text, numbers, currencies, dates, and times in a user's preferred format.
- **Adapting Operations:** The application might also need to adapt its operations based on user preferences, such as calculating taxes based on the user's location.

#### To properly localize your application, you may need:
- Preferred Language
- Country of Residence
- Current Location
- Preferred Time Zone

# Application Internationalization Layer
It converts between the internal data formats used by the application and the formats required by users. This layer handles text encoding, number formatting, date/time formatting, and time zone conversions.

#### Java provides several classes to aid this layer:
- `Locale`: Represents a specific language and region.
- `ResourceBundle`: Contains localized texts or components for a specific Locale.
- `NumberFormat`: Formats numbers according to a Locale.
- `DateFormat`: Formats dates according to a Locale.
