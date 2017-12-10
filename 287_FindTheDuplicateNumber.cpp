/*
	https://leetcode.com/problems/find-the-duplicate-number/description/
	shimon0505004
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::unordered_set<int> keys;
        keys.reserve(nums.size()-1);
        int result = 0;
        for(const auto& num: nums){
            if(keys.count(num)==0){
                keys.insert(num);
            }else
            {
                result = num;
                break;
            }
        }
        
        return result;
    }
};