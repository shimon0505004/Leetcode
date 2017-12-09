/*
	https://leetcode.com/problems/minimum-depth-of-binary-tree/
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
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        else if(root->right==nullptr && root->left!=nullptr)
            return minDepth(root->left)+1;
        else if(root->left==nullptr && root->right!=nullptr)
            return minDepth(root->right)+1;
        
        return min(minDepth(root->left),minDepth(root->right)) + 1;
    }
};