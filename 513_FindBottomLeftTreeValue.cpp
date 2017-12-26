/*
	https://leetcode.com/problems/find-bottom-left-tree-value/
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
    int findBottomLeftValue(TreeNode* root) {
        /*
            The idea is that we will keep track of depth of node and run BFS.
        */
        
        std::queue<std::pair<TreeNode*,int>> bfsQueue;
        if(root != nullptr)
            bfsQueue.push(std::make_pair(root,0));
        
        int currentDepth = -1;
        TreeNode* leftmostInCurrentDepth = nullptr;
        
        while(!bfsQueue.empty())
        {
            std::pair<TreeNode*,int> nodeDepthPair = bfsQueue.front();
            bfsQueue.pop();
            if(nodeDepthPair.second > currentDepth)
            {
                leftmostInCurrentDepth = nodeDepthPair.first;
                currentDepth = nodeDepthPair.second;
            }
            
            if(nodeDepthPair.first->left !=nullptr)
                bfsQueue.push(std::make_pair(nodeDepthPair.first->left,nodeDepthPair.second+1));

            if(nodeDepthPair.first->right !=nullptr)
                bfsQueue.push(std::make_pair(nodeDepthPair.first->right,nodeDepthPair.second+1));
        }
        
        return leftmostInCurrentDepth->val;
    }
};