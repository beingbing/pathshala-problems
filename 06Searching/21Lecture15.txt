~~ allocate the books ~~

until now we saw that BS can be used to solve optimization problems.
other two paradigms which can be used for this type of optimization problems are
dynamic programming and greedy method.

given n books and an array denoting the number of pages each of them have.
given int m, denoting number of students.
we want to allocate n books to m students such that,
1. each student must get atleast 1 book.
2. all the books should be alloted. (this will direct us to implement greedy allocation strategy)
3. allotment must be contiguous.
4. a book will entirely belong to a single student

allocate such that maximum number of pages allocated to any student must be minimum.

if m > n then no allocation will be possible, simply return 0;

min(max number of pages allocated to a student)

here we can see that

students required           inversely proportional to           max number of pages that can be alloted

if we allot all the books successfully then still some students gets left
then, we can always take some books from students which has multiple books and allot it to them,
hence students going back empty handed is not a concerning constraint.

our answer will always be >= max book page count.

so, our low = max element of array
and, high = sum of all the pages of books available

bool isPossible(vector<int>& a, int& mid, int& m) {
    int studentsCnt = 1, pagesSum = 0;
    int n = a.size();
    for (int i{0}; i<n; i++) {
        if (pagesSum + a[i] > mid) {
            studentsCnt++;
            pagesSum = a[i];
        } else {
            pagesSum += a[i];
        }
    }
    return studentsCnt <= m;
}

int low{INT_MIN}, high = 0;
for (int i{0}; i<n; i++) {
    low = max(low, a[i]);
    high += a[i];
}
while (low <= high) {
    mid = (l+h)/2;
    if (!isPossible(a, mid, m)) l = mid+1;
    else {
        if (!isPossible(a, m-1, m)) return mid;
        else h = mid-1;
    }
}
TC = O(nlog(h-l))

In this question we had minimize the max
and in last we had, maximize the min
so, we can conclude that in these type of problems BS is applicable
