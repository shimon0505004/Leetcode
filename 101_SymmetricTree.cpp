/*
	https://leetcode.com/problems/symmetric-tree/
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
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return true;
        else //both left and right exist;
            return isMirror(root->left,root->right);
    }
    
    bool isMirror(TreeNode* left, TreeNode* right)
    {
        if(left==nullptr && right==nullptr)
            return true;
        else if((left!=nullptr && right==nullptr) || (right!=nullptr && left==nullptr))
            return false;
        else if((left->val==right->val) && (isMirror(left->left,right->right)) && (isMirror(left->right,right->left)))
            return true;
        else
            return false;
    }
};