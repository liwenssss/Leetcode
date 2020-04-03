#include"header.h"
using namespace std;


/**
 * 双指针法，首先排序，对于每一个nums[i]，对其后的数组进行双指针寻找另外两个数，根据三个数的和的大小移动指针。
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> res;
        if (size < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size-2; i++) {
            if (nums[i] > 0) {
                return res;
            }
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int l = i + 1, r = size - 1;
            while (r <size && l < r) {
                if (nums[i] + nums[l] + nums[r] == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l+1] == nums[l]) {
                        l = l + 1;
                    }
                    while (l < r && nums[r-1] == nums[r]) {
                        r = r - 1;
                    }
                    l++;
                    r--;
                }
                else if (nums[i] + nums[l] + nums[r] > 0) {
                    r--;
                }
                else if (nums[i] + nums[l] + nums[r] < 0) {
                    l++;
                }
            }
        }
        return res;   
    }
};

int main() {
    vector<int> vec = {-1, 0, 1, 2, -1, -4};
    Solution sol;
    vector<vector<int>> res = sol.threeSum(vec);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}