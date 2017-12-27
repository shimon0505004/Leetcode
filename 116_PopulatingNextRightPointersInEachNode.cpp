/*
	shimon0505004
	https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        using NodeLevelPair = std::pair<TreeLinkNode*, int>;
        using NodeLevelQueue = std::queue<NodeLevelPair>;
        
        NodeLevelQueue bfsQueue;
        
        if(root!=nullptr)
            bfsQueue.push(std::make_pair(root,1));
        
        std::vector<NodeLevelPair> NodeLevelPairChain;
     
        while(!bfsQueue.empty())
        {            
            NodeLevelPair pair = bfsQueue.front();
            NodeLevelPairChain.push_back(pair);
            bfsQueue.pop();
            
            if(pair.first->left!=nullptr)
                bfsQueue.push(std::make_pair(pair.first->left,pair.second+1));
            
           if(pair.first->right!=nullptr)
                bfsQueue.push(std::make_pair(pair.first->right,pair.second+1));
        
        }
        
        for(int index=0; index<NodeLevelPairChain.size(); index++)
        {
            if(index+1<NodeLevelPairChain.size())
            {
                if(NodeLevelPairChain[index].second == NodeLevelPairChain[index+1].second)
                {
                    NodeLevelPairChain[index].first->next = NodeLevelPairChain[index+1].first;
                }
            }
        }
    }
};