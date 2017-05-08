// 56. Merge Intervals
// source: https://leetcode.com/problems/merge-intervals
// difficulty: Medium
// author: simplc

/**
Description:
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

*/

/*  struct Interval {
       int start;
       int end;
       Interval() : start(0), end(0) {}
       Interval(int s, int e) : start(s), end(e) {}
    };
*/

class Solution {
public:
    static bool cmp(Interval i1, Interval i2) {
        if (i1.start == i2.start) return i1.end < i2.end;
        return i1.start < i2.start;
    }
   
    
    vector<Interval> merge(vector<Interval>& intervals) {
        int l = intervals.size();
        if(l <= 1) return intervals;  
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), cmp);
        Interval tmp = intervals[0];
        
        for (int i = 1; i < l; ++i){
            //if (intervals[i].start == intervals[i].end) continue;
            if (intervals[i].start <= tmp.end) 
                tmp.end = max(intervals[i].end, tmp.end);
            else {
                res.push_back(tmp);
                tmp = intervals[i];
            }
            if (i == l-1) res.push_back(tmp);
        }
        
        return res;
    }
};