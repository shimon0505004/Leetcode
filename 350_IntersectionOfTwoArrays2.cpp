/*
	https://leetcode.com/problems/intersection-of-two-arrays-ii/
	shimon0505004
*/

#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int,int> map1;
        std::unordered_map<int,int> map2;
        
        for(const auto& num:nums1)
        {
            int doesExist = map1.count(num);
            if(doesExist==0)
            {
                map1.emplace(num,1);
            }
            else
            {
                map1[num] = map1[num]+1;
            }
            
            cout << num<<" "<<map1[num]<<endl;
        }
        
        for(const auto& num:nums2)
        {
            int doesExist = map2.count(num);
            if(doesExist==0)
            {
                map2.emplace(num,1);
            }
            else
            {
                map2[num] = map2[num]+1;
            }
            
            cout << num<<" "<<map2[num]<<endl;

        }
        
        std::unordered_map<int,int> map3;
        
        for(const auto& pair:map1)
        {
            int key = pair.first;
            if(map1.count(key)==map2.count(key))
            {
                int min = map1[key] < map2[key] ? map1[key] : map2[key];
                map3.emplace(key,min);
            }
        }
        
        for(const auto& pair:map2)
        {
            int key = pair.first;
            if(map1.count(key)==map2.count(key))
            {
                int min = map1[key] < map2[key] ? map1[key] : map2[key];
                map3.emplace(key,min);
            }
        }
        
        vector<int> result;
        for(const auto& pair:map3)
        {
            int key = pair.first;
            int count = pair.second;
            for(int i=0;i<count;i++)
            {
                result.push_back(key);
            }
        }
        
        return result;
    }
};