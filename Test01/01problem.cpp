/*

given first two terms A and B of a Fibonacci series

calculate GCD of Mth and Nth elements of the sequence, where N and M are any two
consecutive indices.

Input format:
1. The first line of input contains a single integer T, the number of test cases.
2. The second line contains four integers A, B, N and M.
3. A - first element of the sequende, B - second element of the sequence,
M, N - Mth and Nth index element of sequence

N and M are adjacent indices

*/

/*

Answer:
GCD of any consecutive index will be same, = GCD of 1st and 2nd number

gcd of any two consecutive fibonacci number can be calculated by subtracting the smaller
number from bigger number repeatedly, if a < b <= 2a. This subtraction is happening because,
suppose,
a and b are such that, a < b <= 2a then on b%a we will get b-a (as b/a is 1)
which can be written as, b-a, hence,
if a < b <= 2a then b%a becomes b-a
similarly,
if 2a < b <= 3a then b%a becomes b - 2a
and it goes on ....
so, pick any two consecutive elements, as soon as you start calculating the GCD,
you are retracing your steps back towards first two components (a, b, a+b, a+2b, 2a+3b ...)
and then the whole process shrinks to calculating GCD of first two numbers.

GCD(e,f) = g;
so,
e = g * p
f = g * q

TC = log(max(a,b))

*/