// 51. N-Queens
// source: https://leetcode.com/problems/n-queens
// difficulty: Hard
// author: simplc

/**
Description:
    The n-queens puzzle is the problem of placing n queens on an n*n chessboard such that no two queens attack each other.

    Given an integer n, return all distinct solutions to the n-queens puzzle.

    Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

    For example,
    There exist two distinct solutions to the 4-queens puzzle:

    [
     [".Q..",  // Solution 1
      "...Q",
      "Q...",
      "..Q."],

     ["..Q.",  // Solution 2
      "Q...",
      "...Q",
      ".Q.."]
    ]

*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> pos(n, -1);
        vector<vector<string>> res;

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

    void dfs(vector<vector<string>>& res, vector<int>& pos, int col) {
        int n = pos.size();
        for (int i = 0; i < n; ++i) {
            if (valid(pos, col, i)) {
                pos[col] = i;
                if (col == n - 1) {
                    vector<string> ss(n, string(n, '.'));
                    for (int k = 0; k < n; ++k)
                        ss[pos[k]][k] = 'Q';
                    res.push_back(ss);
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
