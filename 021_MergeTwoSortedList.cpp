/*
	https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto L1Iter = l1;
        auto L2Iter = l2;
        ListNode* dummy = new ListNode(-1);
        auto L3Iter=dummy;
        while(L1Iter && L2Iter)
        {
            if(L1Iter->val<L2Iter->val)
            {
                L3Iter->next=L1Iter;
                L3Iter=L1Iter;
                L1Iter=L1Iter->next;
                L3Iter->next=nullptr;
            }else
            {
                L3Iter->next=L2Iter;
                L3Iter=L2Iter;
                L2Iter=L2Iter->next;
                L3Iter->next=nullptr;
            }
        }
        
        if(L1Iter)
            L3Iter->next=L1Iter;
        else
            L3Iter->next=L2Iter;
        
        auto newHead = dummy->next;
        delete(dummy);
        return newHead;
    }
};