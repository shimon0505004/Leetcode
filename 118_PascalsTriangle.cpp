/*
	https://leetcode.com/problems/pascals-triangle/
	shimon0505004
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        return generateTriangleUsingLessSpace(numRows);
    }
    
    vector<vector<int>> generateTrivial(int numRows)
    {
        vector<vector<int>> triangle;
        triangle.clear();
        if(numRows>0)
        {
            vector<int> currentRow = {1};
            triangle.push_back(currentRow);
            while(triangle.size()<numRows)
            {
                vector<int> previousRow = triangle.at(triangle.size()-1);
                currentRow.clear();
                currentRow.resize(triangle.size()+1);
                currentRow.at(0)=1;    
                currentRow.at(triangle.size())=1;
                for(int index=1;index<previousRow.size();index++)
                    currentRow.at(index) = (previousRow.at(index)+previousRow.at(index-1));
                triangle.push_back(currentRow);
            }           
        }
        return triangle;
    }
    
    
    vector<vector<int>> generateTriangleUsingLessSpace(int numRows)
    {
        vector<int> currentRow(numRows, 1);
        vector<vector<int>> result;
        for(int row=1;row<=numRows;row++)
        {
            if(row>=3)
            {
                int prevElement = currentRow.at(0);
                for(int index=1;index<row-1;index++)
                {
                    int currentElement = currentRow.at(index);
                    currentRow.at(index) = currentElement+prevElement;
                    prevElement = currentElement;
                }
            }
            result.push_back(vector<int>(currentRow.begin(),currentRow.begin()+row));
        }
        return result;
    }
};