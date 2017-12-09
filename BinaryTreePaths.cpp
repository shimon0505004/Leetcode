/*
	https://leetcode.com/problems/binary-tree-paths/description/
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(root != nullptr){
            if(root->left == nullptr && root->right==nullptr){
                string node = std::to_string(root->val);
                paths.push_back(node);
            }else{
                vector<string> leftPaths = binaryTreePaths(root->left);
                paths.insert(paths.end(),leftPaths.begin(),leftPaths.end());

                vector<string> rightPaths = binaryTreePaths(root->right);
                paths.insert(paths.end(),rightPaths.begin(),rightPaths.end());

                if(paths.empty())
                {
                    string node = std::to_string(root->val);
                    paths.push_back(node);
                }else
                {
                    for(auto& path:paths){
                        path = std::to_string(root->val).append(std::string("->")).append(path);
                    }
                }
            }            
        }

        return paths;

    }
};