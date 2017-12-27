/*
	shimon0505004
	https://leetcode.com/problems/add-two-numbers-ii/
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
        std::stack<ListNode*> l1Stack;
        std::stack<ListNode*> l2Stack;
        
        for(ListNode* cur = l1; cur!= nullptr; cur= cur->next)
            l1Stack.push(cur);

       for(ListNode* cur = l2; cur!= nullptr; cur= cur->next)
            l2Stack.push(cur);

        std::stack<ListNode*> resultStack;
        
        int carryOver = 0;
        while(!(carryOver==0 && l1Stack.empty() && l2Stack.empty()))
        {
            int sum = carryOver;
            if(!l1Stack.empty())
            {
                sum += l1Stack.top()->val;
                l1Stack.pop();
            }
            
            if(!l2Stack.empty())
            {
                sum += l2Stack.top()->val;
                l2Stack.pop();
            }
            
            ListNode* newNode = new ListNode(sum%10);
            carryOver = sum/10;
            
            resultStack.push(newNode);
        }
        
        
        ListNode* resultHead = nullptr;
        
        if(!resultStack.empty())
        {
            resultHead = resultStack.top();
            resultStack.pop();
        }

        ListNode* current = resultHead;
        
        while(!resultStack.empty())
        {
            current->next = resultStack.top();
            current = current->next;
            resultStack.pop();
        }

        return resultHead;
    }
};