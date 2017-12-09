/*
	https://leetcode.com/problems/insertion-sort-list/
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* finalList=nullptr;
        while(head!=nullptr)
        {
            ListNode* temp = head;
            head=head->next;
            temp->next=nullptr;
            finalList = insertNodeInAlreadySortedList(finalList, temp);
        }
        
        return finalList;
    }
    
    ListNode* insertNodeInAlreadySortedList(ListNode* headOfAlreadySortedList, ListNode* newNode)
    {
        ListNode* finalHead = headOfAlreadySortedList;
        if(finalHead==nullptr)
        {
            finalHead = newNode;
            if(newNode!=nullptr)
            {
                newNode=newNode->next;
                finalHead->next=nullptr;                
            }
        }
        else
        {
            if(newNode != nullptr)
            {
                if(newNode->val<finalHead->val)
                {
                    ListNode* temp = newNode;
                    newNode=newNode->next;
                    temp->next=finalHead;
                    finalHead = temp;
                }
                else
                {
                    ListNode* prevNode = finalHead;
                    ListNode* curNode = finalHead->next;
                    while(curNode!=nullptr)
                    {
                        if(newNode->val<curNode->val)
                        {
                            ListNode* temp = newNode;
                            newNode=newNode->next;
                            temp->next=curNode;
                            prevNode->next=temp;
                            break;
                        }
                        curNode = curNode->next;
                        prevNode = prevNode->next;
                    }
                    
                    if(curNode==nullptr)
                    {
                        ListNode* temp = newNode;
                        newNode=newNode->next;
                        prevNode->next=temp;
                        temp->next=nullptr;
                    }
                }
                
            }
        }
        
        return finalHead;
    }
};