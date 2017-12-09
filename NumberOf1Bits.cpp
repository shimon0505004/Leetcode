/*
	https://leetcode.com/submissions/detail/125621644/
	shimon0505004
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