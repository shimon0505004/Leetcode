/*
	https://leetcode.com/problems/find-the-difference/
	shimon0505004
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> charCounter(28);
        for(const char& c:t)
            charCounter[c-'a']++;
        for(const char& c:s)
            charCounter[c-'a']--;
        vector<int>::iterator it = find_if(std::begin(charCounter),std::end(charCounter), [](int val){return val>0;});
        return 'a'+(it-std::begin(charCounter));
    }
};