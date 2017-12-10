/*
	https://leetcode.com/problems/hamming-distance/
	shimon0505004
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int xor1 = x ^ y;
        int hammingDistance = 0;
        while(xor1)
        {
            //Brian Kernighan's algorithm
            //
            xor1 &= (xor1 -1);
            hammingDistance += 1;
        }
        
        return hammingDistance;
    }
};