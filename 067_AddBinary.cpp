/*
	https://leetcode.com/problems/add-binary/
	shimon0505004.gmail.com
*/

#include <bitset>

class Solution {
public:
    string addBinary(string a, string b) {
        int len = std::max(a.length(),b.length()) + 1;
        std::string s(len,'0');
        
        int sIndex = s.length()-1;
        for(int index=a.length()-1;index>=0;index--,sIndex--)
        {
            s[sIndex]=a[index];
        }

        int index= b.length()-1;
        sIndex = s.length()-1;
        bool carry = false;
        bool sum = false;
        for(;sIndex>0;sIndex--, index--)
        {
            bool left = s[sIndex]=='1'? true : false;
            bool right = ((index>=0) && b[index]=='1') ? true : false;
            bool sum = carry ^ left ^ right;
            carry = (left&right) |(right&carry) | (carry&left);
            s[sIndex] = sum ? '1' : '0';
        }
        
        if(!carry && s.length()>1)
            s.erase(s.begin());
        else
            s[0] = '1';
        
        return s;
    }
};