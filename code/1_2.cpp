#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> res;
        map<int, int> mp;
        for (int i = 0; i < size; i++) {
            mp.insert(make_pair(nums[i], i));
        }
        for (int i = 0; i < size; i++) {
            int tar = target - nums[i];
            if (mp.find(tar) != mp.end() && mp[tar] != i) {
                res.push_back(i);
                res.push_back(mp[tar]);
                return res;
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