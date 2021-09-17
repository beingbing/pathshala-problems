~~ peak element ~~

given an unsorted array, find any peak element

for a peak element,

a[i-1] <= a[i] >= a[i+1]

low = 0, high = n-1
while (low <= high) {
    int mid = low + (high - low)/2
    if (mid == 0) {
        if (a[mid] >= a[mid+1]) return mid;
        else return mid+1;
    } else if (mid == n-1) {
        if (a[mid-1] <= a[mid]) return mid;
        else return mid-1;
    } else {
        if (a[mid-1] <= a[mid] && a[mid] >= a[mid+1]) return mid;
        else if (a[mid] < a[mid+1]) low = mid + 1;
        else if (a[mid-1] > a[mid]) high = mid - 1;
    }
}

we apply Binary Search when there is a condition separating the left and the right halves of the answer.
