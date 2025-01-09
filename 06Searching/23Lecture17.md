~~ family of (boolean) strings ~~

s[0] = 0
s[i] = s[i-1]*0*(s[i-1])'       i >= 1
given n and k. answer kth character of nth string.

we can deduce from above that -
length of s[i] will be 2^(i+1) - 1
in fast exponentiation, we learned that, we can find 2^i in logi time

after creating a binary tree, and traversing from root, we observed that -
- moving right, bit changes 1/0 -> 0/1
- moving left, bit do not change

code -

int low = 0, high = 2^(n+1) - 2 // first and last character position
bool bit = false;
while (low <= high) {
    mid = low + (high - low)/2;
    if (mid == k) return bit;
    else if (mid < k) {
        low = mid+1;
        bit = !bit
    } else {
        high = mid-1;
    }
}

TC = O(n)
