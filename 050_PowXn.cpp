/*
	https://leetcode.com/problems/powx-n/description/
	shimon0505004
*/

class Solution {
public:
    double myPow(double x, int n) {
        return doubleMyPow(x,n);
    }
    
    
    double recursiveMyPow(double x, int n)
    {
        //takes log(n) time to calculate power
        if(n<0)
            return (1/x)*recursiveMyPow(1/x,-(n+1));
        else if(n==0)
            return 1;
        else if(n==1)
            return x;
        else if(n==2)
            return x*x;
        else if(n % 2 == 0)
            return recursiveMyPow(recursiveMyPow(x, n/2),2);
        else 
            return x * recursiveMyPow(recursiveMyPow(x, n/2),2);
    }
    
    
    double doubleMyPow(double x, int n) { 
        if(n==0) return 1;
        double t = doubleMyPow(x,n/2);
        if(n%2 !=0)
            return n<0 ? 1/x * t * t : x*t*t;
        return t*t;
    }
    
    
    double doubleXMyPow(double x, int n)
    {
        double seed = (n < 0) ? 1/x : x;
        if(n!=0)
        {
           double t = seed*seed;
           int newN = abs(n/2);
           double answer = doubleXMyPow(t,newN);
           if(n%2 != 0)
              answer *= seed;
                
           return answer;
       }
       else
           return 1;
           
    }
};