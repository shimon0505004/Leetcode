/*
	shimon0505004
	94. Binary Tree Inorder Traversal
	https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> returnval;
        
        if(root!=nullptr)
        {
            vector<int> left = inorderTraversal(root->left);
            returnval.push_back(root->val);
            vector<int> right = inorderTraversal(root->right);
            
            returnval.insert(returnval.begin(),left.begin(),left.end());
            returnval.insert(returnval.end()  ,right.begin(),right.end());
        }
        
        return returnval;
    }
};