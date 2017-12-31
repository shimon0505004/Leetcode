/*
	shimon0505004
	266. Palindrome Permutation
	https://leetcode.com/problems/palindrome-permutation
*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> alphabetCount(256,0);
        for(const char& c: s)
        {
            int index = static_cast<int>(c);
            if(alphabetCount[index]==1)
                alphabetCount[index] = 0;
            else
                alphabetCount[index]++;
        }
        
        int countOf1 = std::count(alphabetCount.begin(),alphabetCount.end(),1);
        return (countOf1 > 1) ? false : true;
    }
};