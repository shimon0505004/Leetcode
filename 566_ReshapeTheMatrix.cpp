/*
	https://leetcode.com/problems/reshape-the-matrix/
	shimon0505004
*/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if( r==0 || c==0 || nums.size() == 0)
            return nums;
        
        int elements = 0;
        for(auto row: nums)
        {
            elements += row.size();
        }
        if(elements != (r*c))
            return nums;
        else
        {
            vector<vector<int>> newMat = vector<vector<int>>(r, vector<int>(c,0));
            int count = 0;
            for(auto row: nums)
            {
                for(auto col: row)
                {
                    int newRow = count / c;
                    int newCol = count % c;
                    newMat.at(newRow).at(newCol) = col;
                    count++;
                }
            }
            
            return newMat;
        }
    }
};