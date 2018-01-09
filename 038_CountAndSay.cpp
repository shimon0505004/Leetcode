/*
	shimon0505004
	038. Count and Say
	https://leetcode.com/problems/count-and-say/
*/

#include<stack>

class Solution {
public:
    string countAndSay(string inputString)
    {
        stack<char> characterStack;
        stack<int> countStack;
        
        for(char c: inputString)
        {
            if(characterStack.empty())
            {
                characterStack.push(c);
                countStack.push(1);                
            }
            else
            {
                if(c==characterStack.top())
                {
                   int incrementedCountForC = countStack.top() + 1;
                   countStack.pop();
                   countStack.push(incrementedCountForC);                    
                }
                else
                {
                    characterStack.push(c);
                    countStack.push(1);                                    
                }
            }
        }

        string resultString;

        while(!characterStack.empty() && !countStack.empty())
        {
            string countToString = std::to_string(countStack.top());
            countStack.pop();
            string charString;
            charString +=  characterStack.top();
            characterStack.pop();

            resultString = countToString + charString + resultString;
        }
        
        return resultString;
    }
    

    
    string countAndSay(int n) {
        string result = string("1");
        if(n==1)
            return result;
        
        for(int count = 2; count <= n; count++)
        {
            result = countAndSay(result);
        }
        return result;
    }
};