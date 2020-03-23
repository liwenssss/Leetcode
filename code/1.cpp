#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> res;
        for (int i = 0; i < size - 1; i++) {
            int tar = target - nums[i];
            for (int j = i + 1; j < size; j++) {
                if (nums[j] == tar) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
                if (nums[j] > tar) {
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> ans = sol.twoSum(vec, 5);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}