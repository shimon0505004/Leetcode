/*
	shimon0505004
	23. Merge k Sorted Lists
	https://leetcode.com/problems/merge-k-sorted-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class ListNodeComparator
{
public:
    bool operator()(ListNode* node1, ListNode* node2)
    {
        return node1->val > node2->val;
    }
};


class Solution {
public:
    using PriorityQueue = std::priority_queue<ListNode*, vector<ListNode*>, ListNodeComparator>;
    
    
    ListNode* merge2Lists(ListNode* list1,ListNode* list2)
    {
        if(list1!= nullptr && list2!= nullptr)
        {
            ListNode* dummyHead = new ListNode(0);
            ListNode* current = dummyHead;
            ListNode* currentL1 = list1;
            ListNode* currentL2 = list2;
            
            while(currentL1 != nullptr && currentL2 != nullptr)
            {
                if(currentL1->val < currentL2->val)
                {
                    current->next = currentL1;
                    currentL1 = currentL1->next;
                }
                else
                {
                    current->next = currentL2;
                    currentL2 = currentL2->next;
                }
                current = current->next;
                current->next = nullptr;                
            }

            if(currentL1 == nullptr)
                current->next = currentL2;
            else
                current->next = currentL1;
            
            ListNode* actualHead = dummyHead->next;
            delete(dummyHead);
            return actualHead;
        }
        return (list1 != nullptr) ? list1 : list2;
    }
    
    ListNode* mergeKLists_UsingO1_Space(vector<ListNode*>& lists) {
        //O(1) space
        ListNode* result = nullptr;
        if(lists.size() != 0)
        {
            result = lists.at(0);
            lists.erase(lists.begin());
            while(!lists.empty())
            {
                ListNode* nextList = lists.at(0);
                lists.erase(lists.begin());
                
                result = merge2Lists(result, nextList);
            }
        }
        
        return result;
    }
    
    
    ListNode* mergeKLists_UsingPriorityQueue(vector<ListNode*>& lists) 
	{
		/*
			O(nlogn) time complexity for total n number of node;
			O(n) 	space complexity for total n number of node;
		*/
		
        PriorityQueue queue;
        for(ListNode* list: lists)
        {
            while(list!=nullptr)
            {
                ListNode* current = list;
                list = list->next;
                current->next = nullptr;
                queue.push(current);
            }
        }
        
        ListNode* dummyNode = new ListNode(0);
        ListNode* currentNode = dummyNode;
        
        while(!queue.empty())
        {
            ListNode* next = queue.top();
            queue.pop();
            currentNode->next = next;
            currentNode = currentNode->next;
        }
            
        ListNode* head = dummyNode->next;
        delete(dummyNode);
        return head;
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {        
        return mergeKLists_UsingPriorityQueue(lists);
    }
};