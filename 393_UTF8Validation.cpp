/*
	https://leetcode.com/problems/utf-8-validation/
	shimon0505004
*/

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        bool isUTF8 = true;
        for(int index=0;index<data.size();)
        {
            if(data.at(index)<128)
                index++;
            else if((data.at(index)>=192 && data.at(index)<224)
                    && (index+1<data.size())
                    && (data.at(index+1)>=128 && data.at(index+1)<192))
                    index+=2;
            else if((data.at(index)>=224 && data.at(index)<240)
                    && (index+1<data.size())
                    && (data.at(index+1)>=128 && data.at(index+1)<192) 
                    && (index+2<data.size())
                    && (data.at(index+2)>=128 && data.at(index+2)<192))
                    index += 3;
            else if((data.at(index)>=240 && data.at(index)<248)
                    && (index+1<data.size())
                    && (data.at(index+1)>=128 && data.at(index+1)<192) 
                    && (index+2<data.size())
                    && (data.at(index+2)>=128 && data.at(index+2)<192)
                    && (index+3<data.size())
                    && (data.at(index+3)>=128 && data.at(index+3)<192))
                    index += 4;        
            else
            {
                //cout << data.at(index)<< "," <<data.at(index+1) << endl; 
                isUTF8 = false;
                break;
            }
        }
        
        return isUTF8;
    }
};