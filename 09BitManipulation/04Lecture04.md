~~ count of set bits ~~

given a number n, count number of set bits.


M1 -
int countOnes(int n) {
    int cnt = 0;
    long mask = 1L << 31;
    while (mask) {
        if (mask & n) cnt++
        mast >>= 1
    }
    return cnt;
}
TC = O(32)


M2 -
int countOnes(int n) {
    int cnt = 0;
    while (n) {
        n = n & (n-1)
        cnt++
    }
    return cnt;
}
TC = O(no_of_set_bits)
