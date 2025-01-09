### Introduction to Tries
A Trie (also called a prefix tree) is a tree-based data structure where:
- Each node represents a prefix of a string.
- Every path from the root to a node corresponds to a prefix or a complete string in the list.
- Each node has an isString flag that indicates whether the path from the root forms a valid string in the list.

### Key properties:
- **Efficient Prefix Matching:** Tries allow prefix-based operations in O(l) time, where l is the length of the prefix.
- **Edge Representation:** Each edge represents a character, and a node can have at most 26 edges if we consider lowercase English letters.
- **Space Complexity:** The space required is O(n * l) in the worst case (one node for every character), but it is often much less due to shared prefixes.
