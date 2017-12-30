/*
	shimon0505004
	234. Palindrome Linked List
	https://leetcode.com/problems/palindrome-linked-list/
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
    bool isPalindrome(ListNode* head) {
        std::stack<int> palindromeStack;
        for(auto node = head
            ;node != nullptr
            ;node = node->next){
            palindromeStack.push(node->val);
        }
        
        for(auto node = head
            ;node != nullptr
            ;node = node->next){
            if(node->val != palindromeStack.top())
                return false;
            
            palindromeStack.pop();
        }
        
        return true;
        
    }
};