// // haven't attepted yet

// #include <iostream>
// #include <vector>
// #include <string>
// #include <unordered_map>
// using namespace std;

// class Solution {
//     unordered_map<char, int> c2i;
//     unordered_map<int, char> i2c;
//     int limit = 0;

//     bool helper(vector<string> &words, string &result, int index, int widx, int sum) {
//         if (index == limit) return sum == 0; // to check if there is no carry

//         // if all the words are checked for given index
//         if (widx == words.size()) {
//             // if for corresponding index result character is not assigned a digit
//             // and the current accumulated sum has also do not have any character assigned
//             // then we have a match
//             if (c2i.count(result[index]) == 0 && i2c.count(sum % 10) == 0) {
//                 // the leading digit is trying to be 0
//                 if (sum % 10 == 0 && index + 1 == limit) return false;
//                 c2i[result[index]] = sum % 10;
//                 i2c[sum % 10] = result[index];
//                 bool tmp = helper(words, result, index + 1, 0, sum / 10);
//                 c2i.erase(result[index]);
//                 i2c.erase(sum % 10);
//                 return tmp;
//             // we have a character for current accumulated sum and it is matching
//             } else if (c2i.count(result[index]) && c2i[result[index]] == sum % 10) {
//                 // if it is leading and trying to be zero
//                 if (index + 1 == limit && 0 == c2i[result[index]]) return false;
//                 // now start check for next index
//                 return helper(words, result, index + 1, 0, sum / 10);
//             } else return false;
//         }

//         // if current word is shorter than the index to be considered then check next word
//         if (index >= words[widx].length()) return helper(words, result, index, widx + 1, sum);

//         // if current word is already used
//         if (c2i.count(words[widx][index])) {
//             // and the number assigned to it is 0, and that word is a leading character then it cant be accepted
//             if (index + 1 == words[widx].length() && words[widx].length() > 1 && c2i[words[widx][index]] == 0)
//                 return false;
//             // move to next word for same index to get total sum of words for that index
//             return helper(words, result, index, widx + 1, sum + c2i[words[widx][index]]);
//         }

//         for (int i = 0; i < 10; i++) { // loop over potential digits
//             // if we are currently looking for leading index, then it can not be 0
//             if (index + 1 == words[widx].length() && i == 0 && words[widx].length() > 1) continue;
//             if (i2c.count(i)) continue; // if index already used, cant use it again
//             c2i[words[widx][index]] = i;
//             i2c[i] = words[widx][index];
//             bool tmp = helper(words, result, index, widx + 1, sum + i);
//             c2i.erase(words[widx][index]);
//             i2c.erase(i);
//             if (tmp) return true;
//         }
//         return false;
//     }

// public:
//     bool isSolvable(vector<string> &words, string result) {
//         limit = result.length();
//         for (auto &w : words) if (w.length() > limit) return false;
//         for (auto &w : words) reverse(w.begin(), w.end());
//         reverse(result.begin(), result.end());
//         return helper(words, result, 0, 0, 0);
//     }
// };

// int main()
// {
//     vector<string> words = {"send", "more"};
//     string res = "money";
//     Solution *obj = new Solution();
//     cout << obj->isSolvable(words, res);
//     return 0;
// }