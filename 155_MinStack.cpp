/*
	https://leetcode.com/problems/min-stack/description/
	shimon0505004
*/

#include<cassert>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        stack.clear();
        minTrackerStack.clear();
    }
    
    void push(int x) {
        if(stack.size()==0)
        {
            stack.push_back(x);
            minTrackerStack.push_back(x);
        }
        else
        {
            stack.push_back(x);
            if(minTrackerStack.back()>=x)
                minTrackerStack.push_back(x);
        }
    }
    
    void pop() {
        int poppedVal = stack.back();
        stack.pop_back();
        if(poppedVal==minTrackerStack.back())
            minTrackerStack.pop_back();
    }
    
    int top() {
        return  stack.back();      
    }
    
    int getMin() {
        return minTrackerStack.back();   
    }
    
private:
    vector<int> stack;
    vector<int> minTrackerStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */