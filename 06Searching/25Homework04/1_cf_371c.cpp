#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {

    bool isPossible(long long int r, int& qb, int& qs, int& qc, long long int k, int& nb, int& ns, int& nc, int& pb, int& ps, int& pc) {
        long long int reqB = (qb*k - nb);
        long long int reqS = (qs*k - ns);
        long long int reqC = (qc*k - nc);
        if (reqB > 0) r -= reqB*pb;
        if (reqS > 0) r -= reqS*ps;
        if (reqC > 0) r -= reqC*pc;
        return r >= 0;
    }

public:
    long long int maxHamburgers(unordered_map<char, int>& charsCnt, int& nb, int& ns, int& nc, int& pb, int& ps, int& pc, long long int& r) {
        long long int low = 0;
        long long int high = r + nb*pb + ns*ps + nc*pc;
        long long int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (!isPossible(r, charsCnt['B'], charsCnt['S'], charsCnt['C'], mid, nb, ns, nc, pb, ps, pc)) high = mid - 1;
            else {
                if (!isPossible(r, charsCnt['B'], charsCnt['S'], charsCnt['C'], mid+1, nb, ns, nc, pb, ps, pc)) break;
                else low = mid + 1;
            }
        }
        return mid;
    }
};

int main() {
    string recipe;
    cin >> recipe;
    unordered_map<char, int> charsCnt;
    for (auto ele : recipe) charsCnt[ele]++;
    int nb, ns, nc;
    cin >> nb >> ns >> nc;
    int pb, ps, pc;
    cin >> pb >> ps >> pc;
    long long int r;
    cin >> r;
    Solution obj;
    cout << obj.maxHamburgers(charsCnt, nb, ns, nc, pb, ps, pc, r) << endl;
    return 0;
}
