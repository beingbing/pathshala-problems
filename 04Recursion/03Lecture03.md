~~ recursion tree diagram ~~

recrusion with 2 branches

void func(int n) {
    print x;
    if (x >= 3) return;
    func(x+1);
    func(x+2);
}

main() {
    func(0);
}

                                main
                                |
                                func(0)
        |                         |                               |
    print(0)                    func(1)                       func(2)
                           |     |      |                     |          |           |
                    print(1)   func(2)  func(3)              print(2)    func(3)     func(4)


the above is called recursion tree diagram

output: 0 1 2 3 4 3 2 3 4

every sub tree represents the output if the call been made with that value
