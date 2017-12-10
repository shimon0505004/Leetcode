/*
	https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
	shimon0505004
*/

#include <queue>
#include <functional>

using std::priority_queue;
using std::greater;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        
        for(const auto& row:matrix)
            for(const auto& col:row)
                minHeap.push(col);

        int kThSmallest;
        for(int count=0;count<k;count++)
        {
            kThSmallest = minHeap.top();
            minHeap.pop();
        }
        
        return kThSmallest;
    }
};