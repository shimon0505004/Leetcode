/*
	https://leetcode.com/problems/fizz-buzz/
	shimon0505004
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> output;
        for(int number=1;number<=n;number++)
        {
            if(number%15==0)
                output.push_back("FizzBuzz");
            else if(number %3==0)
                output.push_back("Fizz");
            else if(number %5==0)
                output.push_back("Buzz");
            else
                output.push_back(std::to_string(number));
        }
        
        return output;
    }
};