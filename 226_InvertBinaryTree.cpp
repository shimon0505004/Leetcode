/*
	https://leetcode.com/problems/invert-binary-tree/
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
    TreeNode* invertTree(TreeNode* root) {
        if(root!=nullptr && (root->left!=nullptr || root->right!=nullptr))
        {
            TreeNode* temp = root->right;
            root->right = invertTree(root->left);
            root->left = invertTree(temp);
        }
        
        return root;
    }
};