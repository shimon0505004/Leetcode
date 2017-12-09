/*
	https://leetcode.com/problems/h-index/
	shimon0505004
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(),citations.end(),std::greater<int>());
        
        int hIndex = 0;
        
        for(int h=citations.size();h>0;h--)
        {
            int index=0;
            while(index<h)
            {
                if(citations.at(index)>=h)
                    index++;
                else
                    break;
            }
            
            if(index==h)
            {
                if(index<citations.size())
                {
                    while(index<citations.size())
                    {
                        if(citations.at(index)<=h)
                            index++;
                        else
                            break;
                    }
                    
                    if(index==citations.size())
                    {
                        hIndex = h;
                        break;
                    }
                }
                else
                {
                    hIndex = h;
                    break;
                }
            }
        }
        
        return hIndex;
    }
};