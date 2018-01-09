/*
	shimon0505004
	634. Find the Derangement of An Array
	https://leetcode.com/problems/find-the-derangement-of-an-array/
*/

class Solution {
public:
   int findDerangement_UsingOnSpace(int n) 
   {
        vector<int> dearrangementNumber(n,0);
        if(n>1)
        {
            dearrangementNumber[1] = 1;
            for(int index=2;index<n;index++)
            {
                dearrangementNumber[index] = ((index) * (dearrangementNumber[index-1] + dearrangementNumber[index-2])) % 1000000007;
            }
            return dearrangementNumber[n-1];
        }
        return 0;
    }

    
    int findDerangement(int n) {
        return findDerangement_UsingOnSpace(n);
    }
};