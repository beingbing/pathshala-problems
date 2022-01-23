#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> words;
        for (string &ele : bank) words.insert(ele);
        map<string, bool> visited;
        queue<pair<string, int>> q;
        visited[startGene] = true;
        q.push({startGene, 0});
        int ans{-1};
        vector<int> genes = {0, 2, 6, 19};
        while (!q.empty()) {
            pair<string, int> x = q.front();
            q.pop();
            string temp = x.first;
            if (temp == endGene) {ans = x.second; break;}
            for (int i{0}; i<temp.size(); i++) {
                char ch = temp[i];
                for (int j{0}; j<4; j++) {
                    char rep = genes[j] + 'A';
                    temp[i] = rep;
                    if (words.count(temp) > 0 && !visited[temp]) {
                        visited[temp] = true;
                        q.push({temp, x.second+1});
                    }
                }
                temp[i] = ch;
            }
        }
        return ans;
    }
};
