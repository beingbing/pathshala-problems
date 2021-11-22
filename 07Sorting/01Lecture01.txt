~~ comparators and stability ~~

There are two domains of algortithms guiding every development in that field, these are -
- searching algortithms
- sorting algortithms

sorting depends on comparison logic, it may be -
- ascending order of value
- descending order of value
- ascending order of magnitude
etc.

stability is associated with relative order of repeating elements
- if order changes while sorting, then it is said to be unstable sorting
- otherwise, its a stable sort.
problems sometimes gives you parameter on which you can ensure stability

--------

in build sort functions
sort(data, comparison-logic)

comparison-logic -> comparator function cmpr

// return true when you want to place x before y
// so if we want to sort in ascending order then
bool cmpr(int x, int y) {
    return x < y;
}

// if we want to sort in descending order then
bool cmpr(int x, int y) {
    return x > y;
}

never ever assume that x would be present before y in array, no, it may also happen that
x is last element and y is first element.

so, to maintain stability, create a new vector<pair<int, int>> which will contain value as first element and
index as second element of pair.

so, our ascending order logic for stable sorting will be -
bool cmpr(int x, int y) {
    if (x.first == y.first) return x.second < y.second;
    else x.first < y.first;
}
