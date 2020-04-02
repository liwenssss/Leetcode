#include "header.h"
using namespace std;

/**
 * 复制一份数组，之后老老实实计算
 * */
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size();
        vector<vector<int>> tmp(row, vector<int>(col));
        int dir[2][8] = {{-1, -1, -1, 0, 0, 1, 1, 1}, {-1, 0, 1, -1, 1, -1, 0, 1}};
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                tmp[i][j] = board[i][j];
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int sum = 0;
                for (int t = 0; t < 8; t++) {
                    int x = i + dir[0][t], y = j + dir[1][t];
                    if (x < 0 || x >= row || y < 0 || y >= col) {
                        continue;
                    }
                    else {
                        sum += tmp[x][y];
                    }
                }
                if (tmp[i][j] == 1) {
                    if (sum < 2 || sum > 3) {
                        board[i][j] = 0;
                    }
                }
                else if (tmp[i][j] == 0) {
                    if (sum==3) {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> vec = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    sol.gameOfLife(vec);
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[0].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}