/*
	https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/
	shimon0505004
*/

#include <functional>

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        
        std::sort(d.begin(), d.end(), [](const std::string& left, const std::string& right){
            if(left.length()==right.length())
                return left<right;

            return left.length()>right.length();
        });


        
        std::vector<string>::iterator it = std::find_if (d.begin(), d.end(), std::bind(subsequence,s,std::placeholders::_1));
        std::string retStr = (it!=d.end()) ? *it : std::string();
        return retStr;
    }
    
    
    static bool subsequence(std::string left, std::string right)
    {
        std::string::iterator iter = right.begin();
        for(const auto& c:left)
        {
            if(iter==right.end())
                break;
            
            if(c==*iter)
                iter=std::next(iter);
        }
        
        return iter==right.end();
    }
};