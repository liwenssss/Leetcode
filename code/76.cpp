#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() == 0 || t.length() == 0) {
            return "";
        }
        int len = INT_MAX;
        int start = 0, left = 0, right = 0, count = 0;
        map<char, int> mp;
        map<char, int> window;
        for (char c:t) { //统计t中每个字符的数目
            mp[c]++;
        }
        int lent = mp.size();
        for (; right < s.length(); right++) {
            char c = s[right];
            if (mp[c] > 0) { //窗口右端扩充，添加符合要求的字符
                window[c]++;
                if (window[c] == mp[c]) {
                    count++;
                }
            }
            while (count == lent) { // 窗口左端缩小，寻找最下的窗口
                if (right-left < len) {
                    len = right - left + 1;
                    start = left;
                }

                char c2 = s[left];
                if (mp[c2] >0) {
                    window[c2]--;
                    if (window[c2] < mp[c2]) {
                        count--;
                    }
                }
                left++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

int main() {
    Solution sol;
    string s = "aa", t = "aa";
    cout << sol.minWindow(s, t);
}