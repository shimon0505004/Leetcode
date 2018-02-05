/*
	shimon0505004
	144. Binary Tree Preorder Traversal
	https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> returnval;
        
        if(root!=nullptr)
        {
            returnval.push_back(root->val);
            
            vector<int> left = preorderTraversal(root->left);
            returnval.insert(returnval.end(),left.begin(),left.end());

            vector<int> right = preorderTraversal(root->right);            
            returnval.insert(returnval.end()  ,right.begin(),right.end());
        }
        
        return returnval;
    }
};