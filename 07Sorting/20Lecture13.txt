~~ merge process ~~

given two int arrs, with m and n elements, both of them are sorted in increasing order
create arr3 with size = size1+size2 in sorted order

this is also called as merge process, as we are merging two sorted arrays.

vector<int> a3(m+n)
i = 0, j = 0, c = 0
while (i < m && j < n) {
    if (a1[i] <= a2[j]) a3[c++] = a1[i++]
    else a3[c++] = a2[j++]
}
while (i < m) a3[c++] = a1[i++]
while (j < n) a3[c++] = a2[j++]

TC = O(m+n)
