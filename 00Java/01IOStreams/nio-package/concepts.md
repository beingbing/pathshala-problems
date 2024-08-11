# Introduction
NIO mean New IO, it doesn't represent non-blocking IO. it contains both blocking and non-blocking APIs.

In the standard IO API you work with byte streams and character streams. In NIO you work with channels and buffers. Data is always read from a channel into a buffer, or written from a buffer to a channel.

It also contains the concept of "selectors". A selector is an object that can monitor multiple channels for events (like: connection opened, data arrived etc.). Thus, a single thread can monitor multiple channels for data.

Hence, Java NIO consist of the following core components:
- Channels
- Buffers
- Selectors

# Channels
A `Channel` is a bi-directional communication channel for data, representing an open connection to an I/O device such as a file, socket, or pipe. You can transfer data directly from one channel to another. Channels abstract the underlying System I/O operations and allow for efficient data transfer between the I/O device and the buffers. Unlike streams, channels can be used for both reading and writing operations Asynchronously.
List of the primary Channel implementations in Java NIO:
- `FileChannel` - reads data from and to files.
- `DatagramChannel` - read and write data over the network via UDP.
- `SocketChannel` - read and write data over the network via TCP.
- `ServerSocketChannel` - allows you to listen for incoming TCP connections like a web server does. For each incoming connection, a `SocketChannel` is created.
```
FileChannel fileChannel = FileChannel.open(Paths.get("example.txt"), StandardOpenOption.READ);
```

# Buffers
A `Buffer` in NIO is a container for a fixed amount of data of a specific primitive type. Buffers are used for reading and writing data. First, you read into a Buffer, Then you flip it, Then you read out of it. Buffers work as an intermediary between the channel and the application. Data is written into a buffer from a channel and then read from the buffer by the application, or vice versa. Buffers are used to manage data and track its position, limit, and capacity, making it easier to work with data streams. A Buffer has three properties you need to be familiar with, in order to understand how a Buffer works. These are:
- **capacity:** A buffer has a fixed size, known as its capacity, which defines how much data it can hold. You can only write data up to this capacity. Once the buffer is full, you must either read or clear it before writing more data.
- **position:** The position in a buffer indicates where the next piece of data will be written or read. It starts at 0 and advances as data is added. The position can go up to `capacity - 1`. When you switch the buffer from write mode to read mode (using `flip()`), the position resets to 0, allowing you to read data from the beginning.
- **limit:** In write mode, the limit represents the maximum amount of data you can write, which is equal to the buffer's capacity. When you flip the buffer to read mode, the limit is set to the last written position, defining how much data can be read. In essence, the limit in read mode equals the amount of data that was written.

Using a `Buffer` to read and write data typically follows below steps -
1. Write data into the `Buffer`
2. Call `flip()` on its object
3. Read data out of the `Buffer`
4. Call `clear()/compact()` for clearing already read bytes

### flip()
When you write data to a buffer, it tracks the amount written. To read this data, you must switch the buffer from write mode to read mode using the `flip()` method. In read mode, the buffer allows you to access all the data you’ve written.

### rewind()
The rewind() method resets the buffer's position to 0, allowing you to reread all the data. The limit remains unchanged, so you can still read up to the previously set limit.

### clear()/compact()
After reading from a buffer, you must prepare it for writing again using either `clear()` or `compact()`.
- `clear():` Resets the position to 0 and the limit to the buffer's capacity, making it ready for new data. The data itself isn’t erased, but the markers for reading and writing are reset. Any unread data is effectively "forgotten" since the position and limit no longer indicate where that data resides.
- `compact():` Retains unread data by moving it to the start of the buffer. The position is set right after the last unread element, and the limit remains at the buffer's capacity. This allows you to write new data without overwriting the unread data.

### mark() and reset()
You can mark a specific position in a buffer using the `mark()` method. Later, you can return to this marked position by calling `reset()`. For example:
```java
buffer.mark();
// Call buffer.get() a few times during parsing.
buffer.reset();  // Reset position back to the mark.
```

### equals() and compareTo()
- **equals():**  
  Two buffers are considered equal if:
  - They are of the same type (byte, char, int, etc.).
  - They have the same number of remaining elements.
  - All remaining elements are identical.
  
  **Note:** The `equals()` method compares only the remaining elements in the buffers, not the entire content.

- **compareTo():**  
  The `compareTo()` method compares the remaining elements of two buffers for sorting purposes. A buffer is considered "smaller" if:
  - The first differing element in one buffer is smaller than in the other.
  - All elements are equal, but the first buffer has fewer remaining elements than the other.

### Scatter / Gather
Java NIO supports scatter/gather operations, which are useful for reading from and writing to channels.
- **Scattering Reads:**  
  A scattering read reads data from a channel into multiple buffers. The data is "scattered" across the buffers in the order they appear. This approach is ideal for scenarios where you need to separate parts of the data, like splitting a message into a header and a body.
  Example:
  ```java
  ByteBuffer header = ByteBuffer.allocate(128);
  ByteBuffer body   = ByteBuffer.allocate(1024);

  ByteBuffer[] bufferArray = { header, body };

  channel.read(bufferArray);
  ```
  In this example, data is read into the `header` buffer first. Once it's full, the channel moves on to the `body` buffer. Scattering reads are best for fixed-size parts, such as a 128-byte header.

- **Gathering Writes:**  
  A gathering write writes data from multiple buffers into a single channel. The data is "gathered" from the buffers in sequence. Only the data between each buffer's position and limit is written, making this method suitable for dynamically sized parts.
  Example:
  ```java
  ByteBuffer header = ByteBuffer.allocate(128);
  ByteBuffer body   = ByteBuffer.allocate(1024);

  ByteBuffer[] bufferArray = { header, body };

  channel.write(bufferArray);
  ```
  Here, the channel writes data from the `header` buffer first, followed by the `body` buffer. Gathering writes handle varying data sizes effectively, as only the data between the position and limit is transmitted.

