/*
	shimon0505004
	725. Split Linked List in Parts
	https://leetcode.com/problems/split-linked-list-in-parts/
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> result (k,nullptr);
        vector<int> maxSize(k,0);
        
        int listLength = 0;
        //Run first pass to count number of elements in the list.
        for(ListNode* cur=root;cur!=nullptr;cur = cur->next, ++listLength)
           maxSize[listLength%k]++;     
        
        int currentIndex = 0;
        int currentSizeAtIndex = 0;
        result[currentIndex] = root;
        ListNode* prev=nullptr;

        for(ListNode* cur=root;cur!=nullptr;cur = cur->next)
        {
            if(currentSizeAtIndex == maxSize[currentIndex])
            {                    
                currentIndex++;
                currentSizeAtIndex = 0;
                
                result[currentIndex]= cur;
                
                if(prev != nullptr)
                    prev->next= nullptr;
            }
            currentSizeAtIndex++;
            prev = cur;
        }
        
        return result;
    }
};