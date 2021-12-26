#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<string> generate(int n) {
    queue<string> q;
    vector<string> ans;
    q.push("1");
    int c = 0;
    while (c < n) {
        string x = q.front();
        q.pop();
        ans.push_back(x);
        q.push(x + '0');
        q.push(x + '1');
        c++;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> ans = generate(n);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
