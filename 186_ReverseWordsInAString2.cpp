/*
	shimon0505004
	https://leetcode.com/problems/reverse-words-in-a-string-ii
*/

#include<iostream>

class Solution {
public:
   
    void reverseWordsWithoutExtraSpace(vector<char>& str) {
        //First, completely reverse the string.
        for(int forwardIndex=0, reverseIndex= str.size()-1
            ; forwardIndex < reverseIndex
            ; forwardIndex++, reverseIndex--)
        {
            std::swap(str[forwardIndex],str[reverseIndex]);
        }
        
        vector<int> spaceLocations;
        
        for(int index = 0; index< str.size(); index++)
        {
            if(str[index]==' ')
                spaceLocations.push_back(index);
        }
        spaceLocations.push_back(str.size());
        
        int startingPosition = 0;
        for(int endPoint: spaceLocations)
        {
            for(int forwardIndex=startingPosition, reverseIndex= endPoint-1 ; forwardIndex < reverseIndex ; forwardIndex++, reverseIndex--)
            {
                std::swap(str[forwardIndex],str[reverseIndex]);
            }
            
            startingPosition = endPoint+1;
        }
    }
    
    
    
    void reverseWordsUsingExtraSpace(vector<char>& str) {
        string currentWord;
        std::stack<string> stackForReversing;
        for(const auto& c: str)
        {
            if(c==' ')
            {
                stackForReversing.push(currentWord);
                currentWord = string();
            }
            else
                currentWord.append(1,c);
        }
        stackForReversing.push(currentWord);
        
        string result;
        while(!stackForReversing.empty())
        {
            result.append(stackForReversing.top());
            stackForReversing.pop();
            if(!stackForReversing.empty())
                result.append(" ");            
        }
        
        
        for(int index=0; index<str.size(); index++)
        {
            str[index] = result[index];
        }
    }
    
    
    
    void reverseWords(vector<char>& str) {
        reverseWordsWithoutExtraSpace(str);
    }
};