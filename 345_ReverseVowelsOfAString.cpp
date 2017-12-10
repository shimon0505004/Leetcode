/*
	https://leetcode.com/problems/reverse-vowels-of-a-string/
	shimon0505004
*/

class Solution {
public:
    bool is_vowel(const char& c)
    {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'
                || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') ;
    }

    string reverseVowels(string s) {
        int lo = 0;
        int hi = s.length()-1;
        
        while(lo<=hi)
        {
            if(is_vowel(s.at(lo)))
            {
                if(is_vowel(s.at(hi)))
                {
                    std::swap(s.at(lo),s.at(hi));
                    lo++;
                }
                hi--;
            }else
            {
                if(!is_vowel(s.at(hi)))
                    hi--;
                
                lo++;
            }
        }
        
        return s;
    }
};