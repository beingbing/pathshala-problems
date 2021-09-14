#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> ans;

void generate(string temp, int pl, int pr, int bl, int br, int& paranCnt, int& braceCnt) {
    if (temp.size() == 2*(paranCnt+braceCnt)) {ans.push_back(temp);return;}
    if ((pl+pr) < 2*paranCnt) {
        if (pl == pr) generate(temp+'(', pl+1, pr, bl, br, paranCnt, braceCnt);
        else if (pl > pr) {
            if (pl == paranCnt) {
                int pc{0}, bc{0};
                for (auto i{temp.size()-1}; i>=0 and i <= temp.size(); i--) {
                    if (temp[i] == '(') pc++;
                    else if (temp[i] == ')') pc--;
                    if (temp[i] == '{') bc++;
                    else if (temp[i] == '}') bc--;
                    if (bc > 0 and pc == 0) break;
                    else if (temp[i] == '(' and pc > 0 and bc == 0) {
                        generate(temp+')', pl, pr+1, bl, br, paranCnt, braceCnt);
                        break;
                    }
                }
            } else {
                generate(temp+'(', pl+1, pr, bl, br, paranCnt, braceCnt);
                int pc{0}, bc{0};
                for (auto i{temp.size()-1}; i>=0 and i <= temp.size(); i--) {
                    if (temp[i] == '(') pc++;
                    else if (temp[i] == ')') pc--;
                    if (temp[i] == '{') bc++;
                    else if (temp[i] == '}') bc--;
                    if (bc > 0 and pc == 0) break;
                    else if (temp[i] == '(' and pc > 0 and bc == 0) {
                        generate(temp+')', pl, pr+1, bl, br, paranCnt, braceCnt);
                        break;
                    }
                }
            }
        }
    }
    if ((bl+br) < 2*braceCnt) {
        if (bl == br) generate(temp+'{', pl, pr, bl+1, br, paranCnt, braceCnt);
        else if (bl > br) {
            if (bl == braceCnt) {
                int pc{0}, bc{0};
                for (auto i{temp.size()-1}; i>=0 and i <= temp.size(); i--) {
                    if (temp[i] == '(') pc++;
                    else if (temp[i] == ')') pc--;
                    if (temp[i] == '{') bc++;
                    else if (temp[i] == '}') bc--;
                    if (pc > 0 and bc == 0) break;
                    else if (temp[i] == '{' and bc > 0 and pc == 0) {
                        generate(temp+'}', pl, pr, bl, br+1, paranCnt, braceCnt);
                        break;
                    }
                }
            } else {
                generate(temp+'{', pl, pr, bl+1, br, paranCnt, braceCnt);
                int pc{0}, bc{0};
                for (auto i{temp.size()-1}; i>=0 and i <= temp.size(); i--) {
                    if (temp[i] == '(') pc++;
                    else if (temp[i] == ')') pc--;
                    if (temp[i] == '{') bc++;
                    else if (temp[i] == '}') bc--;
                    if (pc > 0 and bc == 0) break;
                    else if (temp[i] == '{' and bc > 0 and pc == 0) {
                        generate(temp+'}', pl, pr, bl, br+1, paranCnt, braceCnt);
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    int paranCnt, braceCnt;
    cin>>paranCnt>>braceCnt;
    generate("", 0, 0, 0, 0, paranCnt, braceCnt);
    for (auto str : ans) cout << str << endl;
    return 0;
}
