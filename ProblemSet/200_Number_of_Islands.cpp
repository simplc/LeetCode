// source: https://leetcode.com/problems/number-of-islands
// difficulty: Medium
// author: simplc

/*
Description:
    Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
    An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
    You may assume all four edges of the grid are all surrounded by water.

Example 1:

    11110
    11010
    11000
    00000

Answer: 1

Example 2:

    11000
    11000
    00100
    00011

Answer: 3
*/


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:

    bool valid(int a, int b, int row, int col){
        if (row < 0 || col < 0 || a <= row || b <= col) return false;
        return true;
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int a = grid.size(), b = grid[0].size();
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        queue<pair<int, int> > q;
        vector<vector<bool> > visited(a, vector<bool>(b, false));

        int cnt = 0;
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j){
                if (grid[i][j] == '1' && !visited[i][j]) {
                    visited[i][j] = true;
                    q.push(pair<int, int>(i, j));

                    pair<int, int> now;
                    while (!q.empty()) {
                        now = q.front();
                        q.pop();
                        for (int k = 0; k < 4; ++k) {
                            int row = now.first + dir[k][0];
                            int col = now.second + dir[k][1];

                            if (valid(a, b, row, col)
                                    && !visited[row][col]
                                    && grid[row][col] == '1') {
                                visited[row][col] = true;
                                q.push(pair<int, int>(row, col));
                            }
                        }

                    }
                    ++cnt;
                }
            }
        }

        return cnt;

    }
};
