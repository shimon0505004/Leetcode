/*
	https://leetcode.com/problems/diameter-of-binary-tree/
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
            return 0;
        else if(root->right==nullptr)
            return std::max(height(root),diameterOfBinaryTree(root->left));
        else if(root->left==nullptr)
            return std::max(height(root),diameterOfBinaryTree(root->right));
        else
            return std::max(2+height(root->left)+height(root->right),std::max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));

    }
    
    int height(TreeNode* root)
    {
        if(root->left==nullptr && root->right==nullptr)
            return 0;
        else if(root->right==nullptr)
            return (1 + height(root->left));
        else if(root->left==nullptr)
            return (1 + height(root->right));
        else
            return (1 + max(height(root->left),height(root->right)));
    }
    
};