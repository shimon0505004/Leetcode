/*
	shimon0505004
	283. Move Zeroes
	https://leetcode.com/problems/move-zeroes/
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int firstZeroIndex = -1;
        int firstNonZeroIndex = -1;
        for(int index = 0 ; index < nums.size() - 1; index++)
        {
            if(nums[index] == 0)
            {
                for(int nextIndex = index + 1; nextIndex < nums.size(); nextIndex++)
                {
                    if(nums[nextIndex] != 0)
                    {
                        std::swap(nums[index], nums[nextIndex]);
                        break;                        
                    }
                }
            }
        }
    }
};