~~ bubble sort ~~

it treats numbers as bubbles, larger the number, bigger the bubble and vice versa.

bubbling => one complete round of mutual collision of adjacent bubbles.

in one round of bubbling, all adjacent bubbles collides with each other, and get relatively sorted
with respect to their adjacent bubbles.

in 1 round of bubbling if there are n candidates then n-1 collisions will occur and after the
completion of that round, the biggest bubble will be at it's rightful place according to the
sorted order.

TC = O(n^2)

bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i{0}; i<n; i++) {
        bool done = true;
        for (int j{0}; j<n-i-1; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                done = false;
            }
        }
        if (done) break;
    }
}

can also be written as -

============================
[code is not tested yet]
============================

bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i{0}; i<n; i++) {
        bool done = false;
        while (!done) {
            done = true;
            int j = 0;
            while (j < n-i-1) {
                if (a[j] > a[j+1]) {
                    swap(a[j], a[j+1]);
                    done = true;
                }
                j++;
            }
        }
    }
}

this is a normal bubble sort implementation, now let's modify it for a new concept
if the problem stated, sort odd and even indexed elements independently then what will be my approach.

in that case, i will just consider a sub array of size 3 and instead of swap() in above code
i will do reverse,
the code will become -

troubleSort(vector<int>& a) {
    int n = a.size();
    for (int i{0}; i<n; i++) {
        bool done = false;
        while (!done) {
            done = true;
            int j = 0;
            while (j < n-i-2) {                 // a change here
                if (a[j] > a[j+2]) {            // a change here
                    reverse(a[j], a[j+2]);      // a change here
                    done = true;
                }
                j++;
            }
        }
    }
}

