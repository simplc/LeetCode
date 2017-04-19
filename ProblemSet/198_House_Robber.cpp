// 198. House Robber
// source: https://leetcode.com/problems/house-robber
// difficulty: Easy
// author: simplc

/**
Description:
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int res = 0, l = nums.size();
        int dp[l];

        for (int i = 0; i < l; ++i) {
            // only considering i - 2 and i - 3,
            //      since it's obvious that dp[i - 4] < dp[i - 2] and so on.
            dp[i] = nums[i] + max((i >= 2? dp[i - 2] : 0), (i >= 3 ? dp[i - 3] : 0));
            res = max(dp[i], res);
        }

        return res;
    }
};
