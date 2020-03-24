#include"header.h"
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int left=0, right=0, tol=2, match=0, res=0;
        map<int, int> window;
        while (right < tree.size()) {
            while (right < tree.size() && match <= tol) {
                int cur = tree[right];
                if (window[cur] == 0)
                    match++;
                if (match <= tol) {
                    window[cur]++;
                    right++;
                }
                else {
                    match--;
                    break;
                }
            }
            // cout << right << " " << left <<endl;
            res = max(res, right-left);
            
            while (left < right && match==tol) {
                int remove = tree[left];
                window[remove]--;
                if (window[remove] == 0) {
                    match--;
                }
                left++;
            }
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> tree = {0, 1, 2, 2};
    int res = sol.totalFruit(tree);
    cout << res;

}