// 63. Unique Paths II
// source: https://leetcode.com/problems/unique-paths-ii
// difficulty: Medium
// author: simplc

/**
Description:
    Follow up for "Unique Paths":

    Now consider if some obstacles are added to the grids. How many unique paths would there be?

    An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
    There is one obstacle in the middle of a 3x3 grid as illustrated below.

    [
      [0,0,0],
      [0,1,0],
      [0,0,0]
    ]
    The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

// time: O(m*n) space: O(m*n)
// Space complexity can be reduced to O(min{m, n})
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int dp[m][n];
        memset(dp, 0, sizeof(dp));

        dp[0][0] = 1;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] += (j > 0 ? dp[i][j - 1] : 0) + (i > 0 ? dp[i - 1][j] : 0);
            }

        return dp[m - 1][n - 1];
    }
};

// e.g. space: O(n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int dp[n];
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) dp[j] = 0;
                else dp[j] += (j > 0 ? dp[j - 1] : 0);
            }

        return dp[n - 1];
    }
};
