~~ prefix match problem ~~

Lets discuss first how need of trie originated and it is created.

suppose we need to design a DS that supports -
- add a string s to your list of strings. (no repetation allowed)
- delete a string s from your list of strings. (for deletion, string should be present)
- to find number of strings in the list that has p as prefix.

suppose a list of strings is given of size n -
- add a string of size l to this list.
TC = O(l)
- delete a string s from that list.
TC - O(n*l)
- find a list of strings matching given prefix p
TC = O(n*l)

the above results will be in normal circumstances. We can not afford this much complexities hence
we came up with trie.
