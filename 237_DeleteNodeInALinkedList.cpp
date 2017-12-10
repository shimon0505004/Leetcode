/*
	https://leetcode.com/problems/delete-node-in-a-linked-list/
	shimon050504
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
    void deleteNode(ListNode* node) {
        if(node->next!=nullptr)
        {
            node->val=(node->next)->val;
            ListNode* nodeToDelete = node->next;
            node->next = (node->next)->next;
            delete nodeToDelete;
        }
    }
};