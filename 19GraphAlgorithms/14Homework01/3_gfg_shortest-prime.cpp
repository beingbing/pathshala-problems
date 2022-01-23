#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

    vector<int> sieve(int strt, int end) {
        vector<int> ans;
        vector<int> primes(end + 1, 1);
        primes[0] = 0;
        primes[1] = 0;
        int val = sqrt(end+1);
        for (int i = 2; i <= val; i++) if (primes[i]) for (int j = i; j * i <= end; j++) primes[i * j] = 0;
        for (int i = 1000; i < primes.size(); i++) if (primes[i]) ans.push_back(i);
        return ans;
    }

public:
    int solve(int beginNum, int endNum) {
        vector<int> primes = sieve(1000, 9999);
        unordered_map<int, bool> visited, primesMp;
        for(auto &ele : primes) primesMp[ele] = true;
        queue<pair<int, int>> q;
        visited[beginNum] = true;
        q.push({beginNum, 0});
        int ans{0};
        while (!q.empty()) {
            pair<int, int> x = q.front();
            q.pop();
            int num = x.first;
            
            if (num == endNum) return x.second;
            string tmp = to_string(num);
            for (int i{0}; i<tmp.size(); i++) {
                char ch = tmp[i];
                for (int j{0}; j<10; j++) {
                    if (!i && !j) continue;
                    char rep = j + '0';
                    tmp[i] = rep;
                    int val = stoi(tmp);
                    if (primesMp.count(val) > 0 && !visited[val]) {
                        visited[val] = true;
                        q.push({val, x.second+1});
                    }
                }
                tmp[i] = ch;
            }
        }
        return -1;
    }
};

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int Num1, Num2;
        cin >> Num1 >> Num2;
        Solution obj;
        int answer = obj.solve(Num1, Num2);
        cout << answer << endl;
    }
}
