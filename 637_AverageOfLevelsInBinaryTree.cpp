/*
	https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
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
    
    vector<double> averageOfLevels(TreeNode* root) {
        int index=0;
        std::queue<bfsNode> bfsQueue;
        bfsQueue.push(std::make_pair(root,index));
        vector<double> avgArr(1);
        vector<int> levelNodeCounter(avgArr.size());
        while(!bfsQueue.empty())
        {
            bfsNode node = bfsQueue.front();
            bfsQueue.pop();
            if(node.second<avgArr.size())
            {
                avgArr.at(node.second) += node.first->val;
                levelNodeCounter.at(node.second) += 1;
            }
            else
            {
                avgArr.push_back(node.first->val);
                levelNodeCounter.push_back(1);
            }
            if(node.first->left!=nullptr)
                bfsQueue.push(std::make_pair(node.first->left,node.second+1));
            
            if(node.first->right!=nullptr)
                bfsQueue.push(std::make_pair(node.first->right,node.second+1));
        }
        
        for(int index=0;index<avgArr.size();index++)
        {
            avgArr.at(index) /= levelNodeCounter.at(index);
        }
        
        return avgArr;
    }
};