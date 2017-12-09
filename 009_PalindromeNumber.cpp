/*
	https://leetcode.com/problems/palindrome-number/
	shimon0505004
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        
        int p = x;
        int q = 0;
        while(p>0)
        {
            q *= 10;
            q += p%10;
            p = p/10;
        }
        return x==q;
    }
};