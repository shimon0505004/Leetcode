/*
	https://leetcode.com/problems/rotate-list/
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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        int listSize=0;
        ListNode* previousNode=nullptr;
        for(ListNode* currentNode=head;currentNode!=nullptr;currentNode=currentNode->next)
        {
            previousNode = currentNode;
            listSize++;
        }
        
        ListNode* currentNode=head;
        if(previousNode!=nullptr)
        {

            previousNode->next=head;
            
            for(int index=0;index<listSize-(k%listSize);index++)
            {            
                currentNode=currentNode->next;
                previousNode=previousNode->next;
            }
            
            previousNode->next=nullptr;
            
        }
        
        return currentNode;
        
    }
};