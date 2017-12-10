/*
	https://leetcode.com/problems/detect-capital/
	shimon0505004
*/

#include<regex>

class Solution {
public:
    bool detectCapitalUse(string word) {
        return (std::regex_match(word,std::regex("[A-Z]+|[a-z]+|[A-Z][a-z]+"))==1);
    }
};