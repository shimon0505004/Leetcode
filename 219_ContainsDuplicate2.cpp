/*
	https://leetcode.com/problems/contains-duplicate-ii/
	shimon0505004
*/

#include<unordered_set>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_set<int> myset;
        
        bool containsDuplicate = false;
        for(int index=0;index<=k && index<nums.size(); index++)
        {
            auto pair = myset.insert(nums.at(index));
            if(!pair.second)
                containsDuplicate = true;
        }

        if(!containsDuplicate)
        {
            for(int index=k+1;index<nums.size();index++)
            {
                int indexOfItemToRemove = index - k-1;
                myset.erase(nums.at(indexOfItemToRemove));
                auto pair = myset.insert(nums.at(index));
                if(!pair.second)
                {
                    containsDuplicate = true;
                    break;            
                }
            }
        }
        
        return containsDuplicate;
    }
};