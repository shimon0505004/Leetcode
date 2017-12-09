/*
	https://leetcode.com/problems/ransom-note/
	shimon0505004
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int letter[26] = {0};
        for(const char& c: magazine)
        {
            int index = -1;
            if(isalpha(c))
            {
                if(isupper(c))
                    index = c-'A';
                else
                    index = c-'a';
            }
            
            if(index>=0)
                letter[index]++;
        }
        
        bool result = true;
        for(const char& c: ransomNote)
        {
            int index = -1;
            if(isalpha(c))
            {
                if(isupper(c))
                    index = c-'A';
                else
                    index = c-'a';
            }
            
            if(index>=0)
            {
                letter[index]--;
                if(letter[index]<0)
                {
                    result = false;
                    break;
                }
            }
            
        }
        
        
        return result;
    }
};