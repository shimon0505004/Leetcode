/*
	shimon0505004
	285. Inorder Successor in BST
	https://leetcode.com/problems/inorder-successor-in-bst/	
*/

/*
	Technique:
	Save the inorder traversal to a vector.
	traverse the vector.
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
    
    Solution()
    {
        inorderTraversalList.clear();
    }
    
    void inorder(TreeNode* root)
    {
        if(root==nullptr)
            return;
        
        inorder(root->left);
        inorderTraversalList.push_back(root);
        inorder(root->right);
    }
    
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        inorder(root);
        
        TreeNode* result = nullptr;
        for(int index=0 ; index< inorderTraversalList.size(); index++)
        {
            if(p == inorderTraversalList.at(index))
            {
                if(index+1 < inorderTraversalList.size())
                {
                    result = inorderTraversalList.at(index+1);
                    break;                    
                }
            }
        }
        
        inorderTraversalList.clear();
        return result;
    }
    
private:
    vector<TreeNode*> inorderTraversalList;
};