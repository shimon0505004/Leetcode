/*
	https://leetcode.com/problems/length-of-last-word/description/
	shimon0505004
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int lastLength = 0;
        for(const char&c: s)
        {
            if(c!=' ' )
                length++;
            else if(c==' ' && length!=0)
            {
                lastLength = length;
                length = 0;   
            }
        }
        
        return length>0? length : lastLength;
    }
};