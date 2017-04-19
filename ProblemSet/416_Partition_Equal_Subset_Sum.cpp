// 416. Partition Equal Subset Sum
// source: https://leetcode.com/problems/partition-equal-subset-sum
// difficulty: Medium
// author: simplc

/**
Description:
    Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
    Each of the array element will not exceed 100.
    The array size will not exceed 200.

Example 1:
    Input: [1, 5, 11, 5]
    Output: true

    Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:
    Input: [1, 2, 3, 5]
    Output: false

    Explanation: The array cannot be partitioned into equal sum subsets.
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 == 1) return false;

        sum /= 2;

        // dp[sum] means whether we can form sum using some nums.
        bool dp[sum + 1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;

        for (int num : nums) {
            // Inverse order to avoid duplicate updating.
            for (int j = sum - num; j >= 0; --j)
                dp[num + j] |= dp[j];
            if (dp[sum]) return true;
        }

        return false;
    }
};
