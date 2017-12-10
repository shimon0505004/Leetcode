/*
	https://leetcode.com/problems/two-sum/
	shimon0505004
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> returnVal = {-1,-1};
        //Check every pair
        for(int firstIndex=0;firstIndex<nums.size()-1;firstIndex++)
        {
            for(int secondIndex=firstIndex+1;secondIndex<nums.size();secondIndex++)
            {
                if(nums[firstIndex]+nums[secondIndex]==target)
                {
                    returnVal[0] = firstIndex;
                    returnVal[1] = secondIndex;
                    break;
                }
            }
        }
        return returnVal;
    }
};