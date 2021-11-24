~~ dealing with absolute values ~~

1. given an int arr of size n, 
- find min value of mod(a[i]-a[j])
- find max value of mod(a[i]-a[j])
such that i != j

let's take the second point first, let's find the max possible mod(a[i]-a[j])
max => difference between maximum and minimum value - O(n)

mod() of two numbers is nothing but there distance from each other on number line.
so, two elements picked from array such that distance between them is largest possible
then it will be our answer.
and, the ideal candidates for this will be the two corner elements among all available options.
so, we just need to find the min and max elements from array and take difference of them.
so, TC = O(n)

min => only adjacent elements can be candidates for getting this answer
so, 
- sort the array
- then find the minimum (gap) difference between any two elements
TC = O(nlogn)

2. manhattan distance
distance between two points if i am only allowed horizontal and vertical movements (no diagonal movements allowed)
so, it becomes d = |x2 - x1| + |y2 - y1|

given two arrays of x coordinates and y coordinates, find sum of manhattan distances between all pair of points.


M1 -
int sum = 0
for (int i{0}; i<n; i++) {
    for (int j{i+1}; j<n; j++) {
        sum += abs(x[i]-x[j])+abs(y[i]-y[j])
    }
}


M2 -
- sorting x coordinates in ascending order
- ans += sufArr[i+1] - (n-i-1)*x[i]
or 
- ans += (totalSum-x[i]) - (n-i-1)*x[i]


code -

int distancesum(vector<int>& a, int& n) {
	sort(a.begin(), a.end());
	int ans = 0, sufSum = 0;
	for (int i = 0; i < n; i++) {
        sufSum -= x[i];
        ans += sufSum - (n-i-1)*x[i]; // suffix sum from i+1 till n-1
	}
	return ans;
}

int totaldistancesum(vector<int>& x, vector<int>& y, int n) {
	return distancesum(x, n) + distancesum(y, n);
}

int main() {
	vector<int> x = { -1, 1, 3, 2 };
	vector<int> y = { 5, 6, 5, 3 };
	cout << totaldistancesum(x, y, 4) << endl;
	return 0;
}
