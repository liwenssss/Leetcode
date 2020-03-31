#include"header.h"
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len==0 || len==1) {
            return s;
        }
        int left = 0, right = 0;
        int curlen = 1, maxlen = 0, maxstart=0;
        for(int i = 0; i < len; i++) {
            left = i - 1, right = i + 1;
            while (left >= 0 && s[left] == s[i]) {
                left--;
                curlen++;
            }
            while (right < len && s[right] == s[i]) {
                right++;
                curlen++;
            }
            while (left >= 0 && right < len && s[left] == s[right]) {
                curlen += 2;
                left--;
                right++;
            }
            if (curlen > maxlen) {
                maxlen = curlen;
                maxstart = left;
            }
            curlen = 1;
        }
        return s.substr(maxstart + 1, maxlen);
    }
};

int main() {
    Solution sol;
    string str = "babad";
    cout << sol.longestPalindrome(str) << endl;
}