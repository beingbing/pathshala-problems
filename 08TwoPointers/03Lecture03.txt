~~ pair difference ~~

given an array of n elements and a value 'diff' find all the pairs whose difference is 
equal to diff. i != j

M1 -
brute force
- run two loops and check for all pairs
TC = O(n^2)

M2 -
- sort it

i = 0, j = 1
while (j < n) {
    cur = a[j] - a[i]
    if (cur < diff) j++
     else if (cur > diff) {
         i++
         if (i == j) j++
     } else return true;
}

TC = O(n)

Note: if diff is negative, do cur = a[i] - a[j] and change if else conditions of > and <

Note: if questions ask about all the pairs

-> if repeatations are allowed, then count all occurence apply rule of product.

-> edge case: diff = 0

i = 0, j = 1, c = 0
while (j < n) {
    cur = a[j] - a[i]
    if (cur < diff) j++
    else if (cur > diff) {
        i++
        if (i == j) j++
    } else {
        c1 = 0, c2 = 0, p = a[i], q = a[j]
        if (diff == 0) {
            while (a[i] == p) c1++, i++, j++
            c += c1(c1-1)/2
        } else {
            while (a[i] == p) c1++, i++
            while (a[j] == q) c2++, j++
            c += c1*c2
        }
    }
}
