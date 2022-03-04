#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int row, col, wasteCells, queries;
    cin >> row >> col >> wasteCells >> queries;
    set<int> wasteLands;
    int x, y;
    while (wasteCells--) {
        cin >> x >> y;
        wasteLands.insert(((x-1)*col)+y);
    }
    while (queries--) {
        cin >> x >> y;
        int val = ((x-1)*col)+y;
        if (wasteLands.find(val) != wasteLands.end()) cout << "Waste" << endl;
        else {
            for (auto ele = wasteLands.begin(); ele != wasteLands.end(); ele++)
                if ((*ele/col+1) < x || ((*ele/col+1) == x && (*ele%col) < y)) val--;
                else if (*ele > (x-1)*col+y) break;
            if (val%3 == 1) cout << "Carrots" << endl;
            else if (val%3 == 2) cout << "Kiwis" << endl;
            else cout << "Grapes" << endl;
        }
    }
    return 0;
}
