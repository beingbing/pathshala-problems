#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
 
	static bool Comp(pair<int, int>& a, pair<int, int>& b) {
	    if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
	}
 
	public:
	int maxActivitiesBy2Persons(vector<int>& strts, vector<int>& ends, int& n) {
		vector<pair<int, int>> vec;
		for (int i{0}; i<n; i++) vec.push_back({strts[i], ends[i]});
		sort(vec.begin(), vec.end(), Comp);
		int ans = 0;
		int endTime1 = 0, endTime2 = 0;
		for (auto &ele : vec) {
			if (ele.first >= endTime1 || ele.first >= endTime2) {
				ans++;
				if (ele.second > endTime2) endTime2 = ele.second;
				else endTime1 = ele.second;
			}
		}
		return ans;
	}
};
 
int main() {
	int activityCnt;
	cin >> activityCnt;
	vector<int> strtTimes(activityCnt), endTimes(activityCnt);
	for (int i{0}; i < activityCnt; i++) cin >> strtTimes[i];
    for (int i{0}; i < activityCnt; i++) cin >> endTimes[i];
	Solution obj;
	int ans = obj.maxActivitiesBy2Persons(strtTimes, endTimes, activityCnt);
	cout << ans << endl;
	return 0;
}
