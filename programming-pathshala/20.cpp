// print all the valid paths that a rat can take in a maze to 
// reach it's destination.
#include <iostream>
#include <vector>
using namespace std;
    vector<vector<pair<int, int>>> ans;

    void findPaths(vector<vector<int>>& maze, vector<pair<int, int>>& route, int i, int j) {
        if (maze[i][j] == 1) return;
        if (i == j and j == maze.size()-1) {
            route.push_back({i,j});
            ans.push_back(route);
            route.pop_back();
            return;
        }
        route.push_back({i,j});
        if (i == maze.size()-1) findPaths(maze, route, i, j+1);
        else if (j == maze[0].size()-1) findPaths(maze, route, i+1, j);
        else {
            findPaths(maze, route, i, j+1);
            findPaths(maze, route, i+1, j);
        }
        route.pop_back();
    }

int main() {
    vector<vector<int>> maze = {{0,0,1,1},{0,0,1,1},{1,0,1,0},{0,0,0,0}};
    vector<pair<int, int>> route;
    findPaths(maze, route, 0, 0);
    for (auto path : ans) {
        for (auto cell : path) cout << "(" << cell.first << ", " << cell.second << ")\t";
        cout << endl;
    }
    return 0;
}