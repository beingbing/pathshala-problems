# Distinct Rectangles
## Problem
You are given a sorted array of size n with distinct elements. Find count the number of **distinct rectangles (or squares)** that can be formed using array elements as dimensions, such that their **area** is less than a given value B. A rectangle of dimensions `h * w` is considered distinct from `w * h`.

### Code
```java
public class DistinctRectangles {
    public static int countDistinctRectangles(int[] arr, int B) {
        int n = arr.length;
        int i = 0, j = n - 1, count = 0;

        while (i <= j) {
            // Calculate area using the two pointers
            if (arr[i] * arr[j] >= B) {
                j--; // Reduce the larger dimension
            } else {
                // Calculate number of valid configurations
                int length = j - i + 1;
                count += 2 * length - 1; // Count all configurations
                i++; // Move to the next smaller dimension
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 5, 7}; // Sorted distinct elements
        int B = 15; // Area threshold
        System.out.println("Number of distinct rectangles: " + countDistinctRectangles(arr, B));
    }
}
```

### Complexity
- **Time:** O(n)
- **Space:** O(1)

## Example Walkthrough

### Input:
- Array:  [1, 2, 3, 5, 7] 
- Area threshold ( B ):  15 

### Execution:
1. Start with  i = 0 ,  j = 4  (elements  1  and  7 ):
    -  1 \times 7 = 7 < 15 :
        - Count  2 \times (4 - 0 + 1) - 1 = 9 .
        - Increment  i  to 1.
2.  i = 1 ,  j = 4  (elements  2  and  7 ):
    -  2 \times 7 = 14 < 15 :
        - Count  2 \times (4 - 1 + 1) - 1 = 7 .
        - Increment  i  to 2.
3.  i = 2 ,  j = 4  (elements  3  and  7 ):
    -  3 \times 7 = 21 \geq 15 :
        - Decrement  j  to 3.
4.  i = 2 ,  j = 3  (elements  3  and  5 ):
    -  3 \times 5 = 15 \geq 15 :
        - Decrement  j  to 2.
5.  i = 2 ,  j = 2  (element  3 ):
    -  3 \times 3 = 9 < 15 :
        - Count  2 \times (2 - 2 + 1) - 1 = 1 .
        - Increment  i  to 3.

### Output:
- Total count:  9 + 7 + 1 = 17 .

---
