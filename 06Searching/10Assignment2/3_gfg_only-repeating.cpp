#include <iostream>
#include <vector>
using namespace std;

int findRepeatingElement(vector<int>& a) {
	int low = 0, high = a.size()-1;
    while (low <= high) {
        int mid = low + (high - low)/2;
        if (a[mid] == mid) high = mid - 1;
        else {
            if (a[mid] == a[mid+1]) return mid;
            else low = mid+1;
        }
    }
    return -1;
}

int main() {
	vector<int> arr = {1, 2, 3, 3, 4, 5};
	int index = findRepeatingElement(arr);
	if (index != -1) cout << arr[index] << endl;
	return 0;
}
