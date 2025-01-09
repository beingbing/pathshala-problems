# Searching
When solving search problems, understanding how the search space reduces with each iteration helps in deducing recurrence/iterative equation for Time Complexity (TC) analysis of the algorithm. Generally,
```
     T(n) = T(n-k) + c
 or, T(n) = T(l) + c
```
where:
- k + l = n
- k, the amount by which search space is reduced after every iteration.
- l, the amount of search space left to search into after every iteration.

## Key Concepts
When performing a search, we need:
1. **Search Key**: The item we’re looking for.
2. **Search Space**: The collection in which we search for the item.

For performance analysis, **Time Complexity** (TC) is measured in the worst-case scenario, assuming we examine the full search space of n elements, then it will be O(n), which is called linear search.

### Linear Search
In linear search, we check each item one by one. Therefore, after each iteration, our search space reduces by one until we find the target or exhaust the array. Its recurrence relation can be represented as:
```
T(n) = T(n - 1) + c
```
where:
- `T(n)` = time taken to search a collection of size n.
- `T(n-1)` = time needed to search after one item is removed, or one iteration is completed.
- `c` = constant work done per iteration.

#### Code
```java
public int linearSearch(int[] arr, int key) {
    for (int i = 0; i < arr.length; i++) if (arr[i] == key) return i;  // Key found at index i
    return -1;  // Key not found
}
```

### Can Searching be Improved?
Linear search is inefficient for large datasets. To improve search efficiency, two critical insights were identified:
1. **Ordered Search Space**: If the search space is sorted/ordered in some way, it provides intuition about the likely position of the key.
2. **Divide and Conquer**: Based on the order, if we land on some middle element, we can determine if the key lies in the left or right half of the search space, allowing us to eliminate half of the remaining elements in each step.

These insights lead to **Binary Search**, which leverages sorted data to cut the search space in half with each step, leading to significantly faster performance.

### Binary Search
Binary Search works only on sorted data. Here’s the algorithm:
1. Set pointers: **low** at the start and **high** at the end of the array.
2. In each iteration, calculate the middle index:
```
    mid = low + (high - low)/2
```
3. Check if the middle element matches the search key `k`:
    - If `a[mid] == k`, return `mid` (found).
    - If `a[mid] > k`, discard the right half by setting `high = mid - 1`.
    - If `a[mid] < k`, discard the left half by setting `low = mid + 1`.
4. Repeat until `low` exceeds `high` (i.e., the target is not found).

#### Recurrence Relation
In Binary Search, each iteration reduces the search space by half:
```
T(n) = T(n / 2) + c
```
where:
- `T(n)` = time taken to search a collection of size n.
- `T(n / 2)` = time taken after reducing the search space by half.
- `c` = constant work done per iteration.

#### Code
```java
public class BinarySearch {
    public static int binarySearch(int[] arr, int key) {
        int low = 0, high = arr.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key) return mid;  // Key found at index mid
            else if (arr[mid] > key) high = mid - 1;  // Focus on the left half
            else low = mid + 1;   // Focus on the right half
        }
        return -1; // Key not found
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 7, 9};
        int key = 5;
        int result = binarySearch(arr, key);

        if (result != -1) System.out.println("Element found at index " + result);
        else System.out.println("Element not found in array.");
    }
}
```

#### Complexity
- **Time Complexity**: `O(log n)` since each iteration halves the search space.
- **Space Complexity**: `O(1)` if iterative, `O(log n)` if recursive due to stack depth.
