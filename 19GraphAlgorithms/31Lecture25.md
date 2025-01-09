# Optimized Union

### Approach 2:
Organize elements which belong to the same set hierarchically. Like in a Tree. Then, our union() operation will have O(log n) time complexity. That's because we just need to find the root of both sets and make root of one set child node of another root. Thing is famously called Union of Disjoint sets.

### What is a Disjoint Set Union (DSU)?
Disjoint Set Union (DSU), also known as Union-Find, is a data structure used to efficiently manage a collection of disjoint sets. It supports two main operations:
1. **Find**: Determine the set (or representative) to which an element belongs.
2. **Union**: Merge two sets into a single set.

### Core Concepts
1. **Representation**:
    - Each element in the DSU is associated with a "parent" pointer.
    - If an element points to itself, it is the representative (or root) of its set.
2. **Union by Rank**:
    - When merging two sets, attach the smaller tree under the larger tree to keep the depth minimal.
3. **Path Compression**:
    - During the `find` operation, flatten the tree structure by pointing all nodes on the path directly to the root. This significantly speeds up future operations.
4. **Time Complexity**:
    - Using both Union by Rank and Path Compression, the operations (`find` and `union`) have an almost constant time complexity, `O(alpha(n))`, where `alpha` is the inverse Ackermann function (extremely slow-growing).

---

### Code
```java
public class DisjointSetUnion {
    private int[] parent;
    private int[] rank;

    // Constructor to initialize the DSU with n elements
    public DisjointSetUnion(int n) {
        parent = new int[n];
        rank = new int[n];
        // Each element is initially its own parent (self-representative)
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Find operation with path compression
    public int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union operation by rank
    public void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    // Check if two elements are in the same set
    public boolean isConnected(int x, int y) {
        return find(x) == find(y);
    }

    // Utility to print parent array (for debugging)
    public void printParents() {
        System.out.print("Parents: ");
        for (int i : parent) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
    
    // Utility to print rank array (for debugging)
    public void printRanks() {
        System.out.print("Ranks: ");
        for (int i : rank) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        // Example usage
        int n = 5; // Number of elements (0 to 4)
        DisjointSetUnion dsu = new DisjointSetUnion(n);

        dsu.union(0, 1);
        dsu.union(1, 2);
        dsu.union(3, 4);

        System.out.println("Connected (0, 2): " + dsu.isConnected(0, 2)); // true
        System.out.println("Connected (0, 4): " + dsu.isConnected(0, 4)); // false

        dsu.union(2, 3);
        System.out.println("Connected (0, 4): " + dsu.isConnected(0, 4)); // true
    }
}
```
