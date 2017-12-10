/*
	https://leetcode.com/problems/repeated-substring-pattern/
	shimon0505004
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string newStr(s);
        for(int count=0;count<s.length()-1;count++)
        {
            std::rotate(newStr.begin(),newStr.begin()+1,newStr.end());
            
            if(s==newStr)
                return true;
        }
        return false;
    }
};