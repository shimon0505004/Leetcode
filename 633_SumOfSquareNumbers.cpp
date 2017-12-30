/*
	shimon0505004
	633. Sum of Square Numbers
	https://leetcode.com/problems/sum-of-square-numbers/
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        
        for(int a=0; a<= (static_cast<int>(sqrt(c))) ; a++){
            int b_2 = c - (a*a);
            if(b_2 >= 0){
                if( ((static_cast<int>(sqrt(b_2))) * (static_cast<int>(sqrt(b_2))) == b_2))
                   return true;
            }
            else
                break;
        }
    
        return false;
        
    }
};