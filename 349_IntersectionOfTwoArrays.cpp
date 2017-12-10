/*
	https://leetcode.com/problems/intersection-of-two-arrays/
	shimon0505004
*/

#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int,int> map_1;
        std::unordered_map<int,int> map_2;
        
        for(const auto& num:nums1)
        {
            auto temp = map_1.count(num);
            if(temp==0)
            {
                map_1.emplace(num,1);
            }
        }
        
        for(const auto& num:nums2)
        {
            auto temp = map_2.count(num);
            if(temp==0)
            {
                map_2.emplace(num,1);
            }
        }
        
        std::unordered_set<int> intersection;
        for(const auto& elem:map_1)
        {
            auto key = elem.first;
            if(map_1.count(key)==map_2.count(key))
                intersection.insert(key);
        }
        
        for(const auto& elem:map_2)
        {
            auto key = elem.first;
            if(map_1.count(key)==map_2.count(key))
                intersection.insert(key);
        }
        
        std::vector<int> final_result;
        for(const auto& elem: intersection)
        {
            final_result.push_back(elem);
        }
        
        return final_result;

    }
};