/*
	shimon0505004
	145. Binary Tree Postorder Traversal
	https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> returnval;
        
        if(root!=nullptr)
        {            
            vector<int> left = postorderTraversal(root->left);
            returnval.insert(returnval.end(),left.begin(),left.end());

            vector<int> right = postorderTraversal(root->right);            
            returnval.insert(returnval.end()  ,right.begin(),right.end());

            returnval.push_back(root->val);
        }
        
        return returnval;
    }
};