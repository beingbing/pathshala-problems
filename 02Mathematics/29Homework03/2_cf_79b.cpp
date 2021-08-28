// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int row, col, wasteCells, queries;
//     cin >> row >> col >> wasteCells >> queries;
//     vector<vector<int>> field(row+1, vector<int>(col+1, 1));
//     int x, y;
//     while (wasteCells--) {
//         cin >> x >> y;
//         field[x][y] = 0;
//     }
//     int cnt{0};
//     for (int i{1}; i<=row; i++)
//         for (int j{1}; j<=col; j++)
//             if (field[i][j] != 0) field[i][j] = ++cnt;
//             else field[i][j] = -1;
//     while (queries--) {
//         cin >> x >> y;
//         int val = field[x][y]%3;
//         if (field[x][y] == -1) cout << "Waste" << endl;
//         else if (val == 1) cout << "Carrots" << endl;
//         else if (val == 2) cout << "Kiwis" << endl;
//         else cout << "Grapes" << endl;
//     }
//     return 0;
// }

// memory limit exceeded

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