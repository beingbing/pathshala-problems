~~ merge sort ~~

void merge(vector<int>& arr, int s1, int e1, int s2, int e2) {
    int i = s1, j = s2, c = s1
    for (i <= e1 && j <= e2) {
        if (a[i] <= a[j]) tmp[c++] = a[i++]
        else tmp[c++] = a[j++]
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

TC = O(nlogn)
SC = O(n)
