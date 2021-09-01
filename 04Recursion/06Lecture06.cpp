// ~~ print from 1 to n ~~
// print number from 1 to n recursively

/*
while writing recursive code, we will be needing a separate recursion function
so, 1. think of function definition
- name of function
- arguments of function (global variables)
- return type

then, think of, 2. what must be your termination condition
then, think of, 3. recurrence relation
then, think of, 4. first call (Initializtion)


after you are through with all the above, think of expected output and map it to
function body, to decide on how will the control of recursive function flow

to decide on what part of action will a function should execute and what remaining
part should it delegate to the child functions


*/

#include <iostream>
using namespace std;

void printTill(int n) {
    if (n < 1) return;
    printTill(n-1);
    cout << n << endl;
}

void printTill2(int x, int n) {
    if (x > n) return;
    cout << x << endl;
    printTill2(x+1, n);
}

void printReverse(int n) {
    if (n < 1) return;
    cout << n << endl;
    printReverse(n-1);
}

int main() {
    int n;
    cin>>n;
    printReverse(n);
    return 0;
}