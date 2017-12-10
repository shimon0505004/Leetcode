/*
	https://leetcode.com/problems/maximum-subarray/
	shimon0505004
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        //Kadane's algorithm
        int currentMax = nums.at(0);
        int maxSum = nums.at(0);
        for(int index=1;index<nums.size();index++)
        {
            currentMax = max(nums.at(index),currentMax+nums.at(index));
            maxSum = max(currentMax, maxSum);
        }
        
        return maxSum;
    }
};