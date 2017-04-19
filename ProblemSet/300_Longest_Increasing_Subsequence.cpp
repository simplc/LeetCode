// 300. Longest Increasing Subsequence
// source: https://leetcode.com/problems/longest-increasing-subsequence
// difficulty: Medium
// author: simplc

/**
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

// time: O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int l = nums.size();
        if (l == 0) return 0;

        int dp[l];
        int res = 1;
        for (int i = 0; i < l; ++i) dp[i] = 1;

        for (int i = 1; i < l; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] = max(dp[i], nums[i] > nums[j] ? dp[j] + 1 : 1);
                res = max(res, dp[i]);
            }
        }

        return res;
    }
};


// time: O(n*logn)
/**
Explanation:
    'tails' is an array storing the smallest tail of all increasing subsequences with length i+1 in tails[i].
    For example, say we have nums = [4,5,6,3], then all the available increasing subsequences are:
    len = 1   :      [4], [5], [6], [3]   => tails[0] = 3
    len = 2   :      [4, 5], [5, 6]       => tails[1] = 5
    len = 3   :      [4, 5, 6]            => tails[2] = 6
    We can easily prove that tails is a increasing array. Therefore it is possible to do a BINARY SEARCH in tails array to find the one needs update.

    Each time we only do one of the two:
        (1) if x is larger than all tails, append it, increase the size by 1
        (2) if tails[i-1] < x <= tails[i], update tails[i]
    Doing so will maintain the tails invariant. The the final answer is just the size.

*/
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int l = nums.size();
        if (l == 0) return 0;

        int tails[l];
        int size = 0;
        for (int x : nums) {
            int i = 0, j = size;

            // To find the first element in 'tails' which is >= x
            //      The found element has index i (If not found, i == j (i.e. i == size))
            //      When we found it, update the 'tails' array
            while (i != j) {
                int m = (i + j) / 2;
                if (tails[m] < x) i = m + 1;
                else j = m;
            }
            tails[i] = x;

            // Case where we cannot find such i (tails[i] >= x).
            if (i == size) ++size;
        }
        return size;
    }
};
