~~ quadruplet sum ~~

given unsorted array with n elements, find distinct quadruplet a, b, c and d with unique indices such that a+b+c = 0

for (i{0}; i<n) {
    if (i>0 and a[i] == a[i-1]) continue;
    else {
        for (j{i+1}; j<n) {
            if (j>i+1 and a[j] == a[j-1]) continue;
            else {
                remSum = -1*(a[i]+a[j])
                p1 = j+1, p2 = n-1
                while (p1 < p2) {
                    if (a[p1]+a[p2] < remSum) p1++
                    else if (a[p1]+a[p2] > remSum) p2++
                    else {
                        print(a[i], a[j], a[p1], a[p2]);
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
    }
}

TC = O(n^3)
