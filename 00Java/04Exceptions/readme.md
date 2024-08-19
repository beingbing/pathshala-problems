# Introduction
An exception is an event that disrupts the normal flow of a program's execution. Java uses it as an object to represent an error or unexpected event that occurs during runtime. When you write a method, you can either deal with the exception or make it the calling method's problem. To make it a caller's problem, use the `Throwable` class.

 # Types of Exceptions
 Java exceptions are categorized into three main types:

### 1. Checked Exceptions
Exceptions that are checked at compile-time. Java prepares our happy path for scenarios which the compiler is aware might happen if something goes wrong at runtime. The compiler forces the programmer to handle them using try-catch blocks or declaring them using the throws keyword. All of them inherit the `Exception` class. They are used for recoverable errors, where the programmer is expected to handle the situation gracefully. Example - `IOException`, `SQLException`, `FileNotFoundException`, etc.

### 2. Unchecked Exceptions
Exceptions that can not be anticipated at compile-time. These exceptions are usually due to programming errors, such as logic mistakes or improper use of an API that usually cannot be recovered gracefully from and indicate bugs in the code. All of them inherit the `RuntimeException` class. They are logical unexpected implementation pitfalls which are not fatal to business logic. Example - `NullPointerException`, `ArrayIndexOutOfBoundsException`, `IllegalArgumentException`, etc.

### 3. Errors
Errors are serious problems that a reasonable application should not try to catch. They are usually external to the application and indicate serious system-level issues. Errors are typically unrecoverable, and the JVM should handle them. Example - `OutOfMemoryError`, `StackOverflowError`, `VirtualMachineError`, etc.

# Exception Hierarchy
```
Throwable
├── Error (unrecoverable)
└── Exception (recoverable)
    ├── RuntimeException (unchecked)
    └── [Other Checked Exceptions]
```
- **Throwable:** The superclass of all errors and exceptions.
- **Error:** Represents serious problems that applications should not attempt to handle.
- **Exception:** The superclass of all checked exceptions.
- **RuntimeException:** The superclass of all unchecked exceptions.

# Handling Exception
## Try-Catch Block
```java
try {
    // Code that might throw an exception
} catch (ExceptionType e) {
    // Handling the exception
} finally {
    // Optional block, executed regardless of exception
}
```
method catches and handles the exception by itself.

## Throws Clause
```java
public void readFile() throws IOException {
    // Code that might throw IOException
}
```
Declares that a method can throw an exception, leaving it to the caller to handle.

## Throw Keyword
```java
if (condition) {
    throw new IllegalArgumentException("Invalid argument");
}
```
explicitly throws an exceptioon for caller to handle

# Creating Custom Exceptions
- Checked
```java
public class InvalidUserException extends Exception {
    public InvalidUserException(String message) {
        super(message);
    }
}
```
- Unchecked
```java
public class InvalidUserRuntimeException extends RuntimeException {
    public InvalidUserRuntimeException(String message) {
        super(message);
    }
}
```

### Note:
If Exception A is thrown because Exception B got produced, then A is suppressed and B is primary Exception.

# Automatic Resource Management (try-with-resource)
```java
try (BufferedReader br = new BufferedReader(new FileReader("file.txt")); var out = new FileOutputSteam("output.txt") {
    // Work with the resource
} catch (IOException e) {
    // Handle the exception
}
```
- Introduced in Java 7, this ensures that resources are closed automatically when the try block exits.
- When multiple resources are opened, they are closed in the reverse order.
- try-with-resource don't need a follow-up `catch` or `finally` block
- if a `finally` block is added, it will be run after implicit `finally` block written by compiler
- classes implementing `AutoCloseable` interface can only be used.
- each resource declaration should be separated by `;`
- scope of `try` block ends at `}` before any user-defined `catch/finally` block starts.

**Note:** `Closable` throws `IOException` and extends `AutoClosable` which throws `Exception` 