### types of Buffer
List of the core Buffer implementations in Java NIO:
- `ByteBuffer`
- `CharBuffer`
- `DoubleBuffer`
- `FloatBuffer`
- `IntBuffer`
- `LongBuffer`
- `ShortBuffer`
```
ByteBuffer buffer = ByteBuffer.allocate(1024); // Allocating a buffer with a capacity of 1024 bytes
```

# Selectors
`Selector` allows a single thread to monitor multiple channels for events, such as incoming data or readiness to write. This concept is essential for non-blocking I/O. This is handy if your application has many connections (Channels) open, but only has low traffic on each connection. Selectors are used in conjunction with channels to build scalable, non-blocking I/O operations. A thread can check which channels are ready for specific operations and then process them accordingly. To use a `Selector` you register the `Channel`'s with it. Then you call `Selector`'s `select()` method. This method will block the thread until there is an event ready for one of the registered channels. Once the method returns, the thread can then process the manifested events.
```
Selector selector = Selector.open();
socketChannel.register(selector, SelectionKey.OP_READ);
selector.select();
Iterator<SelectionKey> keys = selector.selectedKeys().iterator();
```

### Why Use a Selector?
Using a single thread to manage multiple channels reduces the need for multiple threads, saving system resources and reducing the overhead of thread switching. Although modern operating systems and CPUs handle multithreading more efficiently, using a Selector allows you to manage multiple channels with just one thread.

### Creating a Selector
To create a Selector, use:
```java
Selector selector = Selector.open();
```

### Registering Channels with the Selector
To use a channel with a Selector, you must register the channel:
```java
channel.configureBlocking(false);
SelectionKey key = channel.register(selector, SelectionKey.OP_READ);
```
The channel must be in non-blocking mode, meaning you can't use FileChannels with a Selector, but socket channels work fine.

The second parameter in `register()` specifies the "interest set"—the events you're interested in (e.g., connect, accept, read, write). These are represented by the constants `SelectionKey.OP_CONNECT`, `SelectionKey.OP_ACCEPT`, `SelectionKey.OP_READ`, and `SelectionKey.OP_WRITE`. You can combine multiple events using the bitwise OR operator:
```java
int interestSet = SelectionKey.OP_READ | SelectionKey.OP_WRITE;
```

### SelectionKey

When you register a channel with a Selector, the `register()` method returns a `SelectionKey`, which contains:

- **Interest Set:** The set of events you're interested in. You can check which events are included using:
  ```java
  int interestSet = selectionKey.interestOps();
  boolean isInterestedInRead = (interestSet & SelectionKey.OP_READ) != 0;
  ```

- **Ready Set:** The set of operations the channel is ready for. Access it after a selection:
  ```java
  int readySet = selectionKey.readyOps();
  boolean isReadable = selectionKey.isReadable();
  ```

- **Channel & Selector:** Access the associated channel and selector:
  ```java
  Channel channel = selectionKey.channel();
  Selector selector = selectionKey.selector();
  ```

- **Attaching Objects:** You can attach an object to a `SelectionKey` to store additional information:
  ```java
  selectionKey.attach(theObject);
  Object attachedObj = selectionKey.attachment();
  ```
  You can also attach an object while registering the channel:
  ```java
  SelectionKey key = channel.register(selector, SelectionKey.OP_READ, theObject);
  ```

### Selecting Channels via a Selector

After registering channels, use the `select()` methods to determine which channels are ready:
- `int select()`: Blocks until at least one channel is ready.
- `int select(long timeout)`: Blocks for up to `timeout` milliseconds.
- `int selectNow()`: Returns immediately with the channels that are ready.

The `select()` methods return the number of ready channels. To access these channels, use the `selectedKeys()` method:
```java
Set<SelectionKey> selectedKeys = selector.selectedKeys();
Iterator<SelectionKey> keyIterator = selectedKeys.iterator();

while (keyIterator.hasNext()) {
    SelectionKey key = keyIterator.next();
    if (key.isAcceptable()) {
        // Connection accepted
    } else if (key.isConnectable()) {
        // Connection established
    } else if (key.isReadable()) {
        // Channel ready for reading
    } else if (key.isWritable()) {
        // Channel ready for writing
    }
    keyIterator.remove();  // Remove the key from the set after processing
}
```

### wakeUp()
If a thread is blocked in a `select()` call, another thread can call `Selector.wakeup()` to immediately unblock it. If no thread is blocked, the next call to `select()` will return immediately.

### close()
When you're done with the Selector, close it using `close()`. This invalidates all registered `SelectionKey` instances but does not close the channels themselves.

**Full Selector Example**
```java
Selector selector = Selector.open();
channel.configureBlocking(false);
SelectionKey key = channel.register(selector, SelectionKey.OP_READ);

while (true) {
    int readyChannels = selector.selectNow();
    if (readyChannels == 0) continue;

    Set<SelectionKey> selectedKeys = selector.selectedKeys();
    Iterator<SelectionKey> keyIterator = selectedKeys.iterator();

    while (keyIterator.hasNext()) {
        SelectionKey key = keyIterator.next();
        if (key.isAcceptable()) {
            // Connection accepted
        } else if (key.isConnectable()) {
            // Connection established
        } else if (key.isReadable()) {
            // Channel ready for reading
        } else if (key.isWritable()) {
            // Channel ready for writing
        }
        keyIterator.remove();  // Remove the key after processing
    }
}
```
This loop continuously checks for ready channels, processes them, and removes them from the selected key set.
