~~ count sort ~~

non comparison based sorting algortithm

5   7   1   4   5   5   7   4

find frequecy of all elements

1   4   4   5   5   5   7   7

use frequecy array of size max element value which can be present in given array

con -> max value can be very large

TC = O(maxVal)
SC = O(maxVal)


for negative elements -
- find the smallest element
- put that smallest array @ 0th index and then put all others with the same offset ( - minEle )

we can do above trick with positive elements as well ( - minEle)

we can do above trick with max element as well, so our frequecy array size becomes max-min+1

but still after doing all those things we will be iterating on frequecy array, which is futile
as our original array might be 3 elements long but their magnitude can make frequecy array
variably big,
so, to resolve this issue -
- traverse over original array and create frequecy array
- create a cumulative array with that frequecy array
- traverse over original array again and use cumulative array value as sorted index of final
answer and keep decrementing them by 1 after each iteration.


input:  1   4   1   2   7   5   2
vals:   1   2   3   4   5   6   7
freq:   2   2   0   1   1   0   1

cum:    2   4   4   5   6   6   7

        1   3       4   5       6
        0   2

code -
int freq[max-min+1] = {0}
for (i{0}; i<n) freq[a[i]-min]++
for (i{1}; i<max-min+1) freq[i] += freq[i-1]
for (i{0}; i<n) {
    ans[freq[a[i]-min]-1] = a[i]
    freq[a[i]-min]--
}

SC = O(max(n, max-min))
TC = O(max(n, max-min))

it do not maintain order if you start from oth index, instead start from end while creating ans arr
