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
    ListNode* reverseListIterative(ListNode* head);
    ListNode* reverseListRecursive(ListNode* head);
    
    ListNode* reverseList(ListNode* head) {
        return reverseListIterative(head);
    }
    
};


ListNode* Solution::reverseListIterative(ListNode* head)
{
        //To solve iteratively, keep track of previous node.
        ListNode* previous = nullptr;
        ListNode* current = head;
        while(current!=nullptr)
        {
            ListNode* temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }        
        return previous;    
}



ListNode* Solution::reverseListRecursive(ListNode* head)
{
    if(head==nullptr || head->next == nullptr)
        return head;
    
    ListNode* p = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}

