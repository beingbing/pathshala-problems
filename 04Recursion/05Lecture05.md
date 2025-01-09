# Passing Variables in Java
In programming, there are two common ways to pass variables to a function:
1. **Pass by Value**
2. **Pass by Reference**

In Java, **all variables are passed by value**. However, understanding how references work in Java is key to using this correctly with objects. Here’s how each passing method works:

## Pass by Value
In **pass by value**, the value of the variable is copied into a new variable within the called function. This means any changes made within the function will not affect the original variable in the caller.

Example:
```java
public class PassByValueExample {
    public static void main(String[] args) {
        int number = 10;
        modifyValue(number);
        System.out.println("Original value after function call: " + number);  // Outputs 10
    }

    public static void modifyValue(int num) {
        num = num + 5;  // This change does not affect the original variable
    }
}
```

**Output**:
```
Original value after function call: 10
```

Since `num` is a copy of `number`, changes to `num` inside `modifyValue()` don’t affect `number` in `main()`.

## Pass by Reference
**Pass by reference** refers to passing the address (reference) of an object rather than a copy. In Java, while only references to objects are passed by value, these references allow modifications to the object itself.

Example:
```java
public class PassByReferenceExample {
    public static void main(String[] args) {
        int[] numbers = {1, 2, 3};
        modifyArray(numbers);
        System.out.println("Array after function call: " + numbers[0]);  // Outputs 10
    }

    public static void modifyArray(int[] arr) {
        arr[0] = 10;  // Modifies the actual object referenced by `arr`
    }
}
```

**Output**:
```
Array after function call: 10
```

Since the array `numbers` is an object, its reference is passed to `modifyArray()`, allowing changes to persist after the function returns.

## **Key Takeaways**
- **Primitive types** (like `int`, `double`) are unaffected by changes within a method because only copies of values are passed.
- **Object types** (like arrays, lists) can be modified within a method, as a reference to the actual object is passed.
