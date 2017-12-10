/*
	https://leetcode.com/problems/subarray-sum-equals-k/
	shimon0505004
*/

class Solution {
public:
    int subarraySum(const vector<int>& nums, int k) {

        int result = 0;
        int preSum = 0;
        map<int, int> sumMap;
        sumMap.insert(std::pair<int, int>(preSum, 1));
        for (int index = 0; index < nums.size(); index++)
        {
            preSum += nums.at(index);
            result += sumMap[preSum - k];
            sumMap[preSum]++;
        }

        return result;
    }
};