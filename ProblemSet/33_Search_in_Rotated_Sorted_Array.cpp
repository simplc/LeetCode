// 33. Search in Rotated Sorted Array
// source: https://leetcode.com/problems/search-in-rotated-sorted-array
// difficulty: Medium
// author: simplc

/**
Description:
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        
        while (l <= r) {
            mid = (l + r) / 2;
            
            if (nums[mid] == target) return mid;
            
            if (nums[mid] >= nums[l]) {
                if (target >= nums[l] && target < nums[mid])
                    r = mid - 1;
                else l = mid + 1;
            }
            
            if (nums[mid] <= nums[r]) {
                if (target <= nums[r] && target > nums[mid])
                    l = mid + 1;
                else r = mid - 1;
            }
        }
        
        return -1;
    }
};