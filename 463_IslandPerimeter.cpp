/*
	https://leetcode.com/problems/island-perimeter/
	shimon0505004
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter=0;
        for(size_t rowIndex=0;rowIndex<grid.size();rowIndex++)
        {
            for(size_t colIndex=0;colIndex<grid.at(rowIndex).size();colIndex++)
            {
                if(grid.at(rowIndex).at(colIndex)==1)
                {
                    if(rowIndex==0 || grid.at(rowIndex-1).at(colIndex)==0)
                        perimeter++;
                    
                    if(rowIndex==grid.size()-1 || grid.at(rowIndex+1).at(colIndex)==0)
                        perimeter++;
                    
                    if(colIndex==0 || grid.at(rowIndex).at(colIndex-1)==0)
                        perimeter++;
                    
                    if(colIndex==grid.at(rowIndex).size()-1 || grid.at(rowIndex).at(colIndex+1)==0)
                        perimeter++;
                }
            }
        }
        
        return perimeter;
    }
};