/*
	https://leetcode.com/problems/power-of-four/description/
	shimon0505004
*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        return (((num&(num-1))==0) && (num%3 ==1));
    }
};