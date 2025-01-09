# Comparators and Stability in Sorting Algorithms
Sorting algorithms are fundamental in computer science and often require defining custom comparison logic. This logic determines the order in which elements are sorted.

## Custom Comparators
A **comparator** is a function that defines the comparison logic for sorting. The comparator determines whether one element should be placed before another based on a given condition.

### Examples of Comparison Logic
1. **Ascending Order:** To sort in ascending order:
   ```java
   boolean cmpr(int x, int y) {
       return x < y; // Return true if x should come before y
   }
   ```

2. **Descending Order:** To sort in descending order:
   ```java
   boolean cmpr(int x, int y) {
       return x > y; // Return true if x should come after y
   }
   ```

3. **Custom Order (e.g., Based on Magnitude):** To sort in ascending order of absolute values:
   ```java
   boolean cmpr(int x, int y) {
       return Math.abs(x) < Math.abs(y);
   }
   ```

## Stability in Sorting
**Stability** in sorting refers to whether the relative order of elements with equal values is preserved.
- **Stable Sort**: The order of equivalent elements remains the same as in the input.
- **Unstable Sort**: The relative order of equivalent elements may change.

### Example of Stability
Consider sorting the following pairs based on the first element:  
Input: `[(3, 1), (3, 2), (2, 3)]`
- **Stable Sort**: Output: `[(2, 3), (3, 1), (3, 2)]`
- **Unstable Sort**: Output: `[(2, 3), (3, 2), (3, 1)]`

### Ensuring Stability with Custom Comparators
To maintain stability in a custom comparator:
1. Check if the primary sorting key is equal.
2. Use a secondary criterion (e.g., the original index) to decide the order.

Example: Stable sorting of pairs based on the first value:
```java
boolean cmpr(Pair<Integer, Integer> x, Pair<Integer, Integer> y) {
    if (x.getKey().equals(y.getKey())) {
        return x.getValue() < y.getValue(); // Sort by index for stability
    }
    return x.getKey() < y.getKey(); // Sort by the first value
}
```

### Code
```java
import java.util.*;

public class ComparatorAndStability {
    public static void main(String[] args) {
        List<Pair<Integer, Integer>> data = new ArrayList<>();
        data.add(new Pair<>(3, 1));
        data.add(new Pair<>(3, 2));
        data.add(new Pair<>(2, 3));
        
        // Stable sort
        data.sort((x, y) -> {
            if (x.getKey().equals(y.getKey())) {
                return Integer.compare(x.getValue(), y.getValue()); // Secondary sorting by index
            }
            return Integer.compare(x.getKey(), y.getKey()); // Primary sorting by first value
        });
        
        System.out.println("Sorted Data: " + data);
    }
}

class Pair<K, V> {
    private K key;
    private V value;
    
    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }
    
    public K getKey() {
        return key;
    }
    
    public V getValue() {
        return value;
    }
    
    @Override
    public String toString() {
        return "(" + key + ", " + value + ")";
    }
}
```

## Key Points to Remember
1. **Comparators** control the logic of sorting.
2. **Stability** ensures the relative order of equal elements remains intact.
3. To implement stable sorting with custom comparators, use secondary criteria for tie-breaking.
4. Built-in sort functions (e.g., `Collections.sort`) in Java are stable for objects like lists but not for primitives.
5. never ever assume that x would be present before y in array, no, it may also happen that x is last element and y is first element.
