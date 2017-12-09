/*
	https://leetcode.com/problems/isomorphic-strings/description/
	shimon0505004
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(isIsomorphicSubRoutine(s,t))
            return isIsomorphicSubRoutine(t,s);
        
        return false;
    }
    
    bool isIsomorphicSubRoutine(string s, string t) {
        
        int charArr[256];
        std::fill(charArr,charArr+256,-1);
        for(int index=0;index<s.size();index++)
        {
            int sIndex = s.at(index)-0;
            int tIndex = t.at(index)-0;
            
            if(charArr[sIndex]==-1)
                charArr[sIndex]=tIndex;
            else if(charArr[sIndex]!=tIndex)
                return false;               
        }
        return true;
    }
};