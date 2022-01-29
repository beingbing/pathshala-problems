~~ Activity Selection - 2 ~~

given n Activities with start time and end time. You can perform two Activity at a time, find
max number of activities that can be performed.

our logic of previous lecture -
if an activity can be performed (endTime(cur) <= startTime(next)) then perform it.

will not work in this problem, because we need to distribute every next upcoming activity such that
both persons could complete max number of activities. so, even if the next activity can be performed
by first person but before assigning that we need to keep in account as whether second person can also do
that activity or not, and if yes, then do we get more number of activities completed that way.

because if situation arises that an upcoming activity can be assigned to both persons then we need to check
whether next activity after that can also be assigned to both or not.

in simple terms, we need to check that, if an activity can be assigned to second person can also be assigned
to first person but can an activity that can be assigned to first person, can it be assigned to second person
too or not.

so, if an activity can be assigned to both then assign it to the person which has higher endTime activity
at hand that way we have option that if an activity comes next which had startTime between endTime of first
and second person, then it can go to first person, that way more activities can be completed.

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

TC = O(nlogn)
SC = O(n)
