/*
	shimon0505004
	046. Permutations
	https://leetcode.com/problems/permutations/
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permute;
        std::sort(nums.begin(),nums.end());
        do{
            permute.push_back(nums);
        }while(std::next_permutation(nums.begin(),nums.end()));
        return permute;
    }
};