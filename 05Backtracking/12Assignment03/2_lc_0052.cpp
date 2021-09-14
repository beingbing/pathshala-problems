#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<string>> ans;
    
    bool isSafe(vector<string>& board, int r, int c) {
        for (int i{r-1}; i>=0; i--)
            if (board[i][c] == 'Q') return false;
        for (int i{r-1}, j{c-1}; i>=0 and j>=0; i--, j--)
            if (board[i][j] == 'Q') return false;
        for (int i{r-1}, j{c+1}; i>=0 and j<board.size(); i--, j++)
            if (board[i][j] == 'Q') return false;
        return true;
    }
    
    void findSolution(vector<string>& board, int r) {
        if (r == board.size()) {ans.push_back(board); return;}
        for (auto c{0}; c<board.size(); c++) 
            if (isSafe(board, r, c)) {
                board[r][c] = 'Q';
                findSolution(board, r+1);
                board[r][c] = '.';
            }
    }
    
public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        findSolution(board, 0);
        return ans.size();
    }
};