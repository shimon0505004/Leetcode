/*
	shimon0505004
	387. First Unique Character in a String
	https://leetcode.com/problems/first-unique-character-in-a-string/
*/


class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        
        for(auto c: s)
        {
            int index = c - 'a';
            count[index] = count[index] + 1 ;
        }
        
        int resultIndex = -1;
        for(int stringIndex = 0 ; stringIndex < s.length(); stringIndex++)
        {
            int index = s[stringIndex] - 'a';
            if(count[index] == 1)
            {
                resultIndex = stringIndex;
                break;
            }
        }
        
        return resultIndex;
    }
};