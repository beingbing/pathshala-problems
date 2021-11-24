~~ solve the equation ~~

given an int arr of distinct n elements.
find the number of sextuples satisfying -
(a*b+c)/d - e = f
elements can be repeating in the equation

let the equation be a*b+c = (f+e)*d

cnt1 = 0
for (i{0}; i<n; i++)
    for (j{0}; j<n; j++)
        for (k{0}; k<n; k++) {
            lhsArr[cnt1] = a[i]*a[j]+a[k];
            cnt1++
        }
cnt1 = 0
for (i{0}; i<n; i++)
    for (j{0}; j<n; j++)
        for (k{0}; k<n; k++) {
            if (a[k] != 0) {
                rhsArr[cnt1] = (a[i]+a[j])*a[k];
                cnt1++
            }
        }

now sort rhsArr and for every element of lhsArr use BS and find its frequency in rhsArr

TC = O((n^3)logn)
SC = O(n^3)
