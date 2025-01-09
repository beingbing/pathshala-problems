~~ custom sorting ~~

given two strings s and t, both containing lowercase alphabets only. len(s) <= 26 with all distinct characters.
sort characters of t based on order of characters in s.

bool cmpr(pair<int, int> x, pair<int, int> y) {
    return x.second < y.second;
}

vector<int> rank(26, INT_MAX)
for (int i{0}; i<s.size(); i++) rank[s[i]-'a] = i;
vector<pair<int, int> vec;
for (int i{0}; i<t.size(); i++) vec.push_back({t[i], rank[t[i]-'a]});
sort(vec.begin(), bec.end(), cmpr);
str ans;
for (auto ele : vec) str += vec.first;
return ans;
