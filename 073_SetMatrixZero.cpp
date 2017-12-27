/*
	shimon0505004
	https://leetcode.com/problems/set-matrix-zeroes/
*/

class Solution {
public:
    
    //O(m+n) space complexity.
    void setZeroes_UsingUnorderedSet(vector<vector<int>>& matrix) {
        
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
    
    //O(1) space complexity.
    void setZeroes_UsingConstantSpace(vector<vector<int>>& matrix) {
        
        //Pass 1. Set first row and first columns to zero for appropriate places.

        bool setFirstRowToZero = false;
        bool setFirstColToZero = false;

        
        for(int row=0;row<matrix.size();row++)
        {
            for(int column=0;column<matrix.at(row).size();column++)
            {
                if(matrix[row][column]==0)
                {
                    if(row==0)
                        setFirstRowToZero = true;
                    
                    if(column==0)
                        setFirstColToZero = true;
                    
                    matrix[row][0] = 0;
                    matrix[0][column] = 0;                    
                }
            }            
        }
        
        //Pass 2. Edit the complete matrix.
        for(int row=1;row<matrix.size();row++)
        {
            for(int column=1;column<matrix.at(row).size();column++)
            {
                if(matrix[0][column]==0)
                    matrix[row][column] = 0;
            
                if(matrix[row][0]==0)
                    matrix[row][column] = 0;
            }
        }
        
        if(setFirstRowToZero)
        {
            for(int column=0;column<matrix.at(0).size();column++)
            {
                matrix[0][column] = 0;
            }
        }

        if(setFirstColToZero)
        {
            for(int row=0; row<matrix.size(); row++)
            {
                matrix[row][0] = 0;
            }
        }

    }

    void setZeroes(vector<vector<int>>& matrix) {
        setZeroes_UsingConstantSpace(matrix);
    }
};