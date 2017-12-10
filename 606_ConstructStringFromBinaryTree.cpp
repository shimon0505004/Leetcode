/*
	https://leetcode.com/problems/construct-string-from-binary-tree/description/
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
    string tree2str(TreeNode* t) {
        string s = originalTree2str(t);
        string result = s.substr(1,s.length()-2);
        return result;
    }
    
    
    string originalTree2str(TreeNode* t)
    {
        if(t!=nullptr)
        {
            if(t->left==nullptr && t->right==nullptr)
                return "("+std::to_string(t->val)+")";
            else
            {
                std::string result = "(" + std::to_string(t->val);
                if(t->right!=nullptr)
                    result += originalTree2str(t->left) + originalTree2str(t->right);
                else
                {
                    if(t->left!=nullptr)
                        result += originalTree2str(t->left);                    
                }
                
                result += ')';
                return result;
                
            }
        }
        
        return "()";

    }
};