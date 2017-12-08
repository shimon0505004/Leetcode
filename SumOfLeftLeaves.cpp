/*
	https://leetcode.com/submissions/detail/129799522/
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        if(root->left != nullptr)
        {
            if((root->left->left == nullptr)
               && (root->left->right == nullptr))
            {
                return (root->left->val + sumOfLeftLeaves(root->right));
            }
        }
        
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};