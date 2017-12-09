/*
	https://leetcode.com/problems/path-sum-ii/
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        if(root!=nullptr)
        {
            if(root->left==nullptr && root->right==nullptr)
            {
                if(root->val==sum)
                    paths.push_back({root->val});
            }
            else 
            {
                int newSum =  (sum - root->val);
                vector<vector<int>> pathsOnLeft = pathSum(root->left, newSum);
                vector<vector<int>> pathsOnRight = pathSum(root->right, newSum);
                if(!pathsOnLeft.empty())
                {
                    for(vector<int>& pathOnLeft :  pathsOnLeft)
                    {
                        if(!pathOnLeft.empty())
                            pathOnLeft.insert(pathOnLeft.begin(),root->val);
                    }
                }
                
                if(!pathsOnRight.empty())
                {
                    for(vector<int>& pathOnRight :  pathsOnRight)
                    {
                        if(!pathOnRight.empty())
                            pathOnRight.insert(pathOnRight.begin(),root->val);
                    }
                }
                
                if(!pathsOnLeft.empty())
                    paths.insert(paths.end(),pathsOnLeft.begin(),pathsOnLeft.end());
                
                if(!pathsOnRight.empty())
                    paths.insert(paths.end(),pathsOnRight.begin(),pathsOnRight.end());
            }
        }
        return paths;
    }
};