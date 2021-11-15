#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    vector<vector<int>> ans;

    bool isSafe(vector<vector<int>>& grid, int i, int j) {
        if (i >= grid.size()) return false;
        if (j >= grid[0].size()) return false;
        if (grid[i][j] == 0) return false;
        return true;
    }
	
	void findPath(vector<vector<int>>& mat, vector<vector<int>>& isVisited, int i, int j) {
	    if (mat[i][j] == 0) return;
	    if (i == j && j == mat.size()-1) {
	        isVisited[i][j] = 1;
            if (ans.size() == 0) ans = isVisited;
	        isVisited[i][j] = 0;
	        return;
	    }
	    isVisited[i][j] = 1;
        for (int l{1}; l<=mat[i][j]; l++) {
            if (isSafe(mat, i, j+l) && !isVisited[i][j+l]) findPath(mat, isVisited, i, j+l);
            if (isSafe(mat, i+l, j) && !isVisited[i+l][j]) findPath(mat, isVisited, i+l, j);
        }
	    isVisited[i][j] = 0;
	}
    
public:
	vector<vector<int>> ShortestDistance(vector<vector<int>>&mat){
	   int n = mat.size();
	   vector<vector<int>> isVisited(n, vector<int>(n, 0));
       mat[n-1][n-1] = 1;
	   findPath(mat, isVisited, 0, 0);
	   if (ans.size() > 0) return ans;
       return {{-1}};
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends