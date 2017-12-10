/*
	https://leetcode.com/problems/single-number/
	shimon0505004
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int num:nums)
            result ^= num;
        
        return result;
    }
};