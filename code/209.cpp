#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int left = 0, right = 0, sum = nums[right], len = INT_MAX;
        while (right < nums.size()) {
            while (right < nums.size() && sum < s) {
                right++;
                if (right < nums.size())
                    sum += nums[right];
            }
            if (right == nums.size() && sum < s) {
                break;
            }
            if (sum >= s) {
                if (len > right - left + 1) {
                    len = right - left + 1;
                }
                if (right - left > 1) {
                    sum -= nums[left];
                    left++;
                }
                else {
                    if (nums[right] >= s) {
                        len = 1;
                    }
                    break;
                }
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {1,4,4};
    int s = 4;
    cout << sol.minSubArrayLen(s, vec);
}