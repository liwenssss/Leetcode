#include"header.h"
using namespace std;

/**
 * 如果为(则入栈，入栈后栈的深度即是(的编号
 * 如果为)则出栈一个(，出栈前栈的深度即是)的编号
 * 要满足条件只用使得AB均分即可，可以将奇数编号分给A，偶数编号分给B
 * 事实上，维护一个变量来记录栈内元素的个数，并不用有实际的栈
*/

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int count = 0;
        vector<int> res;
        for (int i = 0; i < seq.length(); i++) {
            if (seq[i] == '(') {
                count++;
                res.push_back((count+1) % 2);
            }
            else if (seq[i] == ')') {
                res.push_back((count+1) % 2);
                count--;
            }
        }
        return res;
    }
};