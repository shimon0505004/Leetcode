/*
	https://leetcode.com/problems/valid-anagram/
	shimon0505004
*/

#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {

       unordered_map<int,int> hashMap_s;
       unordered_map<int,int> hashMap_t;
       
       for(const auto& c : s)
       {
           int temp = hashMap_s.count(c);
           if(temp==0)
           {
               hashMap_s.emplace(c,1);
           }else
           {
               hashMap_s[c] = hashMap_s[c]+1;
           }
       }


       for(const auto& c : t)
       {
           int temp = hashMap_t.count(c);
           if(temp==0)
           {
               hashMap_t.emplace(c,1);
           }else
           {
               hashMap_t[c] = hashMap_t[c]+1;
           }
       }
       
        for(auto it = hashMap_s.begin();it!=hashMap_s.end();it++)
        {
            auto key = it->first;
            if(hashMap_t[key]!=hashMap_s[key])
                return false;
        }
        
        
        for(auto it = hashMap_t.begin();it!=hashMap_t.end();it++)
        {
            auto key = it->first;
            if(hashMap_t[key]!=hashMap_s[key])
                return false;
        }
        
        return true;
    }
    
    
    
    
};