~~ smallest good base ~~

a base is defined as a good base iff all the digit representation in that base is 1.
a base k is considered good if k >= 2.
find smallest good base of a number n. n belongs to [3, 10^18]

domain of smallest good base will be [2, n-1]
so, we can BS on this domain and look for our answer

but as our n can go till 10^18 hence for big number this domain will surely timeout.

but there is one another way, suppose a number n has three good bases k1, k2 and k3 such that -
n = 1*k1^0 + 1*k1^1 + 1*k1^2 
n = 1*k2^0 + 1*k2^1 + 1*k2^2 + 1*k2^3
n = 1*k3^0 + 1*k3^1 + 1*k3^2 + 1*k3^3 + 1*k3^4 + 1*k3^5

so, here we can conclude that, k1 > k2 > k3

so we have another domain available here, if, 2 is a good base and it's power is i and n-1 is a good base
with power j, then on the basis of power we have domain [i, j]

so, here we need to fix one of these domain -
1. base
2. (number of terms / number of power)
and do BS in another to get the answer.

here we modify our no. of powers domain by considering 2 as the smallest possible valid good base and
take 10^18 (the largest valid number) and find it's value, you will find that 10^18 will be around 2^63
so,
we can conclude that the power in any circumstances will not go above 63, so, we fixed our number of powers
domain between [1,63]

for (int i{63}; i<1; i--) {
    l = 2, h = n-1;
    while (l <= h) {
        m = (l+h)/2
        if (1+m^2+m^3+m^4+....+m^(i-1) == n) return m;
        else if (1+m^2+m^3+m^4+....+m^(i-1) < n) l = m+1;
        else h = m-1;
    }
}

TC = O(63*63*logn)

to stop from overflow condition instead of having
sum += x
x = x*m // point of overflow, so before performing this step, ensure that you have this check
(n - sum) / m = x
in place

for (int i{63}; i<1; i--) {
    l = 2, h = n-1;
    while (l <= h) {
        m = (l+h)/2
        sum = 0, x = 1, flag = false
        for (j{0}; j<i) {
            sum += x
            if (sum >= n) break;
            if (j < i && (n-sum)/x < m) {
                flag = true
                break
            }
            if (j < i) x *= m;
        }
        if (sum > n || flag) h = m-1;
        else if (sum < n) l = m+1;
        else return m;
    }
}