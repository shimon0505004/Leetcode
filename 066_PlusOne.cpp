/*
	https://leetcode.com/problems/plus-one/
	shimon0505004
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::reverse_iterator rit = digits.rbegin();
        int carry=1;
        for(;rit!=digits.rend();rit++)
        {
            int result = *rit+carry;
            if(result>=10)
            {
                *rit = result -10;
                 carry = 1;
            }
            else
            {
                *rit = result;
                break;
            }
        }
        
        if(rit==digits.rend() && carry==1)
        {
            digits.emplace(digits.begin(),carry);
        }
        
        return digits;
    }
};