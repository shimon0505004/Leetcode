/*
	https://leetcode.com/problems/reverse-words-in-a-string/
	shimon0505004
*/

#include <utility>
#include <functional>

class Solution {
public:
    void reverseWords(string &s) {
        trimSentence(s);
        swapEachWordInPlace(s);
        reverseString(s);
                
        //Now, go and reverse the word 
    }
    
    void trimSentence(string& s)
    {
        auto end = std::unique(s.begin(), s.end(), [](char l, char r){
            return std::isspace(l) && std::isspace(r) && l == r;
        });
        
        s = std::string(s.begin(),end);
        
        while(s.length()>0 && s.front()==' ')
            s.erase(s.begin());
        
        while(s.length()>0 && s.back()==' ')
            s.erase(--s.end());
    }
    
    void swapEachWordInPlace(string& s)
    {
        std::vector<std::pair<int,int>>  wordLocations = locateWordBoundaries(s);    //First pass, O(n)
        for(const auto& location: wordLocations)
        {
            for(int startingPoint = location.first, endingPoint = location.second
                ; startingPoint<=endingPoint
                ; startingPoint++, endingPoint--)
            {
                std::swap(s[startingPoint],s[endingPoint]);
            }
        }
    }
    
    void reverseString(string& s)
    {
        for(int startingPoint = 0, endingPoint = s.length()-1
                ; startingPoint<=endingPoint
                ; startingPoint++, endingPoint--)
        {
            std::swap(s[startingPoint],s[endingPoint]);
        }
    }
        
        
    std::vector<std::pair<int,int>> locateWordBoundaries(const string& s)
    {
        std::vector<std::pair<int,int>> wordLocations;
        
        int openingIndex = -1;
        int closingIndex = -1;
        for(int index=0;index<s.length();index++)
        {
            if(s[index]!=' ')
            {
                if(openingIndex == -1)
                    openingIndex = index;
                
                closingIndex = index;
            }
            else
            {
                if(openingIndex!=-1)
                {
                    std::pair<int,int> location = std::make_pair(openingIndex, closingIndex);
                    wordLocations.push_back(location);                    
                }
                
                openingIndex = -1;
                closingIndex = -1;
            }
        }
        
        if(openingIndex != -1  && closingIndex != -1)
        {
            std::pair<int,int> location = std::make_pair(openingIndex, closingIndex);
            wordLocations.push_back(location);
        }
        
        return wordLocations;
    }
};