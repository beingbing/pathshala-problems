#include <iostream>
using namespace std;

int main() {
    int t{0};
    cin >> t;
    while (t--) {
        long long int n{0};
        cin >> n;
        long long int cumm_time[n], real_time[n], stu[n];
        long long int count{0};
        for (long long int i{0}; i < n; i++) {
            if (i == 0) {
                cin >> cumm_time[i];
                real_time[i] = cumm_time[i];
            } else {
                cin >> cumm_time[i];
                real_time[i] = cumm_time[i] - cumm_time[i - 1];
            }
        }
        for (long long int i{0}; i < n; i++) {
            cin >> stu[i];
            if (stu[i] <= real_time[i]) count++;
        }
        cout << count << endl;
    }
    return 0;
}
