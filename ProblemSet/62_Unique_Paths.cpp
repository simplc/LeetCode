// 62. Unique Paths
// source: https://leetcode.com/problems/unique-paths
// difficulty: Medium
// author: simplc

/**
Description:
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 

The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n];
        for (int i = 0; i < n; ++i) dp[i] = 1;
        
        for (int i = 1; i < m; ++i) {
            dp[0] = 1;
            for (int j = 1; j < n; ++j) dp[j] += dp[j - 1];
        }
         return dp[n - 1];
    }
};