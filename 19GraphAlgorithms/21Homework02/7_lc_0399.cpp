#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {

    double dfs(const string &strt, const string &nd, unordered_map<string, unordered_map<string, double>> &graph, unordered_set<string> &visited) {
        if (graph.find(strt) == graph.end()) return -1;
        if (graph[strt].find(nd) != graph[strt].end()) return graph[strt][nd];
        for (const auto& ele : graph[strt]){
            if (visited.count(ele.first)) continue;
            visited.insert(ele.first);
            double res = dfs(ele.first, nd, graph, visited);
            if (res != -1) return graph[strt][nd] = graph[strt][ele.first] * res;
        }
        return -1;
    }

    unordered_map<string, unordered_map<string, double>> buildGraph(vector<vector<string>> &equations, vector<double> &values) {
        const int n = equations.size();
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i{0}; i < n; i++) {
            const vector<string> &equation = equations[i];
            const string &num = equation[0], &den = equation[1];
            const double &value = values[i];
            graph[num][num] = 1.0;
            graph[den][den] = 1.0;
            graph[num][den] = value;
            graph[den][num] = 1.0 / value;
        }

        return graph;
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        unordered_map<string, unordered_map<string, double>> graph = buildGraph(equations, values);
        vector<double> ans;
        unordered_set<string> visited;
        for (const vector<string> &query : queries) {
            const string &num = query[0], &den = query[1];
            visited = {num};
            ans.push_back(dfs(num, den, graph, visited));
        }
        return ans;
    }
};
