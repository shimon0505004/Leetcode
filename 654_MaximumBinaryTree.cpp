/*
	shimon0505004
	654. Maximum Binary Tree
	https://leetcode.com/problems/maximum-binary-tree/
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0)
            return nullptr;
        else if(nums.size()==1)
            return new TreeNode(nums.at(0));
        else
        {
            std::vector<int>::iterator max_element_iterator = std::max_element(nums.begin(), nums.end());
            TreeNode* root = new TreeNode((*max_element_iterator));
            
            vector<int> rightHalf(max_element_iterator+1,nums.end());
            nums.erase(max_element_iterator,nums.end());
            
            
            
            root->left = constructMaximumBinaryTree(nums);
            root->right = constructMaximumBinaryTree(rightHalf);
            
            return root;
        }
    }
};