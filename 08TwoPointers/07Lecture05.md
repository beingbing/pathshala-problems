# triplet sum

given unsorted array with n elements, find distinct triplet a, b and c with unique indices such that a+b+c = 0

- sort array

for (i{0}; i<n) {
    if (i > 0 && a[i] == a[i-1]) continue
    else {
        remSum = -1*a[i]
        p1 = i+1, p2 = n-1
        while (p1 < p2) {
            if (a[p1]+a[p2] < remSum) p1++
            else if (a[p1]+a[p2] > remSum) p2++
            else {
                print(a[i], a[p1], a[p2]);
                if (a[p1] == a[p2]) break;
                else {
                    x = a[p1], y = a[p2]
                    while (a[p1] == x) p1++
                    while (a[p2] == y) p2--
                }
            }
        }
    }
}

TC = O(n^2)
