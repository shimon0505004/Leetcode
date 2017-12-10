/*
	https://leetcode.com/problems/range-sum-query-2d-immutable/
	shimon0505004
*/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        if(!matrix.empty())
        {
            int rowSize = matrix.size()+1;
            int colSize = rowSize>0 ? matrix[0].size() : 0;
            matrixRunningSum = vector<vector<int>>(rowSize+1,vector<int>(colSize+1, 0));
            
            for(int i=0;i<matrix.size();i++)
            {
                int rowSum = 0;
                for(int j=0; j< matrix[i].size(); j++)
                {
                    rowSum += matrix[i][j];
                    matrixRunningSum[i+1][j+1] = matrixRunningSum[i][j+1] + rowSum;
                }
            }
            
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (matrixRunningSum[row2+1][col2+1]
                + matrixRunningSum[row1][col1]
                - matrixRunningSum[row1][col2+1]
                - matrixRunningSum[row2+1][col1]);
    }
    
private:    
    vector<vector<int>> matrixRunningSum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */