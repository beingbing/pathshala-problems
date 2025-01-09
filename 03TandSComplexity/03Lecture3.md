~~ Interesting code snippets ~~

Q1.
void func (int n) {
    int i = 0, j = 0;
    for (; i<n && j<n; ) {
        if (i == j) {
            i++;
            j = 0;
        } else j++;
    }
}

    i:  0  1    2      3                ....        n-1

    j:  0  0 1  0 1 2  0 1 2 3          ....        0 1 2 3 ... n-1

no of:  1   2   3       4                           n
operations

as we have seen earlier,
TC = O(n^2)




Q2.
int a = 0, i = n;
while (i > 0) {
    a += i;
    i /= 2;
}

    i: n    n/2     n/4     n/8     n/16     ...     1       0

no of: c    c       c       c       c       ...     c
operations

so, total number of operations = c + c + c + c + c ... x times
where,
x is number of times the loop runs
so,
if after 1st step i is n/2, after 2nd it is n/4, after 3rd it is n/8, ... goes on, then,
after x steps i will be n/(2^x)

so when n/(2^x) will become 1, the loop will stop
so,
        n/(2^x) = 1
=>      n = 2^x
taking logs of 2 both sides we get,

=>      log n = x
so,
so, total number of operations = c + c + c + c + c ... (log n) times

=>  total number of operations = c* (1+1+1+.... logn times) = c*(log n)
so,
time taken = O(log n)



M2 (using recurrence relation) -

    T(n) = T(n/2) + c

=>  T(n) = T(n/4) + 2c

=>  T(n) = T(n/8) + 3c

    ... goes on and become

=> T(n) = T(n/(2^x)) + c*(1+1+1 ... x times)

so, if n/(2^x) = 1  =>   x = log n, hence, the above equation becomes -

=> T(n) = T(1) + c*(1+1+1 ... logn times)   , here, T(1) will again be a constant operation, so,

=> T(n) = c*(logn)

=> T(n) = O(logn)




Q3.
for (int i{1}; i<=n; i++)
    for (int j{1}; j<=i; j *= 2)
        cout << i << " " << j;

    i:  1   2       3       4       5       6       7       8       ....    n

    j:  1   1 2     1 2     1 2 4   1 2 4   1 2 4   1 2 4   1 2 4 8 ....    1 2 4 8 ... (2^x)

no of:  1   2       2       3       3       3 (log6) 3 (log7) 4 (log8)        x (x = logn)
operations

so, total number of operations = log1 + log2 + log3 + .... + logn = log (1*2*3...n) = log(!n)

and !n ~= (n^n), so,

    total number of operations = n*logn

time taken = O(nlogn)




Q4.
int c = 0;
for (int i{n}; i>0; i /= 2)
    for (int j{0}; j<i; j++)
        cout ;

    i:  n           n/2             n/4             n/8             ....    2       1

    j:  1 2 ... n   1 2 ... n/2     1 2 ... n/4     1 2 4 ... n/8   ....    1 2     1

no of:  n           n/2             n/4             n/8                     2       1
operations

so, total number of operations = n + n/2 + n/4 + n/8 + ... + 3 + 2 + 1

=> T(n) = n (1 + 1/2 + 1/4 + 1/8 + ...)

formula for sum of infinite GP is Sn = a / (1-r), here, a is first term and r = common difference

so, T(n) = n * (1/(1/2)) = 2*n

=> T(n) = O(n)



Note:
1. sum of reciprocal of primes numbers till n is loglogn
2. sum of reciprocal of all natural numbers till n is logn