~~ processing queries ~~

given int arr of size n.
int q has queries which has a single integer
print true for if that integer exist in array and false otherwise.

M1 -
search for each query in array (it will be a linear search if not sorted)
so TC = O(qn)
SC = O(1)

M2 -
if sorted then BS can be applied -
TC = O((q+n)logn)
SC = O(1)


M3 -
we can use unordered_map<ele of array, anything(0)>
create a ht from arr, then for every query amortized time become O(1)
TC = O(q+n)
SC = O(n)

code -
for (auto ele : arr) ht[ele] = 0;
for (auto q : queries) {
    cin >> x;
    if (ht.find(x) != ht.end()) return true;
    else return false
}
