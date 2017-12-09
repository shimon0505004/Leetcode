/*
	https://leetcode.com/problems/path-sum/
	shimon0505004
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr)
            return false;
        else if(root->left==nullptr && root->right==nullptr)
            return (sum==root->val);
        else
        {
            int newSum = sum-root->val;
            return (hasPathSum(root->left,newSum) || hasPathSum(root->right,newSum));
        }
    }
};