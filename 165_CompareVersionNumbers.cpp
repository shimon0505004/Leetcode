/*
	shimon0505004
	165. Compare Version Numbers
	https://leetcode.com/problems/compare-version-numbers
*/

class Solution {
public:
    
    using RevisionPair = std::pair<int, int>;
    RevisionPair generatePair(string version)
    {
        std::size_t decimalPointLocation = version.find('.');
        int first = 0;
        int second = 0;
        if(decimalPointLocation == std::string::npos)
        {
            first = std::stoi(version);
        }else
        {
            int lengthOfFirstStr = decimalPointLocation;
            first = std::stoi(version.substr(0, lengthOfFirstStr));
            second = std::stoi(version.substr(decimalPointLocation+1));            
        }
        
        return std::make_pair(first,second);
    }
    
    int compareVersion(string version1, string version2) {
        
        RevisionPair rpVersion1 = generatePair(version1);
        RevisionPair rpVersion2 = generatePair(version2);
        
        int returnValue = 0;
        if(rpVersion1.first < rpVersion2.first)
            returnValue = -1;
        else if(rpVersion1.first > rpVersion2.first)
            returnValue = 1;
        else
        {
            if(rpVersion1.second < rpVersion2.second)
                returnValue = -1;
            else if(rpVersion1.second > rpVersion2.second)
                returnValue = 1;
            else
                returnValue = 0;
        }
        
        return returnValue;
    }
};