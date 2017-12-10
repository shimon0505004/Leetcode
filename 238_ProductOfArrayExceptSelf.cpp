/*
	https://leetcode.com/problems/product-of-array-except-self/
	shimon0505004
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        res[0] = 1;
        for(int index=1;index<nums.size();index++)
        {
            res[index] = res[index-1] * nums[index-1];
        }
        
        int revMult = 1;
        for(int index=nums.size()-2;index>=0;index--)
        {
            revMult = revMult * nums[index+1];
            res[index] = res[index] * revMult;
        }
        
        return res;
    }
};