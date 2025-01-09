# First and Last occurrence
## Problem 1
given a sorted array in which elements can be repeated, give the index of the first occurrence of a specified element.

### Solution
In binary search, when we find the target element at `mid`, we check if it’s either the first element or if the previous element is different. If so, it’s the first occurrence. Otherwise, we continue searching in the left half.

```java
public class FirstOccurrence {
    public static int firstOccurrence(int[] arr, int target) {
        int low = 0, high = arr.length - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] > target) high = mid - 1;
            else if (arr[mid] < target) low = mid + 1;
            else {
                if (mid == 0 || arr[mid - 1] != target) return mid; // First occurrence found
                else high = mid - 1; // Move left
            }
        }
        return -1; // Target not found
    }
}
```

## Problem 2
given a sorted array in which elements can be repeated, give the index of the last occurrence of a specified element.

### Solution
When we locate the target at `mid`, we check if it’s either the last element or if the next element is different. If so, we return `mid`. Otherwise, we continue searching in the right half.

```java
public class LastOccurrence {
    public static int lastOccurrence(int[] arr, int target) {
        int low = 0, high = arr.length - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] > target) high = mid - 1;
            else if (arr[mid] < target) low = mid + 1;
            else {
                if (mid == arr.length - 1 || arr[mid + 1] != target) return mid; // Last occurrence found
                else low = mid + 1; // Move right
            }
        }
        return -1; // Target not found
    }
}
```


## Problem 3
given a sorted array in which elements can be repeated, give the frequency of given key.

### Solution
then ans = last-occurrence - first-occurrence + 1

```java
public class FrequencyCount {

    public static int frequency(int[] arr, int target) {
        int first = FirstOccurrence.firstOccurrence(arr, target);
        int last = LastOccurrence.lastOccurrence(arr, target);
        
        if (first == -1 || last == -1) {
            return 0; // Target not found
        }
        return last - first + 1; // Calculate frequency
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 2, 2, 3, 3, 4};
        int target = 2;
        System.out.println("Frequency of " + target + ": " + frequency(arr, target));
    }
}
```

## Complexity Analysis
- **Time**: Each search (first, last) is `O(log n)`, and finding frequency involves two `O(log n)` searches, keeping overall complexity at `O(log n)`.
- **Space**: `O(1)` for all implementations, as they use constant extra space.
