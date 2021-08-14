class Solution {
public:
    int arrayNesting(vector<int>& a) {
        int n = a.size();
        int mx{0}, cnt{0};
        for (int i{0}; i<n; i++) {
            cnt = 0;
            if (a[i] >= 0 ) {
                int idx = a[i], val = i;
                while (idx != i) {
                    int temp = a[idx];
                    a[idx] = -1*(val+1);
                    val = idx;
                    idx = temp;
                    cnt++;
                }
                a[i] = -1*(val+1);
                cnt++;
                if (mx < cnt) mx = cnt;
            }
        }
        return mx;
    }
};