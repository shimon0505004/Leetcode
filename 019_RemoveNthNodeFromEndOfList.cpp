/*
	https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curPtr = head;
        ListNode* prevPtr = NULL;
        ListNode* endPtr = curPtr;
        for(int i=1;i<=n;i++)
        {
            endPtr = endPtr->next;
        }
        
        while(endPtr!=NULL)
        {
            prevPtr = curPtr;
            curPtr = curPtr->next;
            endPtr = endPtr->next;
        }
        
        if(prevPtr==NULL)
            head = head->next;
        else
            prevPtr->next = curPtr->next;
        
        return head;
    }
};