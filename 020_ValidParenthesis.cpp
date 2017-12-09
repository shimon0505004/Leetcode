/*
	https://leetcode.com/problems/valid-parentheses/
	shimon0505004
*/

class Solution {
public:
    bool match(char stackChar, char inputChar)
    {
        return ((stackChar=='(' && inputChar ==')')
                || (stackChar=='{' && inputChar =='}')
                || (stackChar=='[' && inputChar ==']'));
    }
    
    
    bool isValid(string s) {
        std::stack<char> st;
        for(const char& c:s)
        {
            
            if(st.empty() || !match(st.top(),c))
                st.push(c);
            else
                st.pop();
            
        }
        return st.empty();
    }
};