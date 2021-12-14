#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int appsCnt, eventsCnt;
    cin >> appsCnt >> eventsCnt;
    unordered_map<int, int> notiSeq, appUnreadNoti, appTotalNoti;
    int type, app, notiTillNow{0}, unreadCnt{0}, x{0};
    while (eventsCnt--) {
        cin >> type >> app;
        if (type == 1) {
            notiSeq[++notiTillNow] = app;
            appUnreadNoti[app]++;
            appTotalNoti[app]++;
            unreadCnt++;
        } else if (type == 2) {
            unreadCnt -= appUnreadNoti[app];
            appUnreadNoti[app] = 0;
        }
        else {
            int t = app;
            while (x < t) {
                app = notiSeq[++x];
                if (appTotalNoti[app]) appTotalNoti[app]--;
                if (appUnreadNoti[app] > appTotalNoti[app]) {
                    unreadCnt--;
                    appUnreadNoti[app]--;
                }
            }
        }
        cout << unreadCnt << endl;
    }
}
