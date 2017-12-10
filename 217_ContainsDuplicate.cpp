/*
	https://leetcode.com/problems/contains-duplicate/
	shimon0505004
*/

#include<unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> numSet;
        bool containsDuplicate = false;
        for(const auto& num:nums)
        {
            auto pair = numSet.insert(num);
            if(!pair.second)
            {
                containsDuplicate = true;
                break;
            }
        }
        return containsDuplicate;
    }
};