/*
	https://leetcode.com/problems/find-largest-value-in-each-tree-row/
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
    vector<int> largestValues(TreeNode* root) {
        std::queue<std::pair<TreeNode*,int>> bfsQueue;  //node-depth pair
        
        if(root!=nullptr)
            bfsQueue.push(std::make_pair(root,0));
        
        vector<int> result;
        int currentDepth = -1;
        while(!bfsQueue.empty())
        {
            std::pair<TreeNode*,int> nodeDepthPair = bfsQueue.front();
            bfsQueue.pop();
            if(nodeDepthPair.second>currentDepth)
            {
                result.push_back(nodeDepthPair.first->val);
                currentDepth = nodeDepthPair.second;
            }
            else
            {
                if(nodeDepthPair.first->val > result.back())
                    result.back() = nodeDepthPair.first->val;
            }
            
            if(nodeDepthPair.first->left != nullptr)
                bfsQueue.push(std::make_pair(nodeDepthPair.first->left,(nodeDepthPair.second + 1)));
            
            if(nodeDepthPair.first->right != nullptr)
                bfsQueue.push(std::make_pair(nodeDepthPair.first->right,(nodeDepthPair.second + 1)));            
        }
        
        return result;
    }
};