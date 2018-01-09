/*
	shimon0505004
	567. Permutation in String
	https://leetcode.com/problems/permutation-in-string/
*/


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int map1[26] = {0};   //storing frequency count for s1;
        int map2[26] = {0};   //sliding window's frequency count;
        
        if(s1.length() > s2.length())
            return false;
        
        
        //Step 1. Store frequency count for both s1 and
        //s2's sliding window.
        
        for(int index=0;index<s1.length(); index++)
        {
            map1[s1[index]-'a']++;
            map2[s2[index]-'a']++;            
        }
        
        //Step 2. if frequency matches found for a letter, increment the count for the letter.
        //If frequency match is found for all 26 letters, then a substring is found.
        
        int count = 0;
        for(int index=0;index < 26; index++)
        {
            if(map1[index]==map2[index])
                count++;
        }
        
        //Step 3. Move the sliding window in string s2. 
        for(int index=0 ; index < s2.length() - s1.length(); index++)
        {
            if(count == 26)
                return true;
            
            int leftIndex = s2[index]-'a';
            int rightIndex = s2[index+s1.length()] -'a';
            
            //If adding the next right character matches the corresponding character in first map
            //increment count.
            //If previously it was a match, and adding a new character increments the frequency range
            //decrement the number of matching characters.
            map2[rightIndex]++;
                        
            if(map2[rightIndex] == map1[rightIndex])
                count++;
            else if(map2[rightIndex] == map1[rightIndex] + 1)
                count--;

            //If removing the leftfomst character matches the corresponding character in first map
            //increment count.
            //If previously it was a match, and removing leftmost character decrements the frequency range
            //decrement the number of matching characters.            
            map2[leftIndex]--;
            if(map2[leftIndex] == map1[leftIndex])
                count++;
            else if(map2[leftIndex] == map1[leftIndex] - 1)
                count--;
            
        }
        
        return count==26;
    }
};