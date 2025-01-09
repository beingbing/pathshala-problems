~~ Binary Search ~~

Whenever we search something, we has two things -
1. search key
2. search space

when we talk about TC, we mean worst case, hence going through the complete search space, but,
while doing a searching problem,
keep track of by what amount your search space is reduced after every iteration, which will make
your recurence/iterative equation, which in turn will help you deduce your TC.

hence, suppose, you are performing a linear search on an array, then, after every iteration your
search space is reduced by 1 unit, and while going through that iteration, suppose, you perform,
c amount of work, then your recurence equation becomes -
                    T(n) = T(n-1) + c
here,
T(n) is the amount of time taken while going through the search space,
T(n-1) is the amount of time that will be taken to go through a search space which is reduced by
the amount left after completing 1 iteration (which in this case is 1), so, in generic terms,
                    T(n) = T(n-k) + c      or,  T(n) = T(l) + c
here, k + l = n,
k, the amount by which search space is reduced after every iteration.
l, the amount of search space left to search into after every iteration.


To search is a very huge task of our day to day life, so, to make it efficient, 2 points were noted -
1. if search space is sorted/ordered in some order then it will give us an intution regarding our search.
2. if we always look fo a middle element, and then decide which portion of remaining search space can
contain our answer.

These lead us to binary search.
if search space = n, and key to search for is k

low = 0, high = n-1
while (low <= high) {
    mid = low + (high - low)/2;
    if (a[mid] == k) return mid;
    else if (a[mid] > k) high = mid-1;
    else low = mid+1;
}
return -1;

TC = O(logn)
