/*
	https://leetcode.com/problems/merge-two-binary-trees/
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==nullptr && t2!=nullptr)
            return t2;
        else if(t1!=nullptr && t2==nullptr)
            return t1;
        else if(t1==nullptr && t2==nullptr)
            return nullptr;
        else
        {
            TreeNode* left = mergeTrees(t1->left,t2->left);
            TreeNode* right = mergeTrees(t1->right,t2->right);
            t1->val += t2->val;
            t1->left = left;
            t1->right = right;
            return t1;
        }
    }
};