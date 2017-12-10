/*
	https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
	shimon0505004
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> returnVal = {-1,-1};
        
        int frontPointer = 0;
        int backPointer = numbers.size()-1;
        while(frontPointer<=backPointer)
        {
            int tempSum = numbers[frontPointer]+numbers[backPointer];
            if(tempSum == target)
            {
                returnVal[0] = frontPointer+1;
                returnVal[1] = backPointer+1;
                break;
            }
            else if(tempSum>target)
                backPointer--;
            else
                frontPointer++;
        }
        return returnVal;
    }
};