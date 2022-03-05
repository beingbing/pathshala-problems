#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool ans = false;

    bool isSafe(vector<vector<char>> &grid, int i, int j) {
        if (i >= grid.size()) return false;
        if (j >= grid[0].size()) return false;
        return true;
    }

    void findWord(vector<vector<char>> &board, string &word, vector<vector<bool>> &isVisited, int i, int j, int k) {
        if (board[i][j] == word[k] && k == word.size() - 1) {
            ans = true;
            return;
        }
        isVisited[i][j] = true;
        if (isSafe(board, i, j + 1) and !isVisited[i][j + 1] && board[i][j] == word[k])
            findWord(board, word, isVisited, i, j + 1, k + 1);
        if (isSafe(board, i, j - 1) and !isVisited[i][j - 1] && board[i][j] == word[k])
            findWord(board, word, isVisited, i, j - 1, k + 1);
        if (isSafe(board, i + 1, j) and !isVisited[i + 1][j] && board[i][j] == word[k])
            findWord(board, word, isVisited, i + 1, j, k + 1);
        if (isSafe(board, i - 1, j) and !isVisited[i - 1][j] && board[i][j] == word[k])
            findWord(board, word, isVisited, i - 1, j, k + 1);
        isVisited[i][j] = false;
    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        if (word.size() == 0) return false;
        int rows = board.size();
        if (rows == 0) return false;
        int cols = board[0].size();
        vector<vector<bool>> isVisited(rows, vector<bool>(cols, false));
        for (int i{0}; i < rows; i++)
            for (int j{0}; j < cols; j++)
                if (board[i][j] == word[0]) {
                    findWord(board, word, isVisited, i, j, 0);
                    if (ans) return ans;
                }
        return false;
    }
};

int main() {
    Solution *obj = new Solution();
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    cout << obj->exist(board, "SEE") << endl;
    return 0;
}