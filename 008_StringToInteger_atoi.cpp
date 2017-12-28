/*
	shimon0505004
	https://leetcode.com/problems/string-to-integer-atoi/
	
	Several cases to consider.
	
	1) Input String can contain Leading and trailing spaces or tabs.
	   like: "    123242sfa   "
	   In this case, We have to trim leading and trailing spaces/tabs.
	
	2) After Removing the leading and traliling spaces and tabs,
	   We have to look at the first character and check if it is a sign (+, -), digit (0-9)
	   or a non-digit character.
	   If after the whitespace trimming, the input string starts with a non-digit character excluding
	   signs, then this number can not be converted to an integer.
	   Return 0 in this case.
	
	3) If sign characters are found, save it and trim that character also.
	
	4) After removing the sign, The string will be of the format "123safasa fsafasf asfa"
	   Trim the string again from the occurance of first non-digit character ("123").
	
	5) Then convert it to integer. If the trimmed string length is > 10, it can not be converted
	to a integer. Depending on the sign, return INT_MAX or INT_MIN.
	
	6) Depending on the sign, use subtraction / addition rule
*/


#include <algorithm>

class Solution {
public:
    
    void ltrim(string& str)
    {
        str.erase(str.begin(),std::find_if(str.begin(),str.end(),[](unsigned char ch){
            return !std::isspace(ch);
        }));
    }
    
    void rtrim(string& str)
    {
        str.erase(std::find_if(str.rbegin(),str.rend(),[](unsigned char ch){
            return !std::isspace(ch);
        }).base(),str.end());
    }
    
    
    void trim(string& str)
    {
        ltrim(str);
        rtrim(str);
    }
    
    void nonIntegralPartTrim(string& str)
    {
        str.erase(std::find_if(str.begin(),str.end(),[](unsigned char ch){
            return !std::isdigit(ch);
        }), str.end());
    }
    
    void signTrim(string& str)
    {
        if((*str.begin())=='-' 
           || (*str.begin())=='+')
        {
            str.erase(str.begin());
        }
    }
    
    int signExtraction(string& str)
    {
        /*
            If the first character is a digit or contains a sign, 
        */
        int firstCharSign = 0;
        if(str.at(0)=='-')
        {
            firstCharSign = -1;
            signTrim(str);           
        }
        else if(str.at(0)=='+')
        {
            firstCharSign = 1;
            signTrim(str);            
        }
        else if(std::isdigit(str.at(0)))
            firstCharSign = 1;

        return firstCharSign;
    }
    
    int outOfBound(int sign)
    {
        return (sign == 1) ? INT_MAX : INT_MIN ;
    }
    
    int atoi_based_on_sign(string str, int sign)
    {
        if(sign == 0)
            return 0;
        
        if(str.length()>10 || ((str.length()==10) && str.at(0) > '2'))
            return outOfBound(sign);
        
        return sign==1 ? atoi_positive(str) : atoi_negative(str) ;
    }
    
    int atoi_positive(string str)
    {
        int result = 0;
        
        for(auto c: str)
        {
            if(result > (INT_MAX/10))
                return outOfBound(1);
            
            result *= 10;
            int num = c - '0';
            if(!(num>=0 && num<=9))
            {
                return 0;
            }
            
            if(result == ((INT_MAX/10)*10))
            {
                if(num>=7) 
                    return outOfBound(1);
            }    
                
            result += num;
        }
        
        return result;
    }
                  
    int atoi_negative(string str)
    {
        int result = 0;
        
        for(auto c: str)
        {
            if(result < (INT_MIN/10))
                return outOfBound(-1);
            
            result *= 10;
            int num = c - '0';
            if(!(num>=0 && num<=9))
            {
                return 0;
            }
            
            if(result == ((INT_MIN/10)*10))
            {
                if(num>=8) 
                    return outOfBound(-1);
            }    
                
            result -= num;
        }
        
        return result;
    }                   
    
    int myAtoi(string str) {        
        
        trim(str);
        if(str.empty())
            return 0;
                
        int sign = signExtraction(str);
        if(sign == 0)   //Sign 0 means starts with a non-digit char
            return 0;
        
        nonIntegralPartTrim(str);

        if(str.empty())
            return 0;
                
        int result = atoi_based_on_sign(str, sign);
                
        return result;
    }
};