/*
	https://leetcode.com/problems/implement-magic-dictionary/description/
	shimon0505004
*/

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        _dict.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(const std::string& str: dict)
        {
            for(int index=0; index<str.length(); index++)
            {
                std::string key = str.substr(0,index-0);
                if(index != str.length()-1)
                    key += str.substr(index+1,str.length()-index-1);
                
                if(_dict.count(std::make_pair(key,index))==0)
                {
                    std::set<char> possibleVariations;
                    possibleVariations.insert(str[index]);
                     _dict.insert(std::make_pair(std::make_pair(key,index),possibleVariations));
                }
                else
                {
                    _dict.at(std::make_pair(key,index)).insert(str[index]);
                }
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string str) 
    {
        bool found = false;
            for(int index=0; index<str.length(); index++)
            {
                std::string key = str.substr(0,index-0);
                if(index != str.length()-1)
                    key += str.substr(index+1,str.length()-index-1);
                
                if(_dict.count(std::make_pair(key,index))>0)
                {
                    std::set<char> possibleVariations = _dict.at((std::make_pair(key,index)));
                    if(possibleVariations.size()>1)
                    {
                        found = true;
                        break;
                    }
                    else
                    {
                        if(possibleVariations.find(str[index]) == possibleVariations.end())
                        {
                            found = true;
                            break;
                        }
                    }
                }
            }
        
        return found;
    }
    
private:
    std::map<std::pair<std::string,int>,std::set<char>>   _dict;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */