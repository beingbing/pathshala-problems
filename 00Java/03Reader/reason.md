# Reason for creation
In the early days of Java while interacting with I/O Streams, numeric primitive data types had fixed sizes (e.g., `int` was 4B), and their conversion to bytes was straightforward and well abstracted in concrete classes `DataInputStream/DataOutputStream`. The `char` primitive type initially had a size of 1B (8b), each byte-array element directly translated to a character hence required no extra processing or a separate concrete class. However, as Java's need for internationalization grew, support for multiple character encodings became essential to handle text in various languages.

To address this, Java expanded the `char` size to 2B (16b), allowing it to represent all characters in human languages. Unlike numeric types, however, character encoding conversion wasn't a one-size-fits-all solution that could be solved by a subclass, as different encodings continued to emerge.

To accommodate this complexity, Java introduced a new category of streams designed specifically to work with character arrays, where each element is 16b. This decision led to the creation of `Reader/Writer` abstract classes, which handle the diverse needs of character encoding in a flexible and extensible way, unlike the byte-focused `InputStream/OutputStream`.

# Introduction of `Reader/Writer` Classes
These classes provide a higher-level abstraction specifically for handling character streams, which are sequences of characters rather than sequences of bytes. Here's how to achieve this:

**Character-Oriented Operations:** Unlike `InputStream/OutputStream`, which work with bytes, `Reader/Writer` work with characters (char). This makes them ideal for reading and writing text data.

**Direct Support for Character Data:** The methods in `Reader/Writer` are designed to work with char arrays, strings, and other character-based data structures, providing a more intuitive and direct way to handle text.

**Automatic Encoding/Decoding:** `InputStreamReader` (a subclass of `Reader`) reads bytes from an `InputStream` and decodes them into characters using specified encoding (e.g., UTF-8). Subclasses like this allow developers to specify the character encoding explicitly, ensuring that text is correctly interpreted and preserved across different systems and locales.

**Error Handling:** These classes provide built-in mechanisms for handling common text-related errors, such as encoding mismatches, making them safer and more reliable for text processing.
