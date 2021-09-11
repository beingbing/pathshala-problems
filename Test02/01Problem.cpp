/*

given array of N integers, count total number of special pairs in all the subarrays of given array
such that,
 (A[i], A[j])  is wher i < j  and A[i] == A[j]

Input: given array size and it;s elements

output: count of special pairs

i/p:
5
1 1 2 2 1

o/p:
13

*/

/*

Answer:
M1

    element, indices where that element was present
map<int, vector<int> mp

ans += (n-i)

n = total number of elements
i = element stored in vector<int>


M2
above map can be optimezed as,
element, pair<frequency of element found, sum of indices at which that element was found>>
map<int, pair<int, int>>

ans += freq*n - sum(indices)
*/