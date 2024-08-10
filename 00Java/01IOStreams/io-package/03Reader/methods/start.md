# Identical methods already discussed in InputStream
1. `abstract void	close()`
  Closes the stream and releases any system resources associated with it.

2. `void	mark(int readAheadLimit)`
  Marks the present position in the stream.

3. `boolean	markSupported()`
  Tells whether this stream supports the mark() operation.

4. `int	read()`
  Reads a single character.

5. `int	read(char[] cbuf)`
  Reads characters into an array.

6. `abstract int	read(char[] cbuf, int off, int len)`
  Reads characters into a portion of an array.

7. `void	reset()`
  Resets the stream.

8. `long	skip(long n)`
Skips characters.

These will not be discussed again.

# Note
Instead, we will discuss other methods declared in the `Reader` class and some specific methods of subclasses which are not part of the `Reader` class signature but are abundantly in use
