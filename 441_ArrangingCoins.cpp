/*
	https://leetcode.com/problems/arranging-coins/
	shimon0505004
*/

class Solution {
public:
    int arrangeCoins(int n) {
        int row=0;
        while(n-row>=0)
        {
            n -=row;
            row++;
        }
        return row-1;
    }
};