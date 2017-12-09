/*
	https://leetcode.com/problems/search-in-rotated-sorted-array/description/
	shimon0505004
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int indexOfMinElement = findMinIndex(nums); //logn
        int index = subSearch(nums, target, 0, indexOfMinElement-1);    //logn
        if(index ==-1)
            index = subSearch(nums, target, indexOfMinElement , nums.size()-1); //logn
        
        return index;
    }
    
    int subSearch(vector<int>& nums, int target, int lo, int hi)
    {
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            if(target==nums.at(mid))
                return mid;
            else
            {
                if(target>nums.at(mid))
                    lo = mid+1;
                else
                    hi = mid-1;
            }            
        }
        
        return -1;
    }
    
    int findMinIndex(vector<int>& nums) {
        
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<hi)
        {
            int mid = (lo + hi )/2;
            
            if(nums.at(lo)<=nums.at(hi))
                break;
            else
            {
                
                if(nums.at(mid)>nums.at(lo))
                    lo = mid + 1;
                else
                    lo = lo + 1;
            }
        }
        return lo;
    }
    
};