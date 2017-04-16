// 541. 01 Matrix
// source: https://leetcode.com/problems/01-matrix
// difficulty: Medium
// author: simplc


/*
Description:
    Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
    The distance between two adjacent cells is 1.

Example 1:
    Input:
    0 0 0
    0 1 0
    0 0 0

    Output:
    0 0 0
    0 1 0
    0 0 0

Example 2:
    Input:
    0 0 0
    0 1 0
    1 1 1

    Output:
    0 0 0
    0 1 0
    1 2 1
Note:
    The number of elements of the given matrix will not exceed 10,000.
    There are at least one 0 in the given matrix.
    The cells are adjacent in only four directions: up, down, left and right.
*/

/*
    Result: AC
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    bool valid(int a, int b, vector<vector<int> >& matrix){
        if (a < 0 || b < 0 || a >= matrix.size() || b >= matrix[0].size())
            return false;
        return true;
    }

public:
    // Method: BFS (using queue)
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {

        queue<pair<int, int> > q;

        // preprocessing
        //      Push all (i, j) with 0 into the queue (as starters).
        //      Set 1's to INFINITY, aiming to find the minimum.
        for (int i = 0; i < matrix.size(); ++i){
            for (int j = 0; j < matrix[0].size(); ++j){
                if (matrix[i][j] == 0)
                    q.push(pair<int, int>(i, j));
                else matrix[i][j] = INT_MAX;
            }
        }

        int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        pair<int, int> now;
        while(!q.empty()){
            now = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int a = now.first + dirs[i][0];
                int b = now.second + dirs[i][1];

                // IMPORTANT here
                // push (a, b) into the queue only when it is SUPPOSED to be updated.
                //      Because < or == means (a, b) has been updated before.
                if (valid(a, b, matrix)
                    && matrix[a][b] > matrix[now.first][now.second] + 1){
                    q.push(pair<int, int>(a, b));
                    matrix[a][b] = matrix[now.first][now.second] + 1;
                }
            }
        }

        return matrix;
    }
};

int main()
{
    vector<vector<int> > res, matrix(3, vector<int>(3, 0));
    matrix[1][1] = 1;

    Solution sol = Solution();
    res = sol.updateMatrix(matrix);

    for (int i = 0; i < res.size(); ++i){
        for (int j = 0; j < res[0].size(); ++j)
            cout << res[i][j] << ' ';
        cout << endl;
    }

    return 0;
}

