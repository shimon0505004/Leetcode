/*
	https://leetcode.com/problems/find-mode-in-binary-search-tree/
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
    vector<int> findMode(TreeNode* root) {
        std::vector<int> sortedVal;
        inorderTraverse(root, sortedVal);
        
        std::unordered_map<int,unsigned int> countMap;
        for(int val:sortedVal)
        {
            if(countMap.count(val)==0)
                countMap.emplace(val,1);
            else
                countMap.at(val)+=1;
        }

        
        
        std::map<int,vector<int>> frequencyMap;
        for(const auto& element:countMap)
        {
            if(frequencyMap.count(element.second)==0)
                frequencyMap.emplace(element.second,vector<int>());
            
            frequencyMap.at(element.second).push_back(element.first);
        }
        
        vector<int> result = vector<int>();
        if(frequencyMap.rbegin()!=frequencyMap.rend())
            result = frequencyMap.rbegin()->second;
        
        return result;
    }
    
    
    void inorderTraverse(TreeNode* node, std::vector<int>& sortedVal)
    {
        if(node!=nullptr)
        {
            inorderTraverse(node->left,sortedVal);
            sortedVal.push_back(node->val);
            inorderTraverse(node->right,sortedVal);
        }
    }
    
};