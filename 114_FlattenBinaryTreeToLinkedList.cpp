/*
	shimon0505004
	114. Flatten Binary Tree to Linked List
	https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    
    TreeNode* preOrder(TreeNode* root)
    {
        if(!((root == nullptr) 
           || (root->left == nullptr && root->right == nullptr)))
        {
            TreeNode* current = root;
            TreeNode* left = current->left;
            TreeNode* right = current->right;
            current->left = nullptr;
            current->right = nullptr;
            
            current->right = preOrder(left);
            
            TreeNode* iterator = current;
            while(iterator->right != nullptr)
            {
                iterator = iterator->right;
            }
            
            iterator->right = preOrder(right);
        }
        return root;
    }
    
    
    void flatten(TreeNode* root) {
        preOrder(root);
    }
};