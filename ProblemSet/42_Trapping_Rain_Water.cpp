// 42. Trapping Rain Water
// source: https://leetcode.com/problems/trapping-rain-water
// difficulty: Hard
// author: simplc

/**
Description:
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*/




class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        
        int res = 0, lower = 0, level = 0;
        while (i < j) {
            lower = height[height[i] < height[j] ? i++ : j--];
            level = max(level, lower);
            res += (level - lower);
        }
        
        return res;
    }
};