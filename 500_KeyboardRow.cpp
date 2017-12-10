/*
	https://leetcode.com/problems/keyboard-row/
	shimon0505004
*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> rowForAlphabet = {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};
        vector<string> output;
        for(const string& word:words)
        {
            int curRow = -1;
            bool inSameRow = true;
            for(const char& c:word)
            {
                int index = -1;
                if(c>='a'&& c<='z')
                    index = c-'a';
                else
                    index = c -'A';
                
                if(curRow<1)
                    curRow = rowForAlphabet[index];
                else if(curRow!=rowForAlphabet[index])
                {
                    inSameRow = false;
                    break;
                }
            }
            
            if(inSameRow)
                output.push_back(word);
        }
        
        return output;
    }
};
