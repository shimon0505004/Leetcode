/*
	https://leetcode.com/problems/rotate-array/
	shimon0505004
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for(int count=1;count<=k;count++)
        {
            auto iter = nums.end()-1;
            int val = *iter;
            nums.insert(nums.begin(),val);
            nums.pop_back();
        }
    }
};