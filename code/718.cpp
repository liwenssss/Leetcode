#include "header.h"
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int l1 = A.size(), l2 = B.size(), res = 0;
        vector<vector<int>>dp(l1+1, vector<int>(l2+1));
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < l2; j++) {
                if (A[i] == B[j]) {
                    if (i == 0||j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1,2,3,2,1};
    vector<int> b = {3,2,1,4,7};
    cout << sol.findLength(a, b);
}