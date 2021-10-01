~~ space efficient partition ~~

partition(a[], i, j) {
    l = i+1
    r = j
    while (l <= r) {
        while (l <= j && a[l] <= a[i]) l++
        while (r >= i && a[r] > a[i]) r--
        if (l < r) swap(a[l], a[r])
    }
    swap(a[i], a[r])
    return r
}

quick-sort(a[], p, r) {
    if (p < r) {
        q = partition(a[], p, r)
        quick-sort(a[], p, q-1)
        quick-sort(a[], q+1, r)
    }
}
