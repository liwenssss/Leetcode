#include"header.h"
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        word1 = " " + word1;
        word2 = " " + word2;
        int l1 = word1.length(), l2 = word2.length();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1));
        int len = 0;
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < l2; j++) {
                if (i == 0||j == 0) {
                    dp[i][j] = 0;
                }
                else if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                len = max(len, dp[i][j]);
            }
        }
        return l1 + l2 - 2 * len - 2;
    }
};

int main() {
    Solution sol;
    string s1 = "sea", s2 = "eat";
    cout << sol.minDistance(s1, s2) << endl;
}