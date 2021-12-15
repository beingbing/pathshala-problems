#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
    int longestConsecutiveM1(vector<int>& a) {
        unordered_map<int, int> m;
        int n = a.size(), ans = 0;
        for (auto ele : a) {
            if (m.find(ele) != m.end()) continue;
            int ls = 0, rs = 0;
            if (m.find(ele-1) != m.end()) ls = m[ele-1];
            if (m.find(ele+1) != m.end()) rs = m[ele+1];
            ans = max(ans, ls+rs+1);
            m[ele] = ls+rs+1;
            m[ele-ls] = 1+ls+rs;
            m[ele+rs] = 1+ls+rs;
        }
        return ans;
    }

    int longestConsecutiveM2(vector<int>& a) {
        int n = a.size();
        unordered_map<int, int> m, visited;
        for (int i{0}; i<n; i++) m[a[i]] = 1;
        int ans = 0;
        for (int i{0}; i<n; i++) {
            if (m.find(a[i]-1) != m.end()) continue;
            if (visited.find(a[i]) != visited.end()) continue;
            visited[a[i]] = 1;
            int len = 0;
            int x = a[i];
            while (m.find(x) != m.end()) {
                len++;
                x++;
            }
            ans = max(ans, len);
        }
        return ans;
    }

    int longestConsecutiveM3(vector<int>& a) {
        set<int> s;
        for(auto ele : a) s.insert(ele);
        if (s.size() == 1) return 1;
        int curr_run{1}, mx{0};
        for(auto sit = s.begin(); sit != s.end(); sit++) {
            auto it = next(sit, 1);
            if (it != s.end())
                if ( (*sit) + 1 == *it ) curr_run++;
                else curr_run = 1;
                mx = max(mx, curr_run);
        }
        return mx;
    }
};

int main() {
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    Solution obj;
    cout << obj.longestConsecutiveM2(nums) << endl;
    return 0;
}
