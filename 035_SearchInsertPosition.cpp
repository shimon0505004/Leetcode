/*
	https://leetcode.com/problems/search-insert-position/
	shimon0505004
*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //use binary search
        int low=0, high=nums.size()-1;
        int result = -1;
        while(low<=high)
        {
            int currentIndex = (low+high)/2;
            if(target==nums.at(currentIndex))
                return currentIndex;
            else
            {
                if(target<nums.at(currentIndex))
                    high = currentIndex-1;
                else
                    low = currentIndex+1;
            }           
        }
        return low;
    }
};