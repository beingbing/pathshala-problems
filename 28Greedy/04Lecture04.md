~~ Activity Selection - 3 ~~

given n Activities with start time and end time and k persons. every person can perform only one Activity
at a time, find max number of activities that can be performed.

given endTimes of all the activities that are being performed to assign the next activity, we need to know
all the activities whose endTime is <= startTime(next)

k -> index at which we need to update the endTime of next coming activity

for every activity i:
    int maxm = -INF, k = -1;
    for (j{0}; j < k) {
        if (endTime[j] < start[i]) {
            maxm = max(maxm, end[j]);
            k = j;
        }
    }
    if (k != -1) {
        endTime[k] = end[i];
        ans++;
    }
TC = O(nk)
we can improve it.

if we would have needed maxm of all the elements available, then we could easily get that using a
maxHeap, but we need a max from a subset of elements. A subset in which all the elements <= val.
so, we do not need heap, but we could have used binary-search if the array would have been sorted, but
as it is not so we couldn't use that either.

at this time we need to remember that there are two types of maps ordered and unordered. Ordered map in
particular is designed using a balanced-binary-search-tree. and in that search operation is logn.

lower_bound(val) - out of all the elements which are >= val, return pointer to smallest such value.
upper_bound(val) - out of all the elements which are > val, return pointer to smallest such value.

ordered_map() (internally implemented using balanced BST) can perform both above functions.

in ordered_map, ordereing is done on keys and keys need to be distinct.

    {endTime, freq}
map<int, int> endTimes;
endTimes[0] = k;
for (int i{0}; i<n) {
    auro itr = endTimes.upper_bound(start[i]);
    if (itr != endTimes.begin()) {
        itr--;
        endTimes[itr->first]--;
        if (!endTimes[itr->first]) endTimes.erase(itr);
        endTimes[end[i]]++;
        ans++;
    }
}
return ans;
TC = O(nlogk)
SC = O(k)
