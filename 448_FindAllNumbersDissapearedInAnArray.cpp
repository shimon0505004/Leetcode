/*
	https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
	shimon0505004
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        std::set<int> s(nums.begin(),nums.end());
        vector<int> result;
        for(int i=1;i<=n;i++)
        {
            if(s.count(i)==0)
                result.push_back(i);
        }
        
        return result;
    }
};