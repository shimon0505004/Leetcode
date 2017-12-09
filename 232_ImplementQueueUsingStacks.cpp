/*
	https://leetcode.com/problems/implement-queue-using-stacks/description/
	shimon0505004
*/


class MyQueue {
private:
    std::stack<int> storageSpace;

public:
    /** Initialize your data structure here. */
    MyQueue() {
        storageSpace = std::stack<int>();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        std::stack<int> tempStack;
        while(!storageSpace.empty())
        {
            tempStack.push(storageSpace.top());
            storageSpace.pop();            
        }
        storageSpace.push(x);
        while(!tempStack.empty())
        {
            storageSpace.push(tempStack.top());
            tempStack.pop();                        
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int retVal = storageSpace.top();
        storageSpace.pop();
        return retVal;
    }
    
    /** Get the front element. */
    int peek() {
        return storageSpace.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return storageSpace.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */