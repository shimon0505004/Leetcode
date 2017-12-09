/*
	https://leetcode.com/problems/add-digits/
	shimon0505004
*/

class Solution {
public:
    int addDigits(int num) {
        int sum = num;
        while(sum>=10)
        {
            int tempSum = 0;
            int temp = sum;
            while(temp>0)
            {
                tempSum+=temp%10;
                temp = (temp-(temp%10))/10;
            }
            sum = tempSum;
        }
        return sum;
    }
};