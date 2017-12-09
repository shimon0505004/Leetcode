/*
	https://leetcode.com/problems/maximum-average-subarray-i/
	shimon0505004
*/


#include <numeric>

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        //Sliding window
        
        double currentAvg = (static_cast<double>(std::accumulate(nums.begin(), nums.begin()+k, 0)) / k);
        double maxAvg = currentAvg;
        for(int index=k;index<nums.size();index++)
        {
            currentAvg += ((static_cast<double>(nums.at(index)-nums.at(index-k)))/k);
            maxAvg = std::max(maxAvg,currentAvg);
        }
        return maxAvg;
    }
};