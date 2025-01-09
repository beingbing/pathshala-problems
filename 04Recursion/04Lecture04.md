~~ recursion stack diagram ~~

void func(int n) {
1   print x;
2   if (x >= 3) return;
3   func(x+1);
4   func(x+2);
}

main() {
    func(0);
}



        0               1
0 f(0)    =>  3 f(0)    =>  3 f(0)
              0 f(1)        3 f(1)
                            0 f(2)




output: 0 1 2 3 4 3 2 3 4