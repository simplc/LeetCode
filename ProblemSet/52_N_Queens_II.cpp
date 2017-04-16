// 52. N-Queens II
// source: https://leetcode.com/problems/n-queens-ii
// difficulty: Hard
// author: simplc

/**
Description:
    Follow up for N-Queens problem.

    Now, instead outputting board configurations, return the total number of distinct solutions.

*/


class Solution {
public:
    int totalNQueens(int n) {
        vector<int> pos(n, -1);
        int res = 0;

        dfs(res, pos, 0);
        return res;
    }

private:

    bool valid(const vector<int>& pos, int col, int i){
        for (int k = 0; k < col; ++k) {
            if (pos[k] == i) return false;
            if (abs(pos[k] - i) == col - k) return false;
        }

        return true;
    }

    void dfs(int& res, vector<int>& pos, int col) {
        int n = pos.size();
        for (int i = 0; i < n; ++i) {
            if (valid(pos, col, i)) {
                pos[col] = i;
                if (col == n - 1) {
                    ++ res;
                    break;
                }
                else {
                    dfs(res, pos, col + 1);
                    pos[col] = -1;
                }
            }
        }
    }
};
