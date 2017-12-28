/*
	shimon0505004
	13. Roman to Integer
	https://leetcode.com/problems/roman-to-integer
*/

class Solution {
public:

        
    int extractRomanNumeralAndConvertToNumber(string& source, string romanNumeral, int correspondingNumber)
    {
        size_t findIndex = source.find(romanNumeral);
        if(findIndex==0)
        {
            source.erase(source.begin(),source.begin()+romanNumeral.length());
            return correspondingNumber;
        }
        
        return 0;
    }

    
    int getIntFromBegininng(string& s)
    {
        int result = 0;
        for(auto romanToInt : romanToIntMapping)
        {
            result = extractRomanNumeralAndConvertToNumber(s, romanToInt.first, romanToInt.second);
            if(result != 0)
                break;
        }
        
        return result;
    }
    
    
    int romanToInt(string s) {
        if(s.empty())
            return 0;
        
        int result = 0;
        while(!s.empty())
        {
            int val = getIntFromBegininng(s);
            if(val==0)
                return 0;
            
            result += val;
        }
        return result;
    }
    
private:
    std::vector<std::pair<std::string,int>> romanToIntMapping = {{"M",1000},
                                                             {"CM",900},
                                                             {"D" ,500},
                                                             {"CD",400},
                                                             {"C" ,100},
                                                             {"XC", 90},
                                                             {"L" , 50},
                                                             {"XL", 40},
                                                             {"X" , 10},
                                                             {"IX",  9},
                                                             {"V" ,  5},
                                                             {"IV", 4},
                                                             {"I" , 1}};
};