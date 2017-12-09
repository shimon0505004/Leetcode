/*
	https://leetcode.com/problems/word-pattern/description/
	shimon0505004
*/

class Solution {
public:
        
    vector<string> splitter(string str){
        vector<string> result;
        std::string currentWord;
        
        for(const char& character: str){
            if(std::isspace(character) || std::ispunct(character))
            {
                if(!currentWord.empty())
                    result.push_back(currentWord);
                currentWord.clear();                
            }
            else
                currentWord.append(1,character);
            
        }
        
        if(!currentWord.empty())
            result.push_back(currentWord);
        
        return result;
    }
    
    
    bool wordPattern(string pattern, string str) {
        std::unordered_set<std::string> letterToWordMap[26];
        std::unordered_map<std::string, std::unordered_set<char>> wordToLetterMap;
        
        vector<string> words = splitter(str);
        if(pattern.length() != words.size())
            return false;
        
        int wordindex= 0;
        for(const char& character: pattern){
            letterToWordMap[character-'a'].insert(words[wordindex]);
            wordToLetterMap[words[wordindex]].insert(character);
            
            wordindex++;
        }
        
        for(const auto& singleLetterToWordMapping: letterToWordMap)
        {
            if(singleLetterToWordMapping.size() > 1)
                return false;
        }
        
        for(const auto& singleWordToLetterMapping: wordToLetterMap)
        {
            if(singleWordToLetterMapping.second.size() > 1)
                return false;
        }
        
        return true;
    }

};