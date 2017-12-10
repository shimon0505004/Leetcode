/*
	https://leetcode.com/problems/maximum-product-subarray/
	shimon0505004
*/

#include <algorithm>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = 1;
        if(nums.size()>0)
        {
            int curMax = nums.at(0);
            int curMin = nums.at(0);
            maxSoFar = nums.at(0);
            int curMaxPre = nums.at(0);
            int curMinPre = nums.at(0);;
            for(int index =1 ; index < nums.size(); index++)
            {
                curMax = std::max(nums.at(index), std::max(curMaxPre * nums.at(index) , curMinPre*nums.at(index)));
                curMin = std::min(nums.at(index), std::min(curMaxPre * nums.at(index)  , curMinPre*nums.at(index)));
                maxSoFar = std::max(maxSoFar,curMax);
                curMaxPre = curMax;
                curMinPre = curMin;
            }
        }
        
        return maxSoFar;
    }
};