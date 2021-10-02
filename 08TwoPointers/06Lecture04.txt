~~ subarray sum ~~

non negative integer arr with n elements, given variable k, if any subarray sum == k then return true
otherwise return false

i = 0, j = 0, curSum = a[0]
while (j < n) {
    if (curSum < k) {
        j++
        if (j < n) curSum += a[j]
    } else if (curSum > k) {
        curSum -= a[i]
        i++
        if (i > j) {
            j++
            if (j < n) cur = a[j]
        }
    } else return true; // {i, j}
}
return false; // -1

TC = O(n)
