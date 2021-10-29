~~ priority queue ~~

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
