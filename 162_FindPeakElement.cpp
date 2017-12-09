/*
	https://leetcode.com/problems/find-peak-element/
	shimon0505004
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return findPeakElementBinarySearch(nums);
    }
    
    int findPeakElementLinear(vector<int>& nums) {
        int peakIndex = -1;
        for(int index=0;index<nums.size();index++)
        {
            bool left = false;
            bool right = false;
            if((index-1<0) || (nums[index]>nums[index-1]))
                left = true;
            
            if((index+1>=nums.size()) || (nums[index]>nums[index+1]))
                right = true;
            
            if(left && right)
            {
                peakIndex = index;
                break;                
            }
        }
        
        return peakIndex;
    }
    
    int findPeakElementBinarySearch(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        int finalIndex = lo -1;
        while(lo<hi)
        {
            int midIndex = (lo+hi)/2;
            if(((midIndex-1<0)|| (nums[midIndex]>nums[midIndex-1]))
               && ((midIndex+1>=nums.size()) || (nums[midIndex]>nums[midIndex+1])))
            {
                finalIndex = midIndex;
                break;
            }
            else
            {
                if((midIndex-1<0)|| (nums[midIndex]>nums[midIndex-1]))
                    lo = midIndex + 1;
                else
                    hi = midIndex - 1;
            }
        }
        
        if(lo>=hi)
            finalIndex = lo;
        
        return finalIndex;
        
    }
};