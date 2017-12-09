/*
	https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = l1;
        ListNode* l1Prev = nullptr;
        ListNode* l2Prev = nullptr;
        while(l1!=nullptr && l2!=nullptr)
        {
            int sum = l1->val + l2->val + carry;
            if(sum>=10)
            {
                carry = 1;
                sum -= 10;
            }
            else
                carry = 0;
            
            l1->val = sum;
            
            l1Prev = l1;
            l2Prev = l2;
                
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(l1==nullptr && l2!=nullptr)
        {
            l1Prev->next = l2;
            l1 = l2;
            l2Prev->next = nullptr;
        }
        
        while(l1!=nullptr)
        {
            int sum = l1->val + carry;
            if(sum>=10)
            {
                carry = 1;
                sum -= 10;
            }
            else
                carry = 0;

            l1->val = sum;
            l1Prev = l1;
            l1 = l1->next;           
        }
        
        
        if(carry>0)
        {
            ListNode* newNode = new ListNode(carry);
            l1Prev->next = newNode;
        }
        return head;
    }
};