# pair sum - 2 ~~

given an array and a sum, find two numbers in array whose sum equals sum.
such that a[i] + a[j] = sum, where i != j
find count of such pairs

code -
i = 0, j = n-1
while(i<j) {
    sum = a[i] + a[j]
    if (k > sum) i++
    else if (k < sum) j--
    else {
        if (a[i] == a[j]) {
            l = j - i + 1
            ans += l(l-1)/2
            break;
        }
        int v1 = a[i], v2 = a[j]
        while (a[i] == v1) i++, c1++
        while (a[j] == v2) j--, c2++
        ans += c1*c2
    }
}

TC = O(n)
