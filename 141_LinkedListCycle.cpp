/*
	https://leetcode.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> visitedNodes;
        ListNode* visitor = head;
        while(visitor!=nullptr)
        {
            if(visitedNodes.count(visitor)==0)
                visitedNodes.insert(visitor);
            else
                break;
            
            visitor=visitor->next;
        }
        
        return (visitor!=nullptr);
    }
};