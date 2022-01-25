#include <vector>
using namespace std;

class Solution {

    void dfs(int i, int j, int& row, int& col, vector<vector<char>> &board) {
        if (i < 0 || i >= row || j < 0 || j >= col) return;
        if (board[i][j] == 'X' || board[i][j] == 'A') return;
        board[i][j] = 'A';
        dfs(i+1, j, row, col, board);
        dfs(i-1, j, row, col, board);
        dfs(i, j+1, row, col, board);
        dfs(i, j-1, row, col, board);
    }

public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if (!row) return;
        int col = board[0].size();
        for (int i{0}; i<row; i++) {
            dfs(i, 0, row, col, board);
            dfs(i, col-1, row, col, board);
        }
        for (int j{1}; j<col-1; j++) {
            dfs(0, j, row, col, board);
            dfs(row-1, j, row, col, board);
        }
        for (int i{0}; i<row; i++)
            for (int j{0}; j<col; j++)
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'A') board[i][j] = 'O';
    }
};
