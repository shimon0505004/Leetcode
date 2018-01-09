/*
	shimon0505004
	129. Sum Root to Leaf Numbers
	https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
    using BFSQueue = std::queue<std::pair<TreeNode*,int>>;
    using DFSStack = std::stack<std::pair<TreeNode*,int>>;
    
    int sumNumbers(TreeNode* root) {
        //Running both BFS and DFS should work.
        
        int total = 0;
        int parentSum = 0;
        
        BFSQueue toVisit;
        
        if(root!=nullptr)
            toVisit.push(std::make_pair(root,parentSum));
        
        while(!toVisit.empty())
        {
            std::pair<TreeNode*,int> nodeAndParentSum = toVisit.front();
            toVisit.pop();
            
            int currentNodeSum = ((nodeAndParentSum.second) * 10) +  nodeAndParentSum.first->val;
            if(nodeAndParentSum.first->left == nullptr && nodeAndParentSum.first->right == nullptr)
                total += currentNodeSum;
            else
            {
                if(nodeAndParentSum.first->left != nullptr)
                    toVisit.push(std::make_pair(nodeAndParentSum.first->left,currentNodeSum));
                
                if(nodeAndParentSum.first->right != nullptr)
                    toVisit.push(std::make_pair(nodeAndParentSum.first->right,currentNodeSum));                
            }
        }
        
        return total;
    }
};