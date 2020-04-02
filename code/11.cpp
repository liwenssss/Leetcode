#include"header.h"
using namespace std;

/**
 * 双指针：
 * 初始化时，左指针在最左端，右指针在最右端。
 * 如当前面积较大，则更新答案
 * 高度较小的指针向中间移动
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int ans = 0, l = 0, r = size - 1;
        while (l < r) {
            int cur = (r - l) * min(height[l], height[r]);
            ans = max(ans, cur);
            if (height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> vec = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution sol;
    cout << sol.maxArea(vec);
}