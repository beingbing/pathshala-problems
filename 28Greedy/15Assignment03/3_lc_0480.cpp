#include <set>
#include <vector>
using namespace std;

class MedianFinder {
    multiset<long long> ms;
    long double curMedian;
    long long sz;

public:
    MedianFinder(long long k): sz{k}, curMedian{0.0} {}
    
    void addNum(long long num) {
        ms.insert(num);
    }
    
    double findMedian() {
        auto iter = ms.cbegin();
        advance(iter, sz / 2);
        if (sz % 2 == 0) {
            const auto iter2 = iter--;
            curMedian = double(*iter + *iter2) / 2;
        } else curMedian = *iter;
        return curMedian;
    }

    void delNum(long long num) {
        auto it = ms.find(num);
        ms.erase(it);
    }
};


class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        long long n = nums.size();
        MedianFinder *obj = new MedianFinder((long long)k);
        for (long long i{0}; i<k; i++) obj->addNum(nums[i]);
        ans.push_back(obj->findMedian());
        for (long long i{k}; i<n; i++) {
            obj->addNum(nums[i]);
            obj->delNum(nums[i-k]);
            ans.push_back(obj->findMedian());
        }
        return ans;
    }
};
