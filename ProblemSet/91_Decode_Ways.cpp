// 91. Decode Ways
// source: https://leetcode.com/problems/decode-ways
// difficulty: Medium
// author: simplc

/**
Description:
    A message containing letters from A-Z is being encoded to numbers using the following mapping:

    'A' -> 1
    'B' -> 2
    ...
    'Z' -> 26

    Given an encoded message containing digits, determine the total number of ways to decode it.

    For example,
    Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

    The number of ways decoding "12" is 2.
*/

class Solution {
public:
    int numDecodings(string s) {
        int l = s.length();
        if (l == 0) return 0;

        // dp[i]:  total ways to decode using the first i chars
        // end[i]: ways to decode using the first i chars WITH the i-th char as a SINGLE one.
        int dp[l], end[l];

        dp[0] = end[0] = (s[0] == '0' ? 0 : 1);
        for (int i = 1; i < l; ++i) {
            if (s[i] == '0') dp[i] = end[i] = 0;
            else dp[i] = end[i] = dp[i - 1];
            if (s[i - 1] < '2' || (s[i - 1] == '2' && s[i] <= '6')) //
                dp[i] += end[i - 1];
        }

        return dp[l - 1];
    }
};
