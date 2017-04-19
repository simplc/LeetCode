// 53. Maximum Subarray
// source: https://leetcode.com/problems/maximum-subarray
// difficulty: Easy
// author: simplc

/**
Description:
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        // dp[i] : the max sum of subarrays which ENDS WITH nums[i]
        int dp[n], res;

        res = dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            res = max(res, dp[i]);
        }

        return res;
    }
};
