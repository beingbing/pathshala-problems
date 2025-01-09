# PriorityQueue in Java
The **PriorityQueue** class in Java is a part of the **java.util** package. It is a data structure that represents a **min-heap** (by default) or **max-heap** (using a custom comparator). Elements in a PriorityQueue are ordered based on their natural ordering or a custom comparator provided during construction.

## Key Features
1. **Dynamic Resizing**: Automatically resizes as elements are added.
2. **Heap-Based Implementation**: Backed by a binary heap structure.
3. **Partial Order**: The head of the queue is always the smallest (or largest for max-heap) element, but the entire queue isn't fully sorted.
4. **Non-Null Elements**: PriorityQueue does not allow `null` elements.
5. **Thread-Safety**: Not synchronized; use `PriorityBlockingQueue` for concurrent use.
6. **Time Complexity**:
    - **Insertion**: O(log n)
    - **Removal of Head**: O(log n)
    - **Peek (Retrieve Head)**: O(1)

## Constructors
- **Default Constructor**: Creates a PriorityQueue with the default initial capacity (11) and natural ordering.
```java
PriorityQueue<E> pq = new PriorityQueue<>();
```

- **With Initial Capacity**:
```java
PriorityQueue<E> pq = new PriorityQueue<>(initialCapacity);
```

- **With Comparator**:
```java
PriorityQueue<E> pq = new PriorityQueue<>(Comparator<? super E> comparator);
example,
PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
```

- **From Collection**: Initializes the PriorityQueue with the elements of a given collection.
```java
PriorityQueue<E> pq = new PriorityQueue<>(Collection<? extends E> c);
```

## Common Methods
| Method                    | Description                                                                 |
|---------------------------|-----------------------------------------------------------------------------|
| `add(E e)`                | Inserts an element into the queue. Throws `IllegalStateException` if full. |
| `offer(E e)`              | Inserts an element, returns `true` if successful (preferred over `add`).   |
| `poll()`                  | Retrieves and removes the head of the queue, returns `null` if empty.      |
| `peek()`                  | Retrieves but does not remove the head, returns `null` if empty.           |
| `remove(Object o)`        | Removes a single instance of the specified element, returns `true` if removed. |
| `size()`                  | Returns the number of elements in the queue.                               |
| `clear()`                 | Removes all elements from the queue.                                       |
| `toArray()`               | Returns an array containing all elements in the queue.                    |
| `comparator()`            | Returns the comparator used for ordering, or `null` for natural ordering. |

## Example Usage
### Using PriorityQueue with Custom Objects
```java
import java.util.PriorityQueue;

class Student {
    String name;
    int marks;

    Student(String name, int marks) {
        this.name = name;
        this.marks = marks;
    }

    @Override
    public String toString() {
        return name + " (" + marks + ")";
    }
}

public class CustomObjectExample {
    public static void main(String[] args) {
        PriorityQueue<Student> pq = new PriorityQueue<>((s1, s2) -> s2.marks - s1.marks);

        pq.offer(new Student("Alice", 85));
        pq.offer(new Student("Bob", 92));
        pq.offer(new Student("Charlie", 78));

        while (!pq.isEmpty()) {
            System.out.println(pq.poll()); // Prints students in descending order of marks
        }
    }
}
```

### Maintaining a Fixed Size (Top-k Elements):
```java
import java.util.PriorityQueue;

public class TopKElements {
    public static void main(String[] args) {
        int k = 3;
        PriorityQueue<Integer> pq = new PriorityQueue<>(); // Min-heap

        int[] elements = {10, 20, 5, 6, 1, 30, 15};
        for (int elem : elements) {
            pq.offer(elem);
            if (pq.size() > k) {
                pq.poll();
            }
        }

        System.out.println("Top " + k + " elements: " + pq); // Contains top 3 elements
    }
}
```

### **When to Use PriorityQueue**
- **Dijkstra's Algorithm**: For finding the shortest path in graphs.
- **Prim's Algorithm**: For constructing a Minimum Spanning Tree.
- **Job Scheduling**: Prioritize tasks based on importance or deadline.
- **Data Streams**: Maintaining top-k elements in a continuous stream of data.

priority_queue is by default a max-heap. 

priority_queue<int> pq;

pq.top() => get the root element (max element in case of max-heap)

pq.pop() => deleteRoot()

pq.push() => insert(x)

pq.size() => return size;



Q. given an arr[n] and an element k, print k largest elements.
code -
priority_queue<int> pq;
for (i{0}; i<n; i++) pq.push(ar[i]);
int cnt = 0;
while (cnt < k) {
    cout << pq.top();
    pq.pop();
    cnt++;
}
TC = ((k+n)logn)

we can do better -
priority_queue<int> pq(a.begin(), a.end());
int cnt = 0;
while (cnt < k) {
    cout << pq.top();
    pq.pop();
    cnt++;
}
TC = O(n+klogn) ~~ O(n)



Q. given an arr[n] and an element k, print k smallest elements.
code -
priority_queue<int, vector<int>, Comp> pq(a.begin(), a.end());
int cnt = 0;
while (cnt < k) {
    cout << pq.top();
    pq.pop();
    cnt++;
}


Note: priority_queue< data-type, sequential-DS, comparator(user-defined type, not a function)> pq;
e.g. priority_queue<int, vector<int>, 

comparator is an user-defined type which has an overloaded bracket operator.

struct Comp {
    bool operator() (int& a, int& b) {
        // return true, place a after b
        // return false, place a before b
        return a > b; // comparator for min-heap.
    }
}
