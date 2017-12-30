/*
	shimon0505004
	191. Number of 1 Bits
	https://leetcode.com/problems/number-of-1-bits/
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t bitTester =1;
        int result =0;
        for(int count = 1; count <= 32 ; count++){
            result += ((n & bitTester) != 0 ? 1 : 0);
            bitTester <<= 1;
        }
        return result;
    }
};