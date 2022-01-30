#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//          {index, {loss, deadline}}
typedef pair<int, pair<int, int>> job;

bool comp(job a, job b) {
    int aLoss, aDeadline, bLoss, bDeadline;
    aLoss = a.second.first;
    aDeadline = a.second.second;
    bLoss = b.second.first;
    bDeadline = b.second.second;
    return (aLoss * bDeadline) > (bLoss * aDeadline);
}

void printOptimal(vector<int>& loss, vector<int>& deadline, int& N) {
    vector<job> list;
    for (int i = 0; i < N; i++) list.push_back({i + 1, {loss[i], deadline[i]}});
    sort(list.begin(), list.end(), comp); // sort in desc order of loss/deadline
    for (int i = 0; i < N; i++) cout << list[i].first << " ";
    cout << endl;
}

int main() {
    vector<int> L = {1, 2, 3, 5, 6};
    vector<int> T = {2, 4, 1, 3, 2};
    int N = 5;
    printOptimal(L, T, N);
    return 0;
}
