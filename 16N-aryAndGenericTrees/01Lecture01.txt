~~ Introduction and representation ~~

a tree is acyclic and a tree with n nodes will always have n-1 edges

generic n-ary trees:
as any node can have any number of children with it, so we can not define a tree-node with a specific
amount of pointers, it is only at runtime we will know as how many pointers are needed for children
hence unlike binary tree where we had *left and *right as pointers for two possible children that
node can have, we will be using an *arr[n] where each element of array will be a pointer to the
children.

but not all nodes will have n children, as for a tree with E edges there can be atmost (2n-2) entries
hence it is useless to keep a matrix of n^2. Instead, we will have a vector<vector<int>>
which will be denoted as "Adjacency List".

so, to create an Adjacency list from an input of edges.

vector<vector<int>> adjacencyList(n+1);

for (int i{1}; i<=n; i++) {
    cin >> startNode >> endNode;
    adjacencyList[startNode].push_back(endNode);
    adjacencyList[endNode].push_back(startNode);
}
