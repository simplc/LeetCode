// 377. Combination Sum IV
// source: https://leetcode.com/problems/combination-sum-iv
// difficulty: Medium
// author: simplc

/**
Description:
    Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:
    nums = [1, 2, 3]
    target = 4

    The possible combination ways are:
    (1, 1, 1, 1)
    (1, 1, 2)
    (1, 2, 1)
    (1, 3)
    (2, 1, 1)
    (2, 2)
    (3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[i] : # ways to get a sum of i
        int dp[target + 1] = {1};
        for (int i = 1; i <= target; ++i)
            for (int num : nums)
                if (i >= num) dp[i] += dp[i - num];

        return dp[target];
    }
};
