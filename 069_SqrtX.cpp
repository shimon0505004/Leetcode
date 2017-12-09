/*
	https://leetcode.com/problems/sqrtx/
	shimon0505004
*/


class Solution {
public:
    int mySqrt(int x) {
        return static_cast<int>(newtonsMethod(x));
    }
    
    long double newtonsMethod(int x)
    {
        if(x!=0)
        {
            long double ans = static_cast<long double>(x);
            long double delta = 0.00001;
            while(fabs(pow(ans,2)-x) > delta)
            {
                ans = (ans + x/ans)/2;
            }
            return ans;
        }
        
        return 0;
    }
    
};