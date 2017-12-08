/*
	https://leetcode.com/problems/max-area-of-island/
	shimon0505004
*/

struct BorderVal{
    int row;
    int col;
    int val;
    BorderVal(int r,int c,int v)
        :row(r)
        ,col(c)
        ,val(v)
    {
    }
};


class Solution {
public:
    int processConnectedComponent(vector<vector<int>>& grid,int row, int col);
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int currentMax = 0;
        
        //std::queue<std::pair<int,int>> bfsQueueForRowCol;
        for(int row=0;row<grid.size();row++)
        {
            for(int col=0;col<grid.at(0).size();col++)
            {
                if(grid[row][col]==1)
                    currentMax = std::max(currentMax,processConnectedComponent(grid,row,col));
            }
        }
        
        return currentMax;
    }
    
};

int Solution::processConnectedComponent(vector<vector<int>>& grid,int row, int col)
    {
        int componentSize = 0;
        std::queue<BorderVal> bfsQueueForRowCol;
    
        if(grid[row][col]!=0)
        {
            bfsQueueForRowCol.push(BorderVal(row,col,grid[row][col]));
            grid[row][col] = 0;
        }
        while(!bfsQueueForRowCol.empty())
        {
            BorderVal border = bfsQueueForRowCol.front();
            bfsQueueForRowCol.pop();
            componentSize+= border.val;

            int r = border.row-1;
            int c = border.col;
            if(r>=0)
                if(grid[r][c]!=0)
                {
                    int v = grid[r][c];
                    bfsQueueForRowCol.push(BorderVal(r,c,v));
                    grid[r][c] = 0;
                }
            
            r = border.row;
            c = border.col-1;            
            if(c>=0)
                if(grid[r][c]!=0)
                {
                    int v = grid[r][c];
                    bfsQueueForRowCol.push(BorderVal(r,c,v));
                    grid[r][c] = 0;
                }

            r = border.row+1;
            c = border.col;                        
            if(r<grid.size())
                if(grid[r][c]!=0)
                {
                    int v = grid[r][c];
                    bfsQueueForRowCol.push(BorderVal(r,c,v));
                    grid[r][c] = 0;
                }

            r = border.row;
            c = border.col+1;                        
            if(c<grid.at(0).size())
                if(grid[r][c]!=0)
                {
                    int v = grid[r][c];
                    bfsQueueForRowCol.push(BorderVal(r,c,v));
                    grid[r][c] = 0;
                }
        }
        
        return componentSize;
    }