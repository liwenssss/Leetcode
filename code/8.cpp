#include"header.h"
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int len = str.length(), i = 0;
        long long ans = 0;
        int flag = 1;
        while (i < len & str[i]==' ') {
            i++;
        }
        if (str[i] == '-') {
            flag = -1;
            i++;
        }
        else if (str[i] == '+') {
            i++;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            while (i <len) {
                if (str[i] >= '0' && str[i] <= '9') {
                    ans = ans * 10 + (str[i] - '0');
                    if (ans >= 2147483648) {
                        if (flag == 1)return INT_MAX;
                        else return INT_MIN;
                    }
                    i++;
                }
                else {
                    break;
                }
            }
        }
        return flag * ans;
    }
};

int main() {
    string str = "-231";
    Solution sol;
    cout << sol.myAtoi(str);
}