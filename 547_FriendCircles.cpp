/*
	https://leetcode.com/problems/friend-circles/
	shimon0505004
*/

#include <algorithm>
#include <array>

class Solution {
public:
    int find(vector<int> parentArr, int index)
    {
        if(parentArr.at(index)==-1 || parentArr.at(index)==index)
            return index;
        return find(parentArr, parentArr.at(index));
    }
    
    void Union(vector<int>& parentArr, int x, int y)
    {
        int xset = find(parentArr,x);
        int yset = find(parentArr,y);
        parentArr.at(xset) = yset;
    }
    
    
    int findCircleNum(vector<vector<int>>& M) {
        
        std::vector<int> parentArray;
        parentArray.resize(M.size());
        std::fill(parentArray.begin(),parentArray.end(),-1);
        
        int CircleNum = M.size();
        for(int sourceIndex=0;sourceIndex< M.size();sourceIndex++)
        {
            for(int destinationIndex=0;destinationIndex< M.size(); destinationIndex++)
            {
                if(M[sourceIndex][destinationIndex]==1)
                {
                    int x = find(parentArray,sourceIndex);
                    int y = find(parentArray,destinationIndex);
                    if(x!=y)
                    {
                        parentArray.at(x) = y;  //union
                        CircleNum--;
                    }
                }
            }
        }
                
        return CircleNum;
    }
};