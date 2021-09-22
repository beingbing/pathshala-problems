~~ insertion sort ~~

sorting algorithms are of two type -
- comparison based
- non comparison based

TC = O(n^2)

insertion -> inserting a new element at its deserving position in a sorted array.

for (int j{2}; j<a.size(); j++) {
    int key = a[j];
    int i = j-1;
    while (i > 0 && a[i] > key) {
        a[i+1] = a[i];
        i = i-1;
    }
    a[i+1] = key;
}

It is a comparison based, inplace sorting algorithms.

stability => depends on how i implement insertion sort, if on #14 i do a[i] >= key instead
then it will become unstable, otherwise in current scenario it is stable.
