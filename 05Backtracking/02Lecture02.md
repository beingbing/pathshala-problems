# permutations of a string - 2
Swapping string characters losses the relative order of characters in the permuted string in that subtree. Hence, to maintain relative ordering within a subset of characters or when cyclic shifts are required as part of the constraints, an alternative to swapping would be to perform rotation.
## Code
```java
public class RotationalPermutations {

    private void rightRotate(char[] chars, int i, int j) {
        char temp = chars[j];
        for (int idx = j; idx > i; idx--) chars[idx] = chars[idx - 1];
        chars[i] = temp;
    }

    private void leftRotate(char[] chars, int i, int j) {
        char temp = chars[i];
        for (int idx = i; idx < j; idx++) chars[idx] = chars[idx + 1];
        chars[j] = temp;
    }

    private void generatePermutations(char[] chars, int index, List<String> result) {
        if (index == chars.length) {
            result.add(new String(chars));
            return;
        }

        for (int toSwapIdx = index; toSwapIdx < chars.length; toSwapIdx++) {
            rightRotate(chars, index, toSwapIdx);  // do
            generatePermutations(chars, index + 1, result);  // recurse
            leftRotate(chars, index, toSwapIdx);  // undo
        }
    }

    public List<String> permute(String s) {
        List<String> result = new ArrayList<>();
        generatePermutations(s.toCharArray(), 0, result);
        return result;
    }

    public static void main(String[] args) {
        RotationalPermutations permuter = new RotationalPermutations();
        System.out.println(permuter.permute("abc"));  // Expected output: [abc, acb, bac, bca, cab, cba]
    }
}
```
## Complexity
- **Time Complexity**: `O(n!)` for generating all permutations, where `n` is the length of the string.
- **Space Complexity**: `O(n)` for the recursion stack and auxiliary space used for swaps.
