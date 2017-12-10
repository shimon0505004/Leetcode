/*
	https://leetcode.com/problems/climbing-stairs/
	shimon0505004
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> fib(n+1,0);
        fib[0]=0;
        fib[1]=1;
        fib[2]=2;
        for(int index=3;index<=n;index++)
        {
            fib[index] = fib[index-1] + fib[index-2];
        }
        
        return fib[n];
    }
};