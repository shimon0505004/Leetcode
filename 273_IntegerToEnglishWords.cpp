/*
	shimon0505004
	https://leetcode.com/problems/integer-to-english-words/description/
*/


class Solution {
public:
    string numberToWords(int num) {
        if(num>=0 && num<20)
            return zeroTo19[num];
        else if(num>=20 && num < 100)
        {
            int index = num/10;
            string firstPart = zeroTo90[index];
            string secondPart = (((num % 10) != 0) ? numberToWords(num%10) : string());
            string result = firstPart;
            if(!secondPart.empty())
            {
                result += " ";
                result += secondPart;
            }
            
            return result;

        }        
        else if(num >= 100 && num < 1000)
        {
            string firstPart = numberToWords(num/100);
            string secondPart = "Hundred";
            string thirdPart = (((num % 100) != 0) ? numberToWords(num%100) : string());
            string result = firstPart;
            result += " ";
            result += secondPart;
            if(!thirdPart.empty())
            {
                result += " ";
                result += thirdPart;
            }
            
            return result;
        }
        else if(num >= 1000 && num < 1000000)
        {
            string firstPart = numberToWords(num/1000);
            string secondPart = "Thousand";
            string thirdPart = (((num % 1000) != 0) ? numberToWords(num%1000) : string());
            string result = firstPart;
            result += " ";
            result += secondPart;
            if(!thirdPart.empty())
            {
                result += " ";
                result += thirdPart;
            }
            
            return result;
        }
        else if(num >= 1000000 && num < 1000000000)
        {
            string firstPart = numberToWords(num/1000000);
            string secondPart = "Million";
            string thirdPart = (((num % 1000000) != 0) ? numberToWords(num%1000000) : string());
            string result = firstPart;
            result += " ";
            result += secondPart;
            if(!thirdPart.empty())
            {
                result += " ";
                result += thirdPart;
            }
            
            return result;
        }
        else if(num >= 1000000000)
        {
            string firstPart = numberToWords(num/1000000000);
            string secondPart = "Billion";
            string thirdPart = (((num % 1000000000) != 0) ? numberToWords(num%1000000000) : string());
            string result = firstPart;
            result += " ";
            result += secondPart;
            if(!thirdPart.empty())
            {
                result += " ";
                result += thirdPart;
            }
            
            return result;
        }
        
        return string();
    }

private:
    vector<string> zeroTo19 = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string> zeroTo90 = {"Zero","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
};