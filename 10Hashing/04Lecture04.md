# Processing Queries
## Problem
Given an integer array of size n and q queries, where each query contains a single integer, determine if that integer exists in the array. For each query, print `true` if the integer exists and `false` otherwise.

### Solution Approaches
### Approach 1: Linear Search
#### Explanation
- For each query, iterate through the array and check if the query integer matches any element.
- This approach works even if the array is unsorted.
#### Complexity
- **Time:** For q queries, we perform a linear search over n elements: `O(qn)`
- **Space:** O(1) as no extra data structures are used.
#### Code
```java
public static void processQueriesLinear(int[] arr, int[] queries) {
    for (int x : queries) {
        boolean found = false;
        for (int ele : arr) {
            if (ele == x) {
                found = true;
                break;
            }
        }
        System.out.println(found);
    }
}
```
### Approach 2: Binary Search (For Sorted Array)
#### Explanation
1. Sort the array (if it is not already sorted).
2. For each query, apply binary search to check if the integer exists.
#### Time Complexity
- Sorting the array: `O(n log n)`
- Processing q queries with binary search: `O(q log n)`
- Overall: `O((n + q) log n)`
#### Space Complexity
- `O(1)`, assuming sorting is done in place.
#### Code
```java
import java.util.Arrays;

public static void processQueriesBinarySearch(int[] arr, int[] queries) {
    Arrays.sort(arr); // Ensure the array is sorted
    for (int x : queries) {
        System.out.println(binarySearch(arr, x));
    }
}

private static boolean binarySearch(int[] arr, int target) {
    int low = 0, high = arr.length - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return true;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
```
### Approach 3: Hash Table (Using `HashMap`)
#### Explanation  
1. Preprocess the array into a hash table, where each element is stored as a key.  
2. For each query, check if the integer exists in the hash table.  
3. Hash table lookup is `O(1)` on average due to its amortized time complexity.
#### Time Complexity  
- Constructing the hash table: `O(n)`  
- Processing `q` queries: `O(q)`  
- Overall: `O(n + q)`
#### Space Complexity  
- `O(n)` to store the hash table.
#### Code
```java
import java.util.HashSet;

public static void processQueriesHashing(int[] arr, int[] queries) {
    HashSet<Integer> hashTable = new HashSet<>();
    for (int ele : arr) {
        hashTable.add(ele);
    }

    for (int x : queries) {
        System.out.println(hashTable.contains(x));
    }
}
```

## Summary of Approaches  

| **Approach**              | **Time Complexity**  | **Space Complexity** | **Conditions**         |
|---------------------------|----------------------|-----------------------|------------------------|
| **Linear Search**          | \( O(qn) \)          | \( O(1) \)            | Works for any array    |
| **Binary Search**          | \( O((n+q) log n) \) | \( O(1) \)          | Requires sorted array  |
| **Hash Table**             | \( O(n+q) \)         | \( O(n) \)            | Requires extra space   |  

For optimal performance, use **Hash Table** for large inputs. Use **Binary Search** if the array is already sorted and you prefer minimal space usage.  
