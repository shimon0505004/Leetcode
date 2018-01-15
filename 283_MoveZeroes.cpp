/*
	shimon0505004
	283. Move Zeroes
	https://leetcode.com/problems/move-zeroes/
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int currentFillIndex = 0;
        int currentIndex = 0;
        
        while(currentIndex < nums.size())
        {
            if(nums[currentIndex] != 0)
            {
                nums[currentFillIndex] = nums[currentIndex];
                currentFillIndex++;
            }
            currentIndex++;
        }
        
        while(currentFillIndex < nums.size())
        {
            nums[currentFillIndex] = 0;
            currentFillIndex++;
        }
    }
};