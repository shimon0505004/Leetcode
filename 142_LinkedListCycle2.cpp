/*
	shimon0505004
	142. Linked List Cycle II
	https://leetcode.com/problems/linked-list-cycle-ii/
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
    
    ListNode *detectCycle_Using_On_Space(ListNode *head) 
    {
        std::unordered_set<ListNode *> hashTable;
        ListNode* current = head;
        ListNode* cycleLocation = nullptr;
        
        while(current != nullptr)
        {
            if(hashTable.find(current) != hashTable.end())
            {
                cycleLocation = current;
                break;
                
            }    
            hashTable.insert(current);
            current = current->next;
        }
        
        return cycleLocation;
    }

    ListNode *detectCycle_Using_NoExtraSpace(ListNode *head) 
    {
        //Using FastPointer and SlowPointer.
        
        //Step 1. Use a fast pointer and a slow pointer to detect a intersection point.
        //If a intersection point is found, then there is a cycle.
        if(head == nullptr)
            return nullptr;
        
        ListNode* fastPointer = head;
        ListNode* slowPointer = head;
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next;
        if(fastPointer == nullptr)
            return nullptr;
        else
            fastPointer = fastPointer->next;
        
        while(slowPointer != fastPointer && fastPointer != nullptr)
        {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next;
            if(fastPointer == nullptr)
                return nullptr;
            else
                fastPointer = fastPointer->next;
        }
        
        if(fastPointer == nullptr)
            return nullptr;
        
        //Step 2. Intersection Point found at SlowPointer == FastPointer, cycle Exists.
        //Advance slow pointer by 1 from intersection point.
        //take another pointer called cycleStartingPointer that starts from the begining of the list.
        //Increment both pointers by 1.
        //They will intersect at a common point.
        //This common point is the Cycle starting point.
        
        ListNode* cycleStartingPointer = head;
        while(cycleStartingPointer != slowPointer)
        {
            cycleStartingPointer = cycleStartingPointer->next;
            slowPointer = slowPointer->next;
        }
        
        return cycleStartingPointer;
    }

    
    
    ListNode *detectCycle(ListNode *head) {
        return detectCycle_Using_NoExtraSpace(head);
    }
};