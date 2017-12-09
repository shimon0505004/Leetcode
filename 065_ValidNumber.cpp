/*
	https://leetcode.com/problems/valid-number/
	shimon0505004
*/

class Solution {
public:
    bool isNumber(string s) {
        if(!s.empty())
        {
            if(s.at(0)==' ')
                return isNumber(s.substr(1,s.length()-1));
            else if(s.at(s.length()-1)==' ')
                return isNumber(s.substr(0,s.length()-1));
            else
            {   
                bool result = false;
                bool digitBeforeEAlreadyFound = false;
                bool digitAfterEAlreadyFound = false;
                bool eAlreadyFound = false;
                bool signAfterEAlreadyFound = false;
                bool decimalAlreadyFound = false;
                for(int index=0;index<s.length();index++)
                {
                    if(std::isdigit(s.at(index)))
                    {
                        digitBeforeEAlreadyFound = true;
                        result = true;
                        if(eAlreadyFound)
                            digitAfterEAlreadyFound = true;
                    }
                    else if(s.at(index)=='e')
                    {
                        if(eAlreadyFound || !digitBeforeEAlreadyFound)                           
                        {
                            result = false;
                            break;
                        }
                        else
                            eAlreadyFound = true;
                    }
                    else if(s.at(index)=='+' || s.at(index)=='-')
                    {
                        if(index>=1 
                           && ((s.at(index-1)=='e'))
                           && !signAfterEAlreadyFound)
                        {
                            signAfterEAlreadyFound = true;
                        }
                        else if(index!=0)
                        {
                            result = false;
                            break;
                        }
                    }
                    else if(s.at(index)=='.')
                    {
                        if(!decimalAlreadyFound && !eAlreadyFound)
                        {
                            decimalAlreadyFound = true;
                        }
                        else
                        {
                            result = false;
                            break;
                        }
                    
                    }
                    else
                    {
                        result = false;
                        break;
                    }
                }
                
                if(result && eAlreadyFound)
                {
                    result = digitBeforeEAlreadyFound && digitAfterEAlreadyFound;
                }
                return result;
            }
        }
        return false;
    }
};