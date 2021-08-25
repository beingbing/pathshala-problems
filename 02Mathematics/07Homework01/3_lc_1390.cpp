#include <iostream>
#include <vector>
using namespace std;

class Solution {
    
    int sumDivisorsFour(int n) {
        vector<int> vec(1,1);
        int lim = sqrt(n);
        for (int i{2}; i<=lim; i++)
            if (n%i == 0)
                if (i*i == n) vec.push_back(i);
                else vec.push_back(i), vec.push_back(n/i);
        vec.push_back(n);
        int sum{0};
        if (vec.size() == 4) for (auto ele : vec) sum += ele;
        return sum;
    }
    
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans{0};
        for (auto ele : nums) ans += sumDivisorsFour(ele);
        return ans;
    }
};