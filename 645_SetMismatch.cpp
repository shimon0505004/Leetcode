/*
	shimon0505004
	645. Set Mismatch
	https://leetcode.com/problems/set-mismatch/
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        std::unordered_set<int> keys;
        vector<int> result;
        for(const int& num: nums){
            if(keys.count(num) == 0)
                keys.insert(num);
            else
                result.push_back(num);
        }
        
        for(int missingNumber=1; missingNumber <= nums.size() ; missingNumber++){
            if(keys.count(missingNumber) == 0)
            {
                result.push_back(missingNumber);
                break;
            }
        }
        
        return result;
    }
};