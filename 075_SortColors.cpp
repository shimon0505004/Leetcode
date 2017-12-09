/*
	https://leetcode.com/problems/sort-colors/
	shimon0505004
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<vector<int>> RGB = {{},{},{}};
        while(!nums.empty())
        {
            RGB.at(nums.front()).push_back(nums.front());
            nums.erase(nums.begin());
        }
    
        while(!RGB.empty())
        {
            nums.insert(nums.end(),RGB.front().begin(),RGB.front().end());
            RGB.erase(RGB.begin());
        }
    }
};