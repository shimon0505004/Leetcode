/*
	https://leetcode.com/problems/kth-largest-element-in-an-array/
	shimon0505004
*/

#include <queue>

using std::priority_queue;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        for(auto num:nums)
        {
            maxHeap.push(num);
            cout<<num;            
        }

        int kThLargest ;
        for(int count=0;count<k && !maxHeap.empty() ; count++)
        {
            kThLargest = maxHeap.top();
            maxHeap.pop();
        }
        
        return kThLargest;
    }
};