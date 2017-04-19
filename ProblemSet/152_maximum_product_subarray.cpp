// 152. Maximum Product Subarray
// source: https://leetcode.com/problems/maximum-product-subarray
// difficulty: Medium
// author: simplc

/**
Description:
    Find the contiguous subarray within an array (containing at least one number) which has the largest product.

    For example, given the array [2,3,-2,4],
    the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];

        int l = nums.size();

        // TWO dp arrays.
        // Using maxdp[i]/mindp[i] to maintain the MAX/MIN product of the first i nums. (The i-th num INCLUDED)
        int maxdp[l], mindp[l];

        maxdp[0] = mindp[0] = nums[0];

        for(int i = 1; i < l; ++i) {
            maxdp[i] = max(nums[i], nums[i] * (nums[i] > 0 ? maxdp[i - 1] : mindp[i - 1]));
            mindp[i] = min(nums[i], nums[i] * (nums[i] > 0 ? mindp[i - 1] : maxdp[i - 1]));
            res = max(res, maxdp[i]);
        }

        return res;
    }
};
