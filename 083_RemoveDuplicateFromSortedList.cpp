/*
	https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur!=nullptr)
        {
            if(prev!= nullptr && prev->val==cur->val)
            {
                ListNode* nodeToDelete = cur;
                cur=cur->next;
                prev->next = cur;
                delete nodeToDelete;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};