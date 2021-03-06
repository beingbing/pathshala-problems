#include <vector>
using namespace std;

class Solution {

    void solve(vector<vector<char>>& board, int i, int j, bool& ansFound, vector<vector<int>>& rowFreq, vector<vector<int>>& colFreq, vector<vector<int>>& matFreq, vector<vector<char>>& ans) {
        if (ansFound) return;
        if (i == 9) {
            ansFound = true;
            ans = board;
            return;
        }
        if (board[i][j] != '.') {
            if (j < 8) solve(board, i, j+1, ansFound, rowFreq, colFreq, matFreq, ans);
            else solve(board, i+1, 0, ansFound, rowFreq, colFreq, matFreq, ans);
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
                if (j < 8) solve(board, i, j+1, ansFound, rowFreq, colFreq, matFreq, ans);
                else solve(board, i+1, 0, ansFound, rowFreq, colFreq, matFreq, ans);
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

public:
    void solveSudoku(vector<vector<char>>& board) {
        bool ansFound = false;
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
        vector<vector<char>> ans;
        solve(board, 0, 0, ansFound, rowFreq, colFreq, matFreq, ans);
        board = ans;
    }
};