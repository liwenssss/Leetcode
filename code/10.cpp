#include"header.h"
using namespace std;


/***
 * 递归方法：
 * 对于当前字符串分两种情况：
 * 1.第二个字符不是*
 * 2.第二个字符是*
 * 对于第一种情况，首先匹配第一个字符是否相等，随后再递归匹配后续字符，在比较第一个字符的时候，需要对'.'进行判断
 * 对于第二种情况，分两种情况：
 * 1.第一个字符不匹配，此时跳过*，递归匹配s与p[2:]
 * 2.第一个字符匹配，此时不跳过*，递归匹配s[1:]与p
 * 此种方法由于递归，需要耗费时间资源与堆栈资源，所以可以考虑非递归的解法。
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();
        bool first = s[0] && ((s[0] == p[0]) || (p[0] == '.'));
        if (p[1] == '*') {
            return (first && isMatch(s.substr(1, s.length() - 1), p)) ||
                   (isMatch(s, p.substr(2, p.length() - 1)));
        }
        else {
            return first && isMatch(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1));
        }
    }
};

int main() {
    Solution sol;
    string s = "ab", p = ".*";
    if (sol.isMatch(s, p)) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
}