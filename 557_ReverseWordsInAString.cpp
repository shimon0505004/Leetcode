/*
	https://leetcode.com/problems/reverse-words-in-a-string-iii/
	shimon0505004
*/

class Solution {
public:
    string reverseWords(string s) {
        vector<string> wordsInReverse;
        std::stringstream stream;
        for(int index = s.length()-1;index>=0;index--)
        {
            if(s.at(index)!=' ')
                stream<<s.at(index);
            else
            {
                wordsInReverse.push_back(stream.str());
                stream.str("");
            }
        }
        
        wordsInReverse.push_back(stream.str());
        stream.str("");
        
        string outputStr;
        for(int index=wordsInReverse.size()-1;index>=0;index--)
        {
            outputStr+=wordsInReverse.at(index).c_str();
            if(index!=0)
                outputStr+=" ";
        }
        
        return outputStr;
    }
};