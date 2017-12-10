/*
	https://leetcode.com/problems/max-consecutive-ones/
	shimon0505004
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0;
        int tempMax=0;
        bool startBreak=false;
        for(const int& num:nums)
        {   if(num==0)
            {
                if(tempMax>max)
                    max=tempMax;
                
                tempMax=0;
            }
            else
                tempMax++;
       }
       if(tempMax>max)
           max=tempMax; 
        
       return max;
    }
};