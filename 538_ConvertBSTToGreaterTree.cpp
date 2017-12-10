/*
	https://leetcode.com/problems/convert-bst-to-greater-tree/
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
    int sum = 0;
    
    TreeNode* convertBST(TreeNode* root) {
        convert(root);
        return root;
    }
    
    void convert(TreeNode* root)
    {
        if(root==nullptr)
            return;
        convert(root->right);
        root->val+=sum;
        sum=root->val;
        convert(root->left);
    }
};