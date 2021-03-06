// C++ program to find the sum of all
// possible submatrices of a given Matrix

#include <iostream>
#define n 3
using namespace std;

// Function to find the sum of all
// possible submatrices of a given Matrix
int matrixSum(int arr[][n]) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			// Number of ways to choose
			// from top-left elements
			// top-left is starting point for a sub-matrix
			int top_left = (i + 1) * (j + 1);
			// Number of ways to choose
			// from bottom-right elements
			// it is ending point for a sub-matrix
			int bottom_right = (n - i) * (n - j);
			sum += (top_left * bottom_right * arr[i][j]);
		}
	return sum;
}

// Driver Code
int main() {
	int arr[][n] = { { 1, 1, 1 },
					{ 1, 1, 1 },
					{ 1, 1, 1 } };
	cout << matrixSum(arr);
	return 0;
}