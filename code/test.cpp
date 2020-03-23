#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6};
    auto upper = upper_bound(vec.begin(), vec.end(), 5) - vec.begin();
    auto lower = lower_bound(vec.begin(), vec.end(), 5) - vec.begin();
    cout << upper << endl;
    cout << lower << endl;
    return 0;
}