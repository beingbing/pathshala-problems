~~ distinct rectangles ~~

given sorted array with distinct elements, find no of rectangles (or squares) with distinct configurations that can be formed using array
elements such that area < B, B is given.

distinct -> 1x7 is different from 7x1

ans = 0, i = 0, j = n-1
while (i <= j) {
    if (a[i]*a[j] >= B) j--
    else {
        l = j-i+1
        ans += 2l-1
        i++
    }
}

TC = O(n)
