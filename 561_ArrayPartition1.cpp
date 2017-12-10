/*
	https://leetcode.com/problems/array-partition-i/
	shimon0505004
*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int index=0;index<nums.size();index+=2)
            sum += nums.at(index);

        return sum;
    }
};