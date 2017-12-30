/*
	shimon0505004
	047. Permutations II
	https://leetcode.com/problems/permutations-ii/
*/


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        do{
            result.push_back(nums);
        }while(std::next_permutation(nums.begin(),nums.end()));        
        return result;
    }
};