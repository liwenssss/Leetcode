#include "header.h"
using namespace std;

int getLCS(string s, string t) {
    int l1 = s.length(), l2 = t.length();
    int maxLength = 0;
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));

    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            if (s[i] == t[j]) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                maxLength = max(maxLength, dp[i][j]);
            }
        }
    }
    return maxLength;
}

int lcs(string s1, string s2, int l1, int l2) {
    if (l1 == 0 || l2 == 0) {
        return 0;
    }
    if (s1[l1-1] == s2[l2-1]) {
        return lcs(s1, s2, l1 - 1, l2 - 1) + 1;
    }
    else {
        return max(lcs(s1, s2, l1 - 1, l2), lcs(s1, s2, l1, l2 - 1));
    }
}

int main() {
    string s = "abcdefs", t = "anbmckd";
    int l1 = s.length(), l2 = s.length();
    cout << lcs(s, t, l1, l2) << endl;
    return 0;
}