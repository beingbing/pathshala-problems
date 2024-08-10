# Identical methods already discussed in InputStream
1. `void write(char[] cbuf)`
  Writes an array of characters.

2. `abstract void	write(char[] cbuf, int off, int len)`
  Writes a portion of an array of characters.

3. `void write(int c)`
  Writes a single character.

4. `void write(String str)`
  Writes a string.

5. `void write(String str, int off, int len)`
  Writes a portion of a string.

6. `abstract void	close()`
  Closes the stream, flushing it first.

7. `abstract void	flush()`
  Flushes the stream.

These will not be discussed again.

# Note
Instead, we will discuss other methods declared in the `Reader` class and some specific methods of subclasses which are not part of the `Reader` class signature but are abundantly in use
