/*
	https://leetcode.com/problems/factorial-trailing-zeroes/description/
	shimon0505004
*/

class Solution {
public:
    int trailingZeroes(int n) {
        return n==0? n : n/5 + trailingZeroes(n/5);
    }
};