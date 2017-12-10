/*
	https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
	shimon0505004
*/

#include <queue>
#include <functional>
#include <vector>
#include <utility>

using std::priority_queue;
using std::vector;

typedef std::pair<int,int> Pair;
typedef std::pair<int,Pair> HeapNode;


class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        auto lambdaGreaterF = [](const HeapNode& left, const HeapNode& right){
              return left.first > right.first;
        };
        
        priority_queue<HeapNode,vector<HeapNode>,decltype(lambdaGreaterF)> minHeap(lambdaGreaterF);
        
        for(auto num1:nums1)
            for(auto num2:nums2)
                minHeap.push(std::make_pair(num1+num2,std::make_pair(num1,num2)));


        vector<pair<int, int>> result;
        result.clear();
        for(int count=0;count<k && !minHeap.empty() ;count++)
        {
            auto n = minHeap.top();
            minHeap.pop();
            result.push_back(n.second);
        }
        
        return result;
    }
};