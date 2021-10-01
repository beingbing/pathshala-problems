~~ quick sort ~~

what will be the deserving slot of elements once the array is sorted.

partition(a[], p, r) {
    x = a[r]
    i = p-1
    for (j{p}; j<r) {
        if (a[j] <= x) {
            i++
            swap(a[i], a[j])
        }
    }
    swap(a[i+1], a[r])
    return i+1
}

quick-sort(a[], p, r) {
    if (p < r) {
        q = partition(a[], p, r)
        quick-sort(a[], p, q-1)
        quick-sort(a[], q+1, r)
    }
}
