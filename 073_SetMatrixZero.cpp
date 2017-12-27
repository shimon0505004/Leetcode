/*
	shimon0505004
	https://leetcode.com/problems/set-matrix-zeroes/
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        //Pass 1. Set first row and first columns to zero for appropriate places.
        std::unordered_set<int> rowsToBeCleared;
        std::unordered_set<int> columnsToBeCleared;
        
        for(int row=0;row<matrix.size();row++)
        {
            for(int column=0;column<matrix.at(row).size();column++)
            {
                if(matrix[row][column]==0)
                {
                    rowsToBeCleared.insert(row);
                    columnsToBeCleared.insert(column);
                }
            }            
        }
        
        //Pass 2. Edit the complete matrix.
        for(int row: rowsToBeCleared)
        {
            for(int column=0;column<matrix.at(row).size();column++)
            {
                matrix[row][column] = 0;
            }            
        }
                
        for(int column: columnsToBeCleared)
        {
            for(int row=0;row<matrix.size();row++)
            {
                matrix[row][column] = 0;
            }            
        }

    }
};