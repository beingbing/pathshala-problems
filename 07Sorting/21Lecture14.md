~~ applications of merge process ~~

1. given sorted arr, sort the squares of elements of given array

[-4, -2, -1, 0, 1, 3, 7]
[0, 1, 1, 4, 9, 16, 49]

vector<int> ans;
int i = 0;
for (; i<n; i++) {
    if (nums[i] >= 0) break;
}
int j = i-1
while (j >= 0 and i < n) {
    if (nums[i]*nums[i] <= nums[j]*nums[j]) {
        ans.push_back(nums[i]*nums[i])
        i++
    } else {
        ans.push_back(nums[j]*nums[j])
        j--
    }
}
while (j >= 0) {
    ans.push_back(nums[j]*nums[j])
    j--
}
while (i < n) {
    ans.push_back(nums[i]*nums[i])
    i++
}
return ans
TC = O(n)




2. given sorted arr and A, B and C, sort the transformed elements of given array
transformation => ele = A*a[i]^2 + B*a[i] + C

in last question our slope was 0 at x = 0, so before that everything was in decreasing
order and after that everything was in increasing order, hence we can do the same in this
problem also, we just need to know the point where slope changes.

we can do that by calculating the gradient of the current equation and equating it with 0
so, we get, 2Ax + B = 0 => x = -B/2A

so, we just need to find the element which is >= -B/2A, before that element if we
find the f(x) of any element then the resultant values are in decreasing order and after
that element resultant elements are in increasing order.

if A > 0 then it's an upward parabola
if A < 0 then it's an downward parabola

