/*
	https://leetcode.com/problems/valid-palindrome/
	shimon0505004
*/

#include <ctype.h>
class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> originalStr,revStr;
        
        for(int count=0;count<s.length();count++)
        {
            if(isalnum (s[count]))
            {
                originalStr.push_back(s[count]);
            }
        }
        
        for(int count=originalStr.size()-1;count>=0;count--)
        {
            revStr.push_back(originalStr[count]);
        }
        
        for(int count = 0; count<originalStr.size();count++)
        {
            if(tolower(originalStr[count])!=tolower (revStr[count]))
                return false;
        }
        
        return true;
    }
};