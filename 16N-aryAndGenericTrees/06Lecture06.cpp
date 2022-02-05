// ~~ cats in park ~~

// cf 580-c

// nodes with cats should not be consecutive. 

#include <vector>
using namespace std;

void validPath(int &cnt, int cur, int ans, vector<vector<int>> &adjList, Node* rut, Node* par, int &m, vector<int> ar) {
    if (adjList[i].size() == 1) {
        if (ar[i] == 1) cur++;
        ans = max(ans, cur);
        if (ans <= m) cnt++;
        return;
    }
    for (int j{0}; j < adjList[rut].size(); j++) {
        if (adjList[rut][j] != par) {
            if (ar[rut] == 1) validPath(cnt, cur+1, max(ans, cur+1), adjList, adjList[rut][j], rut, m, ar);
            else validPath(cnt, 0, ans, adjList, adjList[rut][j], rut, m, ar);
        }
    }
}
