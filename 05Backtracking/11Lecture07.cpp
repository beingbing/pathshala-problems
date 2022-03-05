/*

sudoku solver -

in this we can check by putting all the values one by one, and checking it's validity.
but, it might time out.
so, we need to optimize it, this we can do by pruning some unnecessary recursions.

- we can check if a number is already present in given row, column, submatrix, in this way,
we can save some of our operations, for that,
we can maintain a rowFreq martrix where, [i][x], will be denoting frequency of x in ith row.
If this value is 0 that means, in ith row we do not have x, so, we can place it.

- similarly, for colFreq, [j][x], will have frequency of x in jth column.

- similarly, matFreq, [k][x], kth matrix will have x or not.

whenever a number is placed, all this three frequency mats need to be updated.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<char>> ans;
    bool ansFound = false;

public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rowFreq, colFreq, matFreq;
        for (int i{0}; i<9; i++) {
            vector<int> vec(9,0);
            for (int j{0}; j<9; j++) if (board[i][j] != '.') vec[board[i][j]-'1']++;
            rowFreq.push_back(vec);
        }
        for (int j{0}; j<9; j++) {
            vector<int> vec(9,0);
            for (int i{0}; i<9; i++) if (board[i][j] != '.') vec[board[i][j]-'1']++;
            colFreq.push_back(vec);
        }
        for (int i{0}; i<9; i+=3) for (int j{0}; j<9; j+=3) {
            vector<int> vec(9,0);
            for (int i1{i}; i1<i+3; i1++) for (int j1{j}; j1<j+3; j1++) if (board[i1][j1] != '.') vec[board[i1][j1]-'1']++;
            matFreq.push_back(vec);
        }
        solve(board, 0, 0, rowFreq, colFreq, matFreq);
        board = ans;
    }
    
    void solve(vector<vector<char>>& board, int i, int j, vector<vector<int>>& rowFreq, vector<vector<int>>& colFreq, vector<vector<int>>& matFreq) {
        if (ansFound) return;
        if (i == 9) {
            ansFound = true;
            ans = board;
            return;
        }
        if (board[i][j] != '.') {
            if (j < 8) solve(board, i, j+1, rowFreq, colFreq, matFreq);
            else solve(board, i+1, 0, rowFreq, colFreq, matFreq);
            return;
        }
        int m = getMatNum(i, j);
        for (char val{'1'}; val<='9'; val++) {
            if (rowFreq[i][val-'1'] == 0 && colFreq[j][val-'1'] == 0 && matFreq[m][val-'1'] == 0) {
                // do
                board[i][j] = val;
                rowFreq[i][val-'1']++;
                colFreq[j][val-'1']++;
                matFreq[m][val-'1']++;
                // recurse
                if (j < 8) solve(board, i, j+1, rowFreq, colFreq, matFreq);
                else solve(board, i+1, 0, rowFreq, colFreq, matFreq);
                // undo
                board[i][j] = '.';
                rowFreq[i][val-'1']--;
                colFreq[j][val-'1']--;
                matFreq[m][val-'1']--;
            }
        }
    }
    
    int getMatNum(int& i, int& j) {
        if (i >= 0 && i < 3) {
            if (j >= 0 && j < 3) return 0;
            else if (j >= 3 && j < 6) return 1;
            else if (j >= 6 && j < 9) return 2;
        } else if (i >= 3 && i < 6) {
            if (j >= 0 && j < 3) return 3;
            else if (j >= 3 && j < 6) return 4;
            else if (j >= 6 && j < 9) return 5;
        } else if (i >= 6 && i < 9) {
            if (j >= 0 && j < 3) return 6;
            else if (j >= 3 && j < 6) return 7;
            else if (j >= 6 && j < 9) return 8;
        }
        return -1; // not a valid number inserted
    }
};