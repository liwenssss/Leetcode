#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size == 0 || size == 1)
            return size;
        int i = 0, j = 1;
        for (; j < size; j++) {
            while (j <size && nums[j] == nums[i])
                j++;
            if (j < size)
                nums[++i] = nums[j];
        }
        return i + 1;
    }
};

int main() {
    vector<int> arr = {1, 1};
    Solution sol;
    int ans = sol.removeDuplicates(arr);
    cout << ans << endl;
    for (int i = 0; i < ans; i++) {
        cout << arr[i] << " ";
    }
}