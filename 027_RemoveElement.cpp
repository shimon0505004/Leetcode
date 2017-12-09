/*
	https://leetcode.com/problems/remove-element/
	shimon0505004
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int counter=0;
        for(int index=0;index<size;)
        {
            if(val==nums[index])
            {
                for(int fwdIndex=index+1;fwdIndex<=nums.size()-1 ;fwdIndex++)
                    nums[fwdIndex-1]=nums[fwdIndex];
                size--;
            }
            else
                index++;
            
            
            counter++;
            if(counter>=nums.size())
                break;
        }
        
        return size;
    }
};