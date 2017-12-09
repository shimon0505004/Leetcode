/*
	https://leetcode.com/problems/largest-number/
	shimon0505004
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::sort(nums.begin(),nums.end(), greaterThan);
        std::string result;
        for(int num:nums)
            result += std::to_string(num);
        
        while(result.length()>1)
        {
            if(result.at(0)=='0')
                result = result.substr(1,result.length()-1);
            else
                break;            
        }
            
        return result;
    }
    
    static bool greaterThan(const int& left, const int& right)
    {
        std::string leftStr = std::to_string(left);
        std::string rightStr = std::to_string(right);
        if(leftStr.length()!=rightStr.length())
        {
            std::string leftRightStr = leftStr + rightStr;
            std::string rightLeftStr = rightStr + leftStr;
            return leftRightStr > rightLeftStr;
        }
        
        return left>right;
    }
    
};