/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    
    RandomListNode *copyRandomListUsingHashTable(RandomListNode *head);
    RandomListNode *copyRandomListWithoutHashTable(RandomListNode *head);
	
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        return copyRandomListUsingHashTable(head);
    }
    
};


RandomListNode* Solution::copyRandomListUsingHashTable(RandomListNode *head)
{
        
        //Intuitive solution. Using a hash table to map node from source to destination.
        
        /*
            First, copy the singly link list.
        */
        RandomListNode* destHead = nullptr;
        RandomListNode* destCurrent = nullptr;
        RandomListNode* sourceCurrent = head;
        
        using ListMap = std::unordered_map<RandomListNode*, RandomListNode*>;
        ListMap map = ListMap();
        
        while(sourceCurrent != nullptr)
        {
            if(destCurrent==nullptr)
            {
                destCurrent = new RandomListNode(sourceCurrent->label);
                destHead = destCurrent;
            }
            else
            {
                destCurrent->next = new RandomListNode(sourceCurrent->label);
                destCurrent = destCurrent->next;
            }
            map.emplace(std::make_pair(sourceCurrent,destCurrent));
            sourceCurrent = sourceCurrent->next;
        }
        
        
        
        /*
            Second, create the random pointers in deep-copied list
        */
        sourceCurrent = head;
        while(sourceCurrent != nullptr)
        {
            RandomListNode* sourceRandom = sourceCurrent->random;
            RandomListNode* destRandom = (sourceRandom != nullptr) ? map.at(sourceRandom) : nullptr;
            map.at(sourceCurrent)->random = destRandom;
            
            sourceCurrent = sourceCurrent->next;
        }
        
        return destHead;
}
	
	
	
RandomListNode* Solution::copyRandomListWithoutHashTable(RandomListNode *head)
{
    //Step 1: Create Copied Nodes and insert them in the original List.
    RandomListNode* next;
    RandomListNode* current = head;
    
    while(current!=nullptr)
    {
        next = current -> next;
        RandomListNode* newNode = new RandomListNode(current->label);
        current -> next = newNode;
        newNode -> next = next;
        
        current = next;
    }

    //Step 2: Copy randoms from source to new nodes.
    current = head;
    while(current!=nullptr)
    {
        current->next->random = ((current->random != nullptr) ? current->random->next : nullptr);        
        current = current->next->next;
    }
    
    
    //Step 3: Splice the list;
    current = head;
    RandomListNode* finalResultHead = new RandomListNode(0);  //dummy head
    RandomListNode* finalResultCurrent = finalResultHead;  //dummy head

    RandomListNode* copy;
    
    while(current!=nullptr)
    {
        next = current->next->next;
        
        copy = current->next;
        finalResultCurrent->next = copy;
        finalResultCurrent = copy;
        
        current->next = next;
        current = current->next;
    }
    
    RandomListNode* nodeToDelete = finalResultHead;
    finalResultHead = finalResultHead->next;
    delete(nodeToDelete);
    
    return finalResultHead;
    
}