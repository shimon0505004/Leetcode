/*
	shimon0505004
	671. Second Minimum Node In a Binary Tree
	https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
*/
	shimon0505004
	671. Second Minimum Node In a Binary Tree
	https://leetcode.com/problems/second-minimum-node-in-a-binary-tree
*/

/*
	Approach 1.
		Minimum value node will be the root. 
		Traverse the complete tree to find the second minimum root using BFS/DFS?
	
	Approach 2.
		use recursion. O(n)
	
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
    
    int findSecondMinimumValueUsingBFS (TreeNode* root)
    {
        if(root != nullptr)
        {
            int smallestValue = root->val;
            int secondSmallestValue = INT_MAX;
            
            std::queue<TreeNode*> toVisit;
            toVisit.push(root);
            while(!toVisit.empty())
            {
                TreeNode* visited = toVisit.front();
                toVisit.pop();
                if(visited->val > smallestValue && visited->val < secondSmallestValue)
                    secondSmallestValue = visited->val;
                
                if(visited->left != nullptr)
                    toVisit.push(visited->left);
                
                if(visited->right != nullptr)                
                    toVisit.push(visited->right);
            }
            
            if(secondSmallestValue != INT_MAX)
                return secondSmallestValue;
        }   
        return  -1;
    }
    
    
    int findSecondMinimumValue(TreeNode* root, int min)
    {
        if(root==nullptr) return  -1;
        else if(root->val > min) return root->val;
        
        int leftMin = findSecondMinimumValue(root->left,min);
        int rightMin = findSecondMinimumValue(root->right,min);
        return (leftMin == -1 || rightMin == -1) ? std::max(leftMin,rightMin) : std::min(leftMin,rightMin);
    }
    
    int findSecondMinimumValueUsingRecursion(TreeNode* root)
    {
        if(root!=nullptr)
        {
            return findSecondMinimumValue(root, root->val);
        }
        return -1;
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        return findSecondMinimumValueUsingRecursion(root);     
    }
};