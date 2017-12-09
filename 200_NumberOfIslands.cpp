/*
	https://leetcode.com/problems/number-of-islands/description/
	shimon0505004
*/


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numberOfIsland = 0;
        
        for(int row=0;row<grid.size();row++)
        {
            for(int column=0;column<grid.at(row).size();column++)
            {
                if(grid.at(row).at(column)=='1')
                {
                    markIsland(grid, row, column);
                    numberOfIsland++;
                }
            }            
        }
        
        return numberOfIsland;
    }
    
    
    void markIsland(vector<vector<char>>& grid, int row, int column)
    {
      if(row>=0 && row<grid.size() && column>=0 && column<grid.at(row).size())
        {
            if(grid.at(row).at(column)== '0')
                return;
          
            grid.at(row).at(column)= '0';
            markIsland(grid,row-1,column);
            markIsland(grid,row+1,column);
            markIsland(grid,row,column-1);
            markIsland(grid,row,column+1);
        }
    }
    
};