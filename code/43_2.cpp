#include"header.h"
using namespace std;

// 把每一位的结果存下来，之后统一进位
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int l1 = num1.length(), l2 = num2.length();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> res(l1 + l2 + 1, 0);
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < l2; j++) {
                res[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = 0; i < res.size(); i++) {
            int cur = res[i];
            res[i] = res[i] % 10;
            if (i < res.size()-1)
            res[i + 1] += cur / 10;
        }
        reverse(res.begin(), res.end());
        int i = 0;
        while (res[i] == 0)
            i++;
        string ans = "";
        for (; i < res.size(); i++) {
            ans += (res[i] + '0');
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string num1 = "9", num2 = "9";
    cout << sol.multiply(num1, num2);
}