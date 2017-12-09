/*
	https://leetcode.com/problems/reverse-bits/
	shimon0505004
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t bitTester = 1;
        uint32_t reversedNumber = 0;
        for(int bitPositionFromRight = 0 ; bitPositionFromRight<32 ; bitPositionFromRight++){
            int result = (n & bitTester) != 0 ? 1 : 0 ;
            
            reversedNumber = reversedNumber | result;
            
            cout << result <<" " << reversedNumber << endl;
            if(bitPositionFromRight!=31)
            {
                bitTester <<= 1;
                reversedNumber <<= 1;
                
            }
            
        }
        return reversedNumber;
    }
};