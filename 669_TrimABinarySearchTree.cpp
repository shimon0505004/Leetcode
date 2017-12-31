/*
	shimon0505004
	669. Trim a Binary Search Tree
	https://leetcode.com/problems/trim-a-binary-search-tree
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root!=nullptr)
        {
            if(root->val < L)
                return trimBST(root->right, L,  R);
            else if(root->val > R)
                return trimBST(root->left,  L,  R);
            else
            {
                root->left = trimBST(root->left, L , R);
                root->right = trimBST(root->right, L , R);
            }            
        }
        return root;
    }
};