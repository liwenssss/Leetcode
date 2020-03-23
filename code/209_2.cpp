#include<iostream>
#include<vector>
using namespace std;

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int left = 0, sum = 0, len = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= s) {
                len = min(len, i - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return len == INT_MAX ? 0 : len;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {2,3,1,2,4,3};
    int s = 7;
    cout << sol.minSubArrayLen(s, vec);
}