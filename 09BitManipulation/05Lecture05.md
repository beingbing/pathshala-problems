~~ cumulative bitwise AND ~~

given 2 non negative integers, left and right, where left <= right
find bitwise AND of all the numbers from left till right

int rangeAND(int m, int n) {
    long mask = 1L << 31, ans = 0
    while (mask) {
        if ((mask & m) == (mask & n)) {
            if (mask & m) ans += mask
            mask >> 1
        } else {
            break;
        }
    }
    return ans;
}
