/*
	https://leetcode.com/problems/balanced-binary-tree/
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
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)
            return true;
        else if(root->left==nullptr && root->right==nullptr)
            return true;
        else
        {
            int diff = height(root->left) - height(root->right);
            bool isThisBalanced = (diff==0 || diff==1 || diff==-1);
            return isThisBalanced && isBalanced(root->left) && isBalanced(root->right);
        }
    }
    
    int height(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        else if(root->left==nullptr && root->right==nullptr)
            return 1;
        else
            return 1+ max(height(root->left), height(root->right));
    }
};