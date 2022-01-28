#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

string rearrange(string& str, int d) {
    priority_queue<pair<int, char>> pq;
    vector<int> freq(26, 0);
    for (auto &ele : str) freq[ele-'a']++;
    for (int i{0}; i<26; i++) if (freq[i]) pq.push({freq[i], i+'a'});
    string ans{""};
    while (pq.size()) {
        int cnt = 0;
        vector<pair<int, char>> tmp;
        while (cnt < d) {
            if (ans.size() == str.size()) break;
            if (pq.size() == 0) return "";
            pair<int, char> x = pq.top();
            pq.pop();
            if (x.first-1 > 0) tmp.push_back({x.first-1, x.second});
            ans += x.second;
            cnt++;
        }
        for (auto &ele : tmp) pq.push(ele);
    }
    return ans;
}

int main() {
    string str;
    int d;
    cin >> str >> d;
    string ans = rearrange(str, d);
    if (ans.size()) cout << ans << endl;
    else cout << "Cannot be rearranged" << endl;
    return 0;
}
