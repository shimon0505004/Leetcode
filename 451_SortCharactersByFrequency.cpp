/*
	https://leetcode.com/problems/sort-characters-by-frequency/
	shimon0505004
*/

#include <map>
#include <queue>
#include <functional>
#include <iostream>

using std::cout;
using std::string;

typedef std::pair<char,int> chpair;

class Solution {
public:
    string frequencySort(string s) {
        std::map<char,int> countMap;
        countMap.clear();
        for(string::iterator it = s.begin();it!=s.end();it++)
        {
            auto c = *it;
            auto iter = countMap.find(c);
            if(iter!=countMap.end())
                countMap[c]=iter->second+1;
            else
                countMap[c]=1;
        }
        
        auto comp = [](const chpair& left, const chpair& right){
            return left.second < right.second;
        };
        
        std::priority_queue<chpair,std::vector<chpair>,decltype(comp)> maxHeap(comp);
        
        for(auto& m:countMap)
            maxHeap.push(m);
            
        std::string outputStr;
        outputStr.erase();
        while(!maxHeap.empty())
        {
            auto pair = maxHeap.top();
            maxHeap.pop();
            for(int count=0;count<pair.second;count++)
                outputStr.push_back(pair.first);
        }
        return outputStr;
    }
};