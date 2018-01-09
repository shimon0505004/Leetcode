/*
	shimon0505004
	14. Longest Common Prefix
	https://leetcode.com/problems/longest-common-prefix/
*/


class Solution {
public:
    
    string longestCommonPrefix(string& left, string& right)
    {
        if(!left.empty() && !right.empty())
        {
            string prefix;
            prefix.reserve(std::min(left.length(),right.length()));
            
            int index=0;
            while(index < left.size() && index < right.size())
            {
                if(left.at(index) == right.at(index))
                {
                    prefix += left.at(index);                    
                }
                else
                    break;
                index++;
            }
            
            return prefix;
        }
        return string();
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return string();
        
        int index = 0;
        string prefix = strs.at(index);
        index++;
        while(index < strs.size())
        {
            prefix = longestCommonPrefix(prefix, strs.at(index));
            if(prefix.empty())
                break;
            
            index++;
        }
        
        return prefix;
    }
};