~~ basics of recursion ~~

Recursion: interaction between same function, calling itself again and again with different
set of arguments.

recurrence equation -
e.g. -

    !n = !(n-1) * n
=>  fact(n) = fact(n-1) * n     for all n > 0
so,
a relation which relates a larger problem with smaller problem is called a recurrence relation.

every recurrence equation have a termination condition

these 2 points hold the world of recursion.

fact(int n) {
    if (n == 0) return 1;   // termination condition
    return n * fact(n-1);   // recurrence relation
}


recurrence equation is not a universal equation, it only applicable for a certain input