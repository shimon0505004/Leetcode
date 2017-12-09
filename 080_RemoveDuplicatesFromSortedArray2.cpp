/*
	https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
	shimon0505004
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::map<int,vector<int>> countMap;
        std::queue<int> numbersToRemove;
        for(const auto& number : nums)
        {
            if(countMap.count(number)==0)
                countMap.insert(std::pair<int,vector<int>>(number,{number}));
            else
            {
                if(countMap.at(number).size()<2)
                   countMap.at(number).push_back(number);
            }
        }
        
        nums.clear();
        for(const auto& mapElement: countMap)
        {
            nums.insert(nums.end(),mapElement.second.begin(),mapElement.second.end());
        }
        
        return nums.size();
    }
};