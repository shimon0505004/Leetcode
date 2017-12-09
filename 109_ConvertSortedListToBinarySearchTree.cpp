/*
	https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
	shimon0505004
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* convertToBST(vector<ListNode*>& sortedList)
    {
        if(sortedList.empty())
            return nullptr;
        else if(sortedList.size()==1)
            return new TreeNode(sortedList.at(0)->val);
        else
        {
            size_t midIndex = sortedList.size()/2;
            TreeNode* mid = new TreeNode(sortedList.at(midIndex)->val);
            vector<ListNode*> lo = vector<ListNode*>(sortedList.begin(),sortedList.begin()+midIndex);
            vector<ListNode*> hi = vector<ListNode*>(sortedList.begin()+midIndex+1,sortedList.end());
            mid->left = convertToBST(lo);
            mid->right = convertToBST(hi);
            return mid;
        }
    }
    
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<ListNode*> sortedList;
        for(ListNode* iter=head;iter!=nullptr;iter=iter->next)
            sortedList.push_back(iter);
        
        return convertToBST(sortedList);
    }
};