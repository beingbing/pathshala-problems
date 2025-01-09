#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
    vector<char> ch = {'a', 'b', 'c'};
    vector<string> ans;
    
    void helper(string str, int& n, int& k) {
        if (ans.size() == k) return;
        if (str.size() == n) {ans.push_back(str); return;}
        for (int i{0}; i<3; i++) {
            if (str.size() == 0 || str[str.size()-1] != ch[i])  {
                helper(str += ch[i], n, k);
                str.pop_back();
            }
        }
    }
    
public:
    string getHappyString(int n, int k) {
        string str;
        helper(str, n, k);
        if (ans.size() == k) return ans.back();
        return "";
    }
};

int main() {
    Solution* obj = new Solution();
    string ans = obj->getHappyString(1, 3);
    cout << ans << endl;
    return 0;
}

import java.util.ArrayList;
import java.util.List;

public class HappyStringGenerator {

    private static final char[] CHARACTERS = {'a', 'b', 'c'};
    private List<String> happyStrings;

    public String getHappyString(int n, int k) {
        happyStrings = new ArrayList<>();
        generateHappyStrings("", n);
        // Check if k is valid
        if (k > happyStrings.size()) return ""; // Not enough happy strings
        return happyStrings.get(k - 1); // Return kth happy string (1-indexed)
    }

    private void generateHappyStrings(String current, int n) {
        // Base case: if the current string length is equal to n
        if (current.length() == n) {
            happyStrings.add(current);
            return;
        }

        // Recursive case: iterate through 'a', 'b', and 'c'
        for (char ch : CHARACTERS) {
            // Check last character to maintain happy string conditions
            if (current.isEmpty() || current.charAt(current.length() - 1) != ch)
                generateHappyStrings(current + ch, n);
        }
    }

    public static void main(String[] args) {
        HappyStringGenerator generator = new HappyStringGenerator();
        System.out.println(generator.getHappyString(1, 3)); // Output: "c"
        System.out.println(generator.getHappyString(1, 4)); // Output: ""
        System.out.println(generator.getHappyString(3, 9)); // Output: "cab"
    }
}
