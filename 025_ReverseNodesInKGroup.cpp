/*
	shimon0505004
	025. Reverse Nodes in k-Group
	https://leetcode.com/problems/reverse-nodes-in-k-group
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
    ListNode* reverse(ListNode* first, ListNode* last)
    {
        ListNode* prev = last;
        while(first != last)
        {
            ListNode* temp = first->next;
            first->next = prev;
            prev = first;
            first = temp;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* last = head;
        for(int subListSize=0; subListSize<k; subListSize++)
        {
            if(last == nullptr)
                return head;
            last = last->next;
        }
        
        ListNode* new_head = reverse(head,last);
        head->next = reverseKGroup(last,k);
        return new_head;
    }
};