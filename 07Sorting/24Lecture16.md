~~ inversion count ~~

given int arr of n elements, find number of pairs i, j such that
- i < j
- a[i] > a[j]
- 0 <= i,j < n

inversion-count(0, n-1) = inversion-count(0, m) + inversion-count(m, n-1) + inter-array-inversion-count(0, m, m+1, n-1)

so, we just need to make a small change in our previous code to be able to calculate it -

void merge(vector<int>& arr, int s1, int e1, int s2, int e2) {
    int i = s1, j = s2, c = s1
    for (i <= e1 && j <= e2) {
        if (a[i] <= a[j]) tmp[c++] = a[i++]
        else {
            cnt += e1 - i + 1                       ## change
            tmp[c++] = a[j++]
        }
    }
    for (i <= e1) tmp[c++] = a[i++]
    for (j <= e2) tmp[c++] = a[j++]
    for (i = s1; i<= e2) {
        a[i] = tmp[i];
    }
}

void mergeSort(arr, i, j) {
    if (i == j) return;
    m = (i+j)/2
    mergeSort(arr, i, m);
    mergeSort(arr, m+1, j)
    merge(arr, i, m, m+1, j);
}

higher the inversion count, the more unsorted the arr is, according to our conditions.
