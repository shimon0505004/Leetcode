/*
	https://leetcode.com/problems/range-sum-query-immutable/
	shimon0505004
*/

class NumArray {
public:
    NumArray(vector<int> nums) {
        runningSum = vector<int>(nums.size()+1);
        runningSum[0] = 0;
        for(int index=0;index<nums.size();index++)
        {
            runningSum[index+1] = runningSum[index] + nums[index];
        }
    }
    
    int sumRange(int i, int j) {
        return runningSum[j+1] - runningSum[i];
    }
    
private:
    vector<int> runningSum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */