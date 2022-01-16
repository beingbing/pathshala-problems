~~ generic tree traversal ~~

if root is given then we can start our traversal

leaf node will have only one element in its Adjacency List and all other remaining nodes will have
atleast two nodes.
but root node can also have only one node in its Adjacency List, in that case we create a dmy parent
of node and 

// traverse and print nodes
void traverse(vector<vector<int>>& adjacencyList, Node* rootNode, Node* parentNode) {
    if (adjacencyList[rootNode].size() == 1) print(rootNode), return;
    print(rootNode);
    for (j{0}; j < adjacencyList[rootNode].size(); j++) {
        if (adjacencyList[rootNode][j] != parentNode) {
            traverse(adjacencyList, adjacencyList[rootNode][j], rootNode);
        }
    }
}
