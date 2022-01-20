~~ graph representation ~~

adjacency list -

struct Node {
    int val;
    vector<Node*> adj; // adjacency list
}

in this case, degree of a node i will be i->adj.size();

in adjacency list representation how much space we require to represent a graph.
we would assume that if number of nodes are v then in worst case we can require v^2 space, in case
all the nodes are connected to all other nodes. but it doesn't happen in real world. there are not
this many connection and we also do not represent only in terms of nodes we take in account number
of edges e too.

so, in order to calculate space required, we know that sum of size of adjacency-lists of all the
nodes will give us the required space taken, but, we know that,
sum of size of adjacency-lists of all the nodes gives us total degree of the graph, and,
degree of graph is equal to 2*e.
so, it implies, we can conclude,
the space required is 2*e.
but that's not the end of the story,
if we have a graph with no nodes then, in this case we have size as v but according to our conclusion
we will get size to be 2*e = 0, which is wrong,
so,
the space required = v + 2*e
but we ignore the constant, hence,
SC = O(v + e)

while traversing, we need to check the adjacency list of all the nodes which again brings us to the
above derivation, but this time it is for finding time complexity.
hence, TC = O(v + e)

in a complete graph, e = vC2 = v*(v-1)/2 which gives, e = v^2 so TC and SC becomes O(v^2)

adjacency matrix -

it's a matrix representation in which mat[i][j] = 1 if there is an edge between i and j, otherwise it
will be 0.
degree of node i = sum of adj[i]
SC = O(v^2) (size of matrix)
TC = O(v^2) (size of matrix)

Note: in case of weighted graph the adjacency list will have pair instead of single node, in which,
(node, weight)
