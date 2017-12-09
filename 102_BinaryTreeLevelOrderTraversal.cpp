/*
	https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    typedef std::pair<TreeNode*, int> bfsNode;
    
    vector<vector<int>> levelOrder(TreeNode* root) {
       int index=0;
        std::queue<bfsNode> bfsQueue;
        vector<vector<int>> result;

        if(root!=nullptr)
        {
            bfsQueue.push(std::make_pair(root,index));

            while(!bfsQueue.empty())
            {
                bfsNode node = bfsQueue.front();
                bfsQueue.pop();
                if(node.second<result.size())
                    result.at(node.second).push_back(node.first->val);
                else
                    result.push_back({node.first->val});

                if(node.first->left!=nullptr)
                    bfsQueue.push(std::make_pair(node.first->left,node.second+1));

                if(node.first->right!=nullptr)
                    bfsQueue.push(std::make_pair(node.first->right,node.second+1));
            }
            
        }

        
        return result;
        
    }
};