~~ single branch recursion ~~

fact(int n) {
    if (n == 0) return 1;
    return n * fact(n-1);
}


main {
    y = fact(5);    // initialization
}

three pillars of recursion -
1. initialization
2. recurrence relation
3. termination condition


    main
     |          ^   1 * 1 * 2 * 3 * 4 * 5
    fact(5)
      |         ^   1 * 1 * 2 * 3 * 4
    fact(4)
      |         ^   1 * 1 * 2 * 3
    fact(3)
      |         ^   1 * 1 * 2
    fact(2)
      |         ^   1 * 1
    fact(1)
      |         ^   1
    fact(0)


here, the control flow has happened from top-to-bottom (going into depth), so this can be called as
depth-first traversal.

returning happens in bottom-to-top fashion. Last to invoke gets returned first. So, it fills the 
call stack. Last-in-first-out principle in work.

so, recrusion is internally works on stack.

TC = O(n)      {recurrence equation: F(n) = F(n-1) + c}
SC = O(n)   as call stack is created