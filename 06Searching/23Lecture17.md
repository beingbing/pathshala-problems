# Family of Boolean Strings
## Problem
Consider a family of strings, where -
1. s[0] = 0,
2. s[i] = s[i-1] + "0" + (s[i-1])`, where, i >= 1
   Given an integer n representing nth string of the family and another integer k representing kth index of nth string. Find the value of k.

### Solution
#### Key Insight
1. Length of each `s[i]` follows a predictable pattern: `2^{i+1} - 1`
2. This structure is important because:
   - The middle element is always `"0"`.
   - The left half of `s[i]` is `s[i-1]`.
   - The right half is the flipped version of `s[i-1]`.
3. With these insights, we can use binary search to avoid generating the entire string. The goal is to use the recursive structure to determine whether to:
   - Traverse left or right based on `k`'s position relative to the middle element.
   - Track bit flips: whenever we move to the right (into `flip(s[i-1])`), we toggle the bit.

#### Code
```java
public class FamilyOfBooleanStrings {

    public int findKthBit(int n, int k) {
        int low = 0; // first character position
        int high = (1 << (n + 1)) - 2;  // last char position
        boolean bit = false;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid == k) return bit ? 1 : 0;
            else if (mid < k) {
                low = mid + 1;
                bit = !bit;  // Flip the bit when moving right
            } else high = mid - 1;
        }

        return bit ? 1 : 0;
    }
}
```

#### Complexity Analysis
- **Time Complexity**: `O(log len)`, `len` is length of nth string, which is `2^(n+1)-1`. Putting the length in we get, `O(log(2^(n+1)-1)`. Thus in terms of `n` the time complexity is `O(n)`.
- **Space Complexity**: `O(1)`, using constant extra space.
