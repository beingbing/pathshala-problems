// #include <iostream>
// #include <iomanip>
// #include <algorithm>
// #include <vector>
// using namespace std;

// inline bool NotAttacking(vector<int>& rowVals) {
//     for (int i = 0; i < 8; ++i)
//         for (int j = 0; j < i; ++j)
//             if (i + rowVals[i] == j + rowVals[j] || i - rowVals[i] == j - rowVals[j]) return false;
//     return true;
// }

// int main() {
//     int testCases;
//     cin >> testCases;
//     string separate = "";
//     while (testCases--) {
//         cout << separate;
//         separate = "\n";
//         int givenRow, givenCol;
//         cin >> givenRow >> givenCol;
//         --givenCol; // Easier to have it be 0 indexed
//         int solutionsCnt = 0;
//         vector<int> rowVals = {1, 2, 3, 4, 5, 6, 7, 8};
//         cout << "SOLN       COLUMN\n";
//         cout << " #      1 2 3 4 5 6 7 8\n\n";
//         do {
//             if (rowVals[givenCol] == givenRow && NotAttacking(rowVals)) {
//                 cout << setw(2) << ++solutionsCnt << "     ";
//                 for (int i = 0; i < 8; ++i) cout << ' ' << rowVals[i];
//                 cout << '\n';
//             }
//         } while (next_permutation(rowVals.begin(), rowVals.end()));
//     }
//     return 0;
// }
