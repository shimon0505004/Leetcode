/*
	shimon0505004
	https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root == p || root== q)
            return root;
        
        TreeNode* leftResult = lowestCommonAncestor(root->left , p , q);
        TreeNode* rightResult = lowestCommonAncestor(root->right, p , q);
        
        return ((leftResult != nullptr) ? ((rightResult != nullptr) ? root : leftResult) : rightResult); 
    }
};