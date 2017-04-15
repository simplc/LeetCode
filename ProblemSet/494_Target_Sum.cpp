// source: https://leetcode.com/problems/target-sum
// difficulty: Medium
// author: simplc

/*
Description:
    You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -.
        For each integer, you should choose one from + and - as its new symbol.
    Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
    Input: nums is [1, 1, 1, 1, 1], S is 3.
    Output: 5

Explanation:

    -1+1+1+1+1 = 3
    +1-1+1+1+1 = 3
    +1+1-1+1+1 = 3
    +1+1+1-1+1 = 3
    +1+1+1+1-1 = 3

    There are 5 ways to assign symbols to make the sum of nums be target 3.

Note:
    The length of the given array is positive and will not exceed 20.
    The sum of elements in the given array will not exceed 1000.
    Your output answer is guaranteed to be fitted in a 32-bit integer.
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int findWays(vector<int>& nums, int start, int S){
        if (start == nums.size() - 1){
            if(nums[start] == abs(S)) {
                if (S == 0) return 2;
                else return 1;
            }
            else return 0;
        }
        return findWays(nums, start + 1, S - nums[start]) + findWays(nums, start + 1, S + nums[start]);
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        return findWays(nums, 0, S);
    }
};

