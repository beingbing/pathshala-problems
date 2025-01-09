### The Need for Tries
We needed a data structure that efficiently manages operations involving strings like:
- Add a string s to the list (no repetitions allowed).
- Delete a string s from the list (only if it exists).
- Find the number of strings in the list that start with a given prefix p.

#### Example:
A list of size n is provided containing strings:
- Adding a string of length l has a time complexity of O(l).
- Deleting a string may require searching through the entire list, leading to a complexity of O(n * l).
- Finding strings with a specific prefix can also take O(n * l).

These complexities can become unmanageable for large datasets. To address this, we use a Trie.
