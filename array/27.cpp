#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int t = 0, size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] != val) {
                nums[t++] = nums[i];
            }
        }
        return t;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 4, 5};
    Solution sol;
    int ans = sol.removeElement(arr, 4);
    cout << ans << endl;
    for (int i = 0; i < ans; i++) {
        cout << arr[i] << " ";
    }
}