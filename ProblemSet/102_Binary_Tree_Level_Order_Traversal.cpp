// 102. Binary Tree Level Order Traversal
// source: https://leetcode.com/problems/binary-tree-level-order-traversal
// difficulty: Medium
// author: simplc

/**
Description:
    Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

    For example:
    Given binary tree [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /  \
       15   7
    return its level order traversal as:
    [
      [3],
      [9,20],
      [15,7]
    ]
*/


class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (!root) return res;

        queue<pair<TreeNode*, int>> q;

        q.push(pair<TreeNode*, int>(root, 0));

        pair<TreeNode*, int> node;
        int now = -1;
        while (!q.empty()) {
            node = q.front();
            q.pop();

            if (node.second > now){
                now = node.second;
                res.push_back(vector<int>());
            }

            res[now].push_back(node.first->val);

            if (node.first->left) q.push(pair<TreeNode*, int>(node.first->left, node.second + 1));
            if (node.first->right) q.push(pair<TreeNode*, int>(node.first->right, node.second + 1));
        }

        return res;
    }
};
