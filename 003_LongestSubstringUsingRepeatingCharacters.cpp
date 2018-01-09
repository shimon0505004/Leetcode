/*
	shimon0505004
	003. Longest Substring Without Repeating Characters
	https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/


class Solution {
public:
    
    int lenghtUsingSlidingWindow(string s)
    {
        std::unordered_set<char> set;   //This is the sliding window
        int left = 0;
        int right = 0;
        int answer = right-left;
        while(left < s.length() && right < s.length())
        {
            if(set.count(s[right]) == 0)
            {
                set.insert(s[right]);
                right++;
                answer = std::max(answer,right-left);
            }
            else
            {
                set.erase(s[left]);
                left++;
            }
        }
        
        return answer;
    }
    
    int lengthOfLongestSubstring(string s) {
        return lenghtUsingSlidingWindow(s);  
    }
};