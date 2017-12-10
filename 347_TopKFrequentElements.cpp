/*
	https://leetcode.com/problems/top-k-frequent-elements/
	shimon0505004
*/

#include <map>
#include <queue>
#include <vector>
#include <iostream>

using std::map;
using std::priority_queue;
using std::cout;
using std::vector;

typedef std::pair<int,int> intPair;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int,int> countMap;
        for(const auto& n:nums)
            countMap[n]++;


        auto lambdaFunc = [](const intPair& left, const intPair& right) ->bool
        {
                return left.second<right.second;
        };
        
        priority_queue<intPair,vector<intPair>,decltype(lambdaFunc)> maxHeap(lambdaFunc);
        for(const auto& m:countMap)
            maxHeap.push(m);

        vector<int> result;
        for(int count=0;count<k&& !maxHeap.empty();count++)
        {
            auto elem = maxHeap.top();
            maxHeap.pop();
            result.push_back(elem.first);
        }

        return result;
    }
};