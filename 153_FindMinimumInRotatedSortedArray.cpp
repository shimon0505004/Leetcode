/*
	https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
	shimon0505004
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<hi)
        {
            if(nums.at(lo)<nums.at(hi))
                break;
            else
            {
                int mid = (lo + hi )/2;
                if(nums.at(mid)>nums.at(lo))
                    lo = mid+1;
                else
                    lo = lo +1;
            }
        }
        
        return nums.at(lo);
    }
};