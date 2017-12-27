/*
	shimon0505004
	https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //Use level order traversal
        using NodeLevelPair = std::pair<TreeNode*,int>;
        using BFS_Queue = std::queue<NodeLevelPair>;
        
        BFS_Queue levelOrderQ;
        
        bool forward = false;
        
        if(root != nullptr)
        {
            levelOrderQ.push(std::make_pair(root,1));
            forward = !forward;
        }
        
        vector<vector<int>> result;
        vector<int> current;
        int currentLevel = 1;
        
        while(!levelOrderQ.empty())
        {
            NodeLevelPair pair = levelOrderQ.front();
            levelOrderQ.pop();
            
            if(pair.second > currentLevel)
            {
                result.push_back(current);
                currentLevel = pair.second;
                current.clear();
                forward = !forward;
            }
            
            if(forward)
                current.push_back(pair.first->val);
            else
                current.insert(current.begin(), pair.first->val);
            
            if(pair.first->left != nullptr)
                levelOrderQ.push(std::make_pair(pair.first->left,pair.second + 1));

            if(pair.first->right != nullptr)
                levelOrderQ.push(std::make_pair(pair.first->right,pair.second + 1));                    
        }
                
        if(!current.empty())
            result.push_back(current);

        
        return result;
    }
};