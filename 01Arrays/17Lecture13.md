~~ array rearrangement ~~

Given an integer array containing n elements. It contains only elements from 0 till n-1 but not in sequence. So, given array is permutation of numbers from 0 till n-1. Change this array such that if a[i] == j then a[j] = i.

Example:
Input: [1, 3, 0, 2]
Output: [2, 0, 3, 1]

Approach 1: taking an extra array for solving the problem.
code:
```java
    public int[] transformArray(int[] arr) {
        int n = arr.length;
        int[] result = new int[n];

        for (int i = 0; i < n; i++) {
            result[arr[i]] = i;
        }

        return result;
    }
```

TC: O(n) and SC: O(n)

issue 1: This approach won't work if array contains multiple cycles, also,
issue 2: Why we need extra array, let's try to do the changes in same array ?

Q: why can't i perform the changes within the same array ?
A: If transformation cycle goes through all the elements in the array then we can use existing array. But if not, and if there are multiple cycles present then we need to handle that.

Let's take an example with multiple cycles -
Example:
Input:  [2, 0, 1, 4, 5, 3]
Output: [1, 2, 0, 5, 3, 4]

Approach: 2
So, if we want to use the existing array for transformation, we need to execute every cycle exactly once. Hence, we need to keep track of elements which got involved/touched in a cycle, so that we can start with the next cycle, which are not yet involved. We can do that by keeping a boolean array indicating which all elements got involved in a cycle, so that all cycles present in an array can be executed once.

```java
class Solution {
    public int arrayNesting(int[] nums) {
        int n = nums.length;
        boolean[] visited = new boolean[n];
        int maxLength = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int length = 0;
                int current = i;

                while (!visited[current]) {
                    visited[current] = true;
                    current = nums[current];
                    length++;
                }

                maxLength = Math.max(maxLength, length);
            }
        }

        return maxLength;
    }
}
```

```java
class Solution {
    public int arrayNesting(int[] nums) {
        int n = nums.length;
        int maxLength = 0;

        for (int i = 0; i < n; i++) {
            int cycleLength = 0;
            if (nums[i] >= 0 ) {
                int currentIndex = i, nextIndex = nums[i];
                while (nextIndex != i) {
                    int futureNext = nums[nextIndex];
                    nums[nextIndex] = -1 * (currentIndex + 1);
                    currentIndex = nextIndex;
                    nextIndex = futureNext;
                    cycleLength++;
                }
                nums[i] = -1 * (currentIndex + 1);
                cycleLength++;
                maxLength = Math.max(maxLength, cycleLength);
            }
        }
        return maxLength;
    }
}
```

The problem here is we still can not do away with need for an extra array.

To not use any extra array, we need to transform the element got involved in a cycle to something which is easily recognizable for already being involved in a cycle.
constraints for transformation are -
- all elements are already positive
- all elements are < n

so, modify all the elements which got involved in a cycle by changing an element x to -(x+1). And once all elements are transformed into negatives, again transform back all the elements x to (x*(-1))-1.

code:
```java
// limitations: it still uses a lot of vars and loops
void rearrangeM2(int[] nums) {
    int n = nums.length;
    for (int i = 0; i < n; i++) {
        if (nums[i] >= 0) {
            int nwVal = i, idx = nums[i];
            while (idx != i) {
                int temp = nums[idx];
                nums[idx] = -1 * (nwVal + 1);
                nwVal = idx;
                idx = temp;
            }
            nums[i] = -1 * (nwVal + 1);
        }
    }
    for (int i = 0; i < n; i++) nums[i] = -1 * nums[i] - 1;
}
```

TC: O(n) and SC: O(1)

issue 1: too complicated and uses a lot of variables and operations

Approach 3:
We were jumping between indices and needed to run a cycle, because without running all elements together, if we just replace old value with new value and do this operation in sequential iteration then some old values will forever get lost.

So, if we can modify existing array without loosing old values of replaced cells, then we can go through sequential iteration without needing to jump between indices to run through a cycle.

So, if during transformation we replace the old value with something which keeps information of both old value and new value, then once all the tranformations are done, we can retrieve array with new values back from those intermediate values.

so, intermediary value can be defined as - (n * new_val) + old_val

so, intermediate transformation will be - a[old_val] = (n * j) + a[old_val]

code:
```java
void rearrangeM3(int[] nums) {
    int n = nums.length;
    for (int i = 0; i < n; i++) {
        int oldVal = nums[i] % n;
        nums[oldVal] = nums[oldVal] + n * i; // a[a[i] % n] += i * n;
    }
    // divide with n, old_val will be discarded and new_val is what you get
    for (int i = 0; i < n; i++) a[i] /= n;
}
```

TC: O(n)
SC: O(n)

issue 1: if numbers are too big then overflow can occur
