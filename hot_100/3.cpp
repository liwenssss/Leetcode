#include <iostream>
#include <string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int ans = 0, start = 0;
        unordered_set<char> se;
        for (int i = 0; i < len; i++) {
            while (se.find(s[i]) != se.end() && start <= i) {
                se.erase(s[start]);
                start++;
            }
            se.insert(s[i]);
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string str = "aaaaaaabbbbbcdee";
    cout << sol.lengthOfLongestSubstring(str);
    return 0;
}