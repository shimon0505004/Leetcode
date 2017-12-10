/*
	https://leetcode.com/problems/power-of-two/
	shimon0505004
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n<=0? false : ((n&(n-1))==0);
    }
};