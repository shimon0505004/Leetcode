/*
	https://leetcode.com/problems/valid-perfect-square/
	shimon0505004
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        return bisectionMethodPerfectSquare(num);
    }
    
    
    bool linearTimePerfectSquare(int num)
    {
        if(num>=0)
        {
            int seed=1;
            while(seed*seed<num && seed<=46340)
                seed++;
            return(seed*seed==num);
                
        }
        return false;
    }
    
    
    bool bisectionMethodPerfectSquare(int num) {
        long long low = 0;
        long long high = num;
        while(low<=high)
        {
            long long mid = (low+high)/2;
            long long sqmid = mid*mid;
            if(sqmid > num) high = mid-1;
            else if(sqmid < num) low = mid+1;
            else return true;
        }
        return false;
    }
};