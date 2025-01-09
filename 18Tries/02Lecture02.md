~~ introduction to tries ~~

Trie is also known as prefix tree because every node in the tree represents a prefix of a string
introduced in the list.

every root to leaf path represents a string present in the given list.

every node also has a variable isString present which denotes if the current path followed up until
now is making a valid string which is present in the list of not.
so, trie DS stores all the strings of given list in the form of a tree from root to some other node.

hence, every new edge represents one new character introduced in the prefix string till that point.
so, how many edges at max can a node has -
if we consider all lowercase letters can be the only candidates of the string then maximum count
of edges from any node will be 26.

space taken by any trie of above explained kind -
size = O(n*l) (in worst case scenario)
but normally it is much less.
