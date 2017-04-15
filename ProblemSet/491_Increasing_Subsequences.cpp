// source: https://leetcode.com/problems/increasing-subsequences
// difficulty: Medium
// author: simplc

/*
Description:
    Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

Example:
    Input: [4, 6, 7, 7]
    Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]

Note:
    -The length of the given array will not exceed 15.
    -The range of integer in the given array is [-100,100].
    -The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.

*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> tmp;

        dfs(nums, 0, tmp, res);

        return vector<vector<int>>(res.begin(), res.end());
    }


    // tmp: can be regarded as PREFIX.
    void dfs(vector<int>& nums, int start, vector<int>& tmp, set<vector<int>>& res){
        if (tmp.size() >= 2) res.insert(tmp);

        // end when start == nums.size() - 1;
        for (int i = start; i < nums.size(); ++i) {
            if(tmp.empty() || nums[i] >= tmp.back()) {
                tmp.push_back(nums[i]);
                dfs(nums, i + 1, tmp, res);
                tmp.pop_back();
            }
        }
    }

};
