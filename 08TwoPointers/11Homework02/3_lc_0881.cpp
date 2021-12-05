#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int ans = 0;
        while (i <= j) {
            ans++;
            if (people[i] + people[j] <= limit) i++;
            j--;
        }
        return ans;
    }
};

int main() {
    vector<int> people = {3,2,2,1};
    int limit = 3;
    Solution obj;
    cout << obj.numRescueBoats(people, limit) << endl;
    return 0;
}
