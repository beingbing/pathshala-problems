~~ Activity Selection - 1 ~~

given n Activities with start time and end time. You can perform only one Activity at a time, find
max number of activities that can be performed. 

- if we pick activities in terms of their start time then it may have highest end time and can only
perform 1 activity, which is not what we want.

- if we pick activities with smallest duration then it may have smallest duration but very high start
and end time which will render us incapable of picking any other activity.

- if we pick activities in terms of their end time then it will work fine in our test cases, because
early concluding activities gives you more time to pick another activities.

when we are sorting, we are always starting with first activity, but is that necessary, can't it be
possible that our final answer doesn't have first activity ?
so, the question should be, can we get a higher number of activities completed if we do not consider
first activity ?
The answer is no, it may happen that we can get the same (equal) highest number of activities completed even
after omitting first activity but we can not get a count which is higher than the count we get considering
first activity because first activity has the smallest end-time hence it contribute to our count as well and
give us more time to consider other activities.

bool Comp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

vector<pair<int, int>> vec(n);
for (i{0}; i<n) vec[i] = {start[i], end[i]};
sort(vec.begin(), vec.end(), Comp);
int ans = 1;
int endTime = vec[0].second;
for (i{1}; i<n) {
    if (vec[i].first >= endTime) {
        ans++;
        endTime = vec[i].second;
    }
}
return ans;
TC = O(nlogn)
SC = O(n)
