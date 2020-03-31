#include "header.h"
using namespace std;

// 没通过，但是这个方法我感觉可以改造，思路为每次
class Solution {
public:
    string multi_one(string num1, char num2) {
        string res = "";
        int tmp = 0, b = num2 - '0';
        for (int i = num1.length() - 1; i >= 0; i--) {
            int a = num1[i] - '0';
            char cur = (a * b + tmp) % 10 + '0';
            tmp = (a * b + tmp) / 10;
            res = cur + res;
        }
        if (tmp != 0) {
            char first = tmp + '0';
            res = first + res;
        }
        return res;
    }
    string move(string num) {
        return num + "0";
    }
    string add(string num1, string num2) {
        string res = "";
        int l1 = num1.length(), l2 = num2.length();
        if (l2 > l1) {
            swap(num1, num2);
            swap(l1, l2);
        }
        int tmp = 0;
        int i = l2 - 1, j = l1 - 1;
        for (; i >= 0; i--, j--) {
            int a = num2[i] - '0';
            int b = num1[j] - '0';
            char cur = (a + b + tmp) % 10 + '0';
            tmp = (a + b + tmp) / 10;
            res = cur + res;
        }
        if (tmp == 1) {
            num1[j] += 1;
        }
        res = num1.substr(0, j + 1) + res;
        return res;
    }
    string multiply(string num1, string num2) {
        if (num1=="0" || num2=="0")
            return "0";
        int l1 = num1.length(), l2 = num2.length();
        string res = "0";
        for (int i = 0; i < l1; i++) {
            string cur = multi_one(num2, num1[i]);
            res = add(move(res),cur);
        }
        if (res[0] == '0') {
            res = res.substr(1, res.length() - 1);
        }
        return res;
    }
};

int main() {
    Solution sol;
    string num1 = "123456789", num2 = "987654321";
    cout << sol.multiply(num1, num2);
}