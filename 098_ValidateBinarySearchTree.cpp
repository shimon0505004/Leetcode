/*
	shimon0505004
	98. Validate Binary Search Tree
	https://leetcode.com/problems/validate-binary-search-tree/
*/

/*
	To check the validity of a BST,
	1) use recursion. 
	2) A tree with only one node is a BST.
	3) If root has left and right subtree,
		a) compare root value with maximum value in the left subtree.
			i) root should be greater than maximum value in the left subtree.
		b) compare root value with minimum value in the right subtree.
			i) root should be smaller than minimum value in the right subtree.
		c) check if left and right subtrees themselves are BST.
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
    TreeNode* minSubTreeNode(TreeNode* root)
    {
        TreeNode* minNode = root;
        while(minNode->left !=nullptr)
        {
            minNode = minNode->left;
        }
        return minNode;
    } 

    TreeNode* maxSubTreeNode(TreeNode* root)
    {
        TreeNode* maxNode = root;
        while(maxNode->right !=nullptr)
        {
            maxNode = maxNode->right;
        }
        return maxNode;
    } 
    
    
    bool isValidBST(TreeNode* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr))
            return true;
        
        if(root->left != nullptr && root->val <= maxSubTreeNode(root->left)->val)
            return false;
        
        if(root->right != nullptr && root->val >= minSubTreeNode(root->right)->val)
            return false;
        
        return (isValidBST(root->left) && isValidBST(root->right));
    }
};