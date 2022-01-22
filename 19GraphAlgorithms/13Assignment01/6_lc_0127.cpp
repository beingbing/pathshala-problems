#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> words;
        for (string &ele : wordList) words.insert(ele);
        map<string, bool> visited;
        queue<pair<string, int>> q;
        visited[beginWord] = true;
        q.push({beginWord, 1});
        int ans{0};
        while (!q.empty()) {
            pair<string, int> x = q.front();
            q.pop();
            string temp = x.first;
            if (temp == endWord) {ans = x.second; break;}
            for (int i{0}; i<temp.size(); i++) {
                char ch = temp[i];
                for (int j{0}; j<26; j++) {
                    char rep = j + 'a';
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
