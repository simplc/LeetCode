// 130. Surrounded Regions
// source : https://leetcode.com/problems/surrounded-regions/
// difficulty: Medium
// author : simplc

/**
Description:
    Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

    A region is captured by flipping all 'O's into 'X's in that surrounded region.

    For example,
    X X X X
    X O O X
    X X O X
    X O X X

    After running your function, the board should be:
    X X X X
    X X X X
    X X X X
    X O X X
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:

    // judge if it is OUT OF BOUND
    bool valid(int x, int y,vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        if (x < 0 || y < 0 || x >= r || y >= c) return false;
        else return true;
    }

    // judge if it is exactly BOUND
    bool isBound(int x, int y, int r, int c) {
        if (x == 0 || y == 0 || x == (r - 1) || y == (c - 1)) return true;
        else return false;
    }

    /*
        Method: Each time when we meet 'O' which is a BOUNDARY:
                    change it to 'B';
                    change all 'O's it CAN REACH to 'B' (using BFS)

                'O' that is not a BOUNARY and not REACHED by others:
                    they are surrounded by 'X' exactly.

    */
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        if (r == 0) return;
        int c = board[0].size();

        int dir[4][2]  = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        for (int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j)

                // meet 'O' and is boundary
                if (board[i][j] == 'O' && isBound(i, j, r, c)) {
                    queue<pair<int, int>> q;

                    q.push(pair<int, int>(i, j));
                    board[i][j] = 'B';

                    pair<int, int> now;
                    while (!q.empty()) {
                        now = q.front();
                        q.pop();

                        // To the four directions.
                        for (int k = 0; k < 4; ++k) {
                            int x = now.first + dir[k][0];
                            int y = now.second + dir[k][1];

                            // Ignore the invalid dirs.
                            if (!valid(x, y,board)) continue;

                            if (board[x][y] == 'O') {
                                q.push(pair<int, int>(x, y));
                                board[x][y] = 'B';
                            }
                        }
                    }
                }

        // Finally: O->X (inner O being surrounded)
        //          B->O (boundaries)
        for (int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'B') board[i][j] = 'O';
            }
    }
};
