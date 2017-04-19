// 216. Combination Sum III
// source: https://leetcode.com/problems/combination-sum-iii
// difficulty: Medium
// author: simplc

/**
Description:
    Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Example 1:

    Input: k = 3, n = 7

    Output:

    [[1,2,4]]

Example 2:

    Input: k = 3, n = 9

    Output:

    [[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;

        vector<int> tmp(1, n);
        dfs(res, tmp, k);

        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int> tmp, const int& k) {
        int len = tmp.size();

        if (k == len) {
            if (tmp[len - 1] <= 9)
                res.push_back(tmp);
            return;
        }

        int part = tmp[len - 1];
        int base = (len == 1 ? 1 : tmp[len - 2] + 1);

        for (int i = base; ; ++i) {
            if (part - i <= i) break;

            tmp.pop_back();
            tmp.push_back(i); tmp.push_back(part - i);
            dfs(res, tmp, k);
            tmp.pop_back(); tmp.pop_back();
            tmp.push_back(part);
        }
    }
};
