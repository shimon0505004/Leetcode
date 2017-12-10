/*
	https://leetcode.com/problems/remove-linked-list-elements/
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* nodeToDelete = nullptr;
        while(cur!=nullptr)
        {
            if(cur->val==val)
            {
                if(prev==nullptr)   //need to delete head
                {
                    nodeToDelete = head;
                    head = head->next;
                }
                else
                {
                    nodeToDelete = cur;
                    prev->next = nodeToDelete->next;            
                }

            }
            else
            {
                prev = cur;
                nodeToDelete = nullptr;
            }
            
            cur = cur->next;        
            if(nodeToDelete)
               delete nodeToDelete;
            
            nodeToDelete = nullptr;
        }
        
        return head;
    }
};