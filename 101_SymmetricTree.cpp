
/*
	shimon0505004
	101. Symmetric Tree
	https://leetcode.com/problems/symmetric-tree/
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
    bool isMirror(TreeNode* leftRoot, TreeNode* rightRoot)
    {
        if(leftRoot!=nullptr && rightRoot!=nullptr)
        {
            if(leftRoot->val != rightRoot->val)
                return false;
            
            return (isMirror(leftRoot->left,rightRoot->right)
                && isMirror(leftRoot->right,rightRoot->left));
        }
        return ((leftRoot==nullptr) && (rightRoot==nullptr));
    }
    
    
    bool isSymmetric(TreeNode* root) {
        if(root!=nullptr)
            return isMirror(root->left,root->right);

        return true;
    }
    
    
};