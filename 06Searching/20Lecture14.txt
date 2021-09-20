~~ place the cows ~~

a farmer has n stalls, located at some position on number line.
1 cow at 1 slot.
given c, number of cows.
n >= 2
c >= 2
n >= c
place c cows at n stalls such that min distance between any two adjacent cows is max.

assume min distance to be d.

so, if we can start d from (min distance between any two adjacent stalls) till the max possible value
that d can attain (which is maximum distance between any two stalls) then we can have a
domain in which we can look for monotonicity.

now, 
whatever is best possible option for you right now, do it currently, as soon as possible, this is
greedy approach.

so,
if we do placement of cows according to greedy approach then it is possible that we are able to
satisfy distance constraint.

so, if a distance constraint is satisfied then look for a bigger distance constraint otherwise
shorten it till you find your answer.
here we can see that we have a function which can decide in which direction to move.

This approach is known as BS on answer.

bool isPossible(vector<int>& a, int& m, int& c) {
    int n = a.size(), pre = a[0], cnt = 1;
    for (int i{1}; i<n; i++) {
        if (a[i] - pre < m) continue;
        else {
            cnt++;
            pre = a[i];
        }
    }
    return cnt >= c;
}

sort(a.begin(), a.end()) // if array is not sorted
int low{INT_MAX}, n = a.size(), high = a[n-1]-a[0];
for (int i{1}; i<n; i++) low = min(low, a[i]-a[i-1])
while (low <= high) {
    m = (l+h)/2;
    if (!isPossible(a, m, c)) h = m-1;
    else {
        if (!isPossible(a, m+1, c)) return m;
        else l = m+1;
    }
}

TC = O(nlog(h-l))
