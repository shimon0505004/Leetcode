/*
	https://leetcode.com/problems/number-of-segments-in-a-string/description/
	shimon0505004
*/

class Solution {
public:
    int countSegments(string s) {
        bool previousCharIsSpace = true;
        int segments = 0;
        for(char c:s)
        {
            if(!std::isspace(c) && previousCharIsSpace)
                segments++;                    
    
            previousCharIsSpace = std::isspace(c);
        }
        
        return segments;
    }
};