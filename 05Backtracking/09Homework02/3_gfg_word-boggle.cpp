#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<string> ans;

    bool isSafe(vector<vector<char>>& grid, int i, int j) {
        if (i >= grid.size()) return false;
        if (j >= grid[0].size()) return false;
        return true;
    }

    void findWord(vector<vector<char>>& board, string& word, vector<vector<bool>>& isVisited, int i, int j, int k) {
        if (board[i][j] == word[k] && k == word.size()-1) {
            if (find(ans.begin(), ans.end(), word) == ans.end()) ans.push_back(word);
            return;
        }
        isVisited[i][j] = true;
        if (isSafe(board, i-1, j) and !isVisited[i-1][j] && board[i][j] == word[k]) findWord(board, word, isVisited, i-1, j, k+1);
        if (isSafe(board, i-1, j+1) and !isVisited[i-1][j+1] && board[i][j] == word[k]) findWord(board, word, isVisited, i-1, j+1, k+1);
        if (isSafe(board, i, j+1) and !isVisited[i][j+1] && board[i][j] == word[k]) findWord(board, word, isVisited, i, j+1, k+1);
        if (isSafe(board, i+1, j+1) and !isVisited[i+1][j+1] && board[i][j] == word[k]) findWord(board, word, isVisited, i+1, j+1, k+1);
        if (isSafe(board, i+1, j) and !isVisited[i+1][j] && board[i][j] == word[k]) findWord(board, word, isVisited, i+1, j, k+1);
        if (isSafe(board, i+1, j-1) and !isVisited[i+1][j-1] && board[i][j] == word[k]) findWord(board, word, isVisited, i+1, j-1, k+1);
        if (isSafe(board, i, j-1) and !isVisited[i][j-1] && board[i][j] == word[k]) findWord(board, word, isVisited, i, j-1, k+1);
        if (isSafe(board, i-1, j-1) and !isVisited[i-1][j-1] && board[i][j] == word[k]) findWord(board, word, isVisited, i-1, j-1, k+1);
        isVisited[i][j] = false;
    }

public:
	vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
        if (dictionary.size() == 0) return ans;
        int rows = board.size();
        if (rows == 0) return ans;
        int cols = board[0].size();
        vector<vector<bool>> isVisited(rows, vector<bool>(cols, false));
        for (auto word : dictionary)
            for (int i{0}; i<rows; i++) for (int j{0}; j<cols; j++) if (board[i][j] == word[0])
                findWord(board, word, isVisited, i, j, 0);
	    return ans;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends