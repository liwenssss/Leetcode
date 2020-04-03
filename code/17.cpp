#include "header.h"
using namespace std;

/**
 * 回溯、递归
 * 具体方法见fun函数，很好理解。
 * */
class Solution {
public:
    vector<vector<char>> phone = {{'a', 'b', 'c'},
                                      {'d', 'e', 'f'},
                                      {'g', 'h', 'i'},
                                      {'j', 'k', 'l'},
                                      {'m', 'n', 'o'},
                                      {'p', 'q', 'r', 's'},
                                      {'t', 'u', 'v'},
                                      {'w', 'x', 'y', 'z'}};
    vector<string> res;
    void fun(string cur, string next) {
        if (next.length() == 0) {
            res.push_back(cur);
        }
        else {
            int index = next[0] - '0';
            vector<char> str = phone[index-2];
            for (int i = 0; i < str.size(); i++) {
                fun(cur + str[i], next.substr(1));
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        if (len == 0) {
            return res;
        }
        else {
            fun("", digits);
            return res;
        }
    }
};

int main() {
    string str = "23";
    Solution sol;
    vector<string> res = sol.letterCombinations(str);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}