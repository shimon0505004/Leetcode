/*
	https://leetcode.com/problems/find-all-anagrams-in-a-string/
	shimon0505004
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if(p.length()<=s.length())
        {
            vector<int> charTracker_s(26);
            vector<int> charTracker_p(26);

            for(const char& c:p)
                charTracker_p.at(c-'a')++;

            for(int index=0;index<p.length()-1;index++)
                charTracker_s.at(s.at(index)-'a')++;


            for(int index=p.length()-1;index<s.length();index++)
            {
                charTracker_s.at(s.at(index)-'a')++;
                int idx = index-p.length();
                if(idx>=0)
                    charTracker_s.at(s.at(idx)-'a')--;



                if(std::equal(charTracker_s.begin(),charTracker_s.end(),charTracker_p.begin()))
                    result.push_back(index+1-p.length());
            }
            
        }
        
        return result;
        
    }
};