/*
	https://leetcode.com/problems/count-and-say/
	shimon0505004
*/

class Solution {
public:
    string countAndSay(int n) {
        string initialStr = "1";
        for(int counter=2;counter<=n;counter++)
        {
            int runningNum = initialStr[0]-'0';
            int count = 1;
            std::string currentStr;
            for(int index=1; index<initialStr.length(); index++)
            {
                if(runningNum!=initialStr[index]-'0')
                {
                    currentStr += std::to_string(count);
                    currentStr += std::to_string(runningNum);
                    count = 1;
                    runningNum = initialStr[index]-'0';
                }
                else
                    count++;
            }
            currentStr += std::to_string(count);
            currentStr += std::to_string(runningNum);
            initialStr = currentStr;
        }
        return initialStr;
    }
};