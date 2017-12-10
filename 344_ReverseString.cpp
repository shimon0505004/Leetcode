/*
	https://leetcode.com/problems/reverse-string/
	shimon0505004
*/

class Solution {
public:
    string reverseString(string s) {
        int lo = 0;
        int hi = s.length()-1;
        while(lo<hi)
        {
            std::swap(s[lo],s[hi]);
            lo++;
            hi--;
        }
        return s;
    }
};