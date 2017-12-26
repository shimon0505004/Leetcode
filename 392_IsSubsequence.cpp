/*
	https://leetcode.com/problems/is-subsequence/
	shimon0505004
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0)
            return true;
        
        int sIndex=0;
        for(const char& tChar: t){
            if(tChar == s[sIndex])
                sIndex++;
            
            if(sIndex == s.length())
                return true;
        }
        
        return false;
    }
};