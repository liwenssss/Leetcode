#include"header.h"
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res=0.0;
        int size = nums1.size() + nums2.size(), i = 0, j = 0;
        int iter_a, iter_b, iter=0, tar;
        double a = 0.0, b = 0.0;
        while (i <nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                tar = nums1[i++];
            }
            else {
                tar = nums2[j++];
            }
            if (iter == size/2-1) {
                a = (double)tar;
            }
            if (iter == size/2) {
                b = (double)tar;
                if (size % 2 == 1) {
                    return b;
                }
                else {
                    return (a + b) / 2;
                }
            }
            iter++;
        }
        if (i == nums1.size()) {
            while (j < nums2.size()) {
                tar = nums2[j++];
                if (iter == size/2-1) {
                    a = (double)tar;
                }
                if (iter == size/2) {
                    b = (double)tar;
                    if (size % 2 == 1) {
                        return b;
                    }
                    else {
                        return (a + b) / 2;
                    }
                }
                iter++;
            }
        }
        else {
            while (i < nums1.size()) {
                tar = nums1[i++];
                if (iter == size/2-1) {
                    a = (double)tar;
                }
                if (iter == size/2) {
                    b = (double)tar;
                    if (size % 2 == 1) {
                        return b;
                    }
                    else {
                        return (a + b) / 2;
                    }
                }
                iter++;
            }
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double res = sol.findMedianSortedArrays(nums1, nums2);
    cout << res << endl;
    return 0;
}