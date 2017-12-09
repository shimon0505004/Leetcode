/*
	https://leetcode.com/problems/letter-combinations-of-a-phone-number/
	shimon0505004
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        std::map<char,std::set<char>> letterMap;
        letterMap['0'] = {' '};
        letterMap['1'] = {};
        letterMap['2'] = {'a','b','c'};
        letterMap['3'] = {'d','e','f'};
        letterMap['4'] = {'g','h','i'};
        letterMap['5'] = {'j','k','l'};
        letterMap['6'] = {'m','n','o'};
        letterMap['7'] = {'p','q','r','s'};
        letterMap['8'] = {'t','u','v'};
        letterMap['9'] = {'w','x','y','z'};
        letterMap['*'] = {'+'};
        
        bool smallLetters = true;
        
        if(digits.length()>0)
            results.push_back(string());
        
        for(const char& c:digits)
        {
            if(c=='#')
                smallLetters = !smallLetters;
            else
            {
                vector<string> tempResults;
                while(!results.empty())
                {
                    string s = results.front();
                    results.erase(results.begin());
                    if((c>='0' && c<='9')
                        || (c=='*'))
                    {
                        for(const char& letter:letterMap[c])
                        {
                            string temp = s+letter;
                            tempResults.push_back(temp);
                        }
                    }
                }
                results = tempResults;
            }
        }
        
        return results;
    }
};