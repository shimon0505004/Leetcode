/*
	shimon0505004
	24. Swap Nodes in Pairs
	https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr)
            return head;
        
        ListNode* newHead = head->next;
        ListNode* current = head;
        ListNode* adjacentToCurrent = nullptr;
        ListNode* next = nullptr;
        ListNode* previous = nullptr;
        
        if(newHead == nullptr)
            return head;
        
        while(current != nullptr && current->next!= nullptr)
        {
            adjacentToCurrent = current->next;
            next = current->next->next;
            if(previous != nullptr)
                previous->next = adjacentToCurrent;
            
            current->next = next;
            adjacentToCurrent->next = current;
            previous = current;
            current = next;
        }
        
        return newHead;
    }
};