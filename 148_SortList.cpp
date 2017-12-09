/*
	https://leetcode.com/problems/sort-list/
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
    ListNode* sortList(ListNode* head) {
        ListNode* returnPtr = nullptr;
        
        if(head!=nullptr)
        {
            ListNode* left = head;
            ListNode* right = splitList(head);
            ListNode* leftSort = nullptr;
            ListNode* rightSort = nullptr;
            
           
            if(left==nullptr || left->next==nullptr)
                leftSort = left;
            else
                leftSort = sortList(left);
            
            if(right==nullptr || right->next==nullptr)
                rightSort = right;
            else
                rightSort = sortList(right);
            
            returnPtr = merge(leftSort,rightSort);
        }
        
        return returnPtr;
    }
    
    
    ListNode* splitList(ListNode* head)
    {
        if(head!=nullptr && head->next!=nullptr)
        {
            ListNode* prevPtr = head;
            ListNode* splitPtr = head->next;
            ListNode* fastPtr = splitPtr->next;
            while(fastPtr!=nullptr)
            {
                fastPtr=fastPtr->next;
                splitPtr=splitPtr->next;
                prevPtr=prevPtr->next;

                if(fastPtr==nullptr)
                    break;
                else
                    fastPtr=fastPtr->next;

            }
            
            prevPtr->next = nullptr;
            return splitPtr;
        }
        
        return nullptr;
    }
    
    
    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode* curPtr = nullptr;
        ListNode* head = curPtr;
        if(left!=nullptr && right!=nullptr)
        {
            if(left->val<right->val)
            {
                curPtr=left;
                left=left->next;
            }
            else
            {
                curPtr=right;
                right=right->next;            
            }            
            
            curPtr->next = nullptr;
            head = curPtr;

            while(left!=nullptr && right!=nullptr)
            {
                if(left->val<right->val)        
                {
                    curPtr->next=left;
                    left=left->next;
                }
                else
                {
                    curPtr->next=right;
                    right=right->next;
                }
                curPtr=curPtr->next;
                curPtr->next=nullptr;  
            }

        }

        
        if(left==nullptr)
        {
            if(curPtr==nullptr)
                curPtr = right;
            else
                curPtr->next = right;
        }
        else
        {
            if(curPtr==nullptr)
                curPtr = left;
            else
                curPtr->next = left;            
        }

        if(head==nullptr)
            head = curPtr;
            
        return head;
    }
};