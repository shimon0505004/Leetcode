/*
	https://leetcode.com/problems/pascals-triangle-ii/
	shimon0505004
*/


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> currentRow(rowIndex+1, 1);
        for(int row=1;row<=rowIndex+1;row++)
        {
            if(row>=2)
            {
                int prevElement = currentRow.at(0);
                for(int index=1;index<row-1;index++)
                {
                    int currentElement = currentRow.at(index);
                    currentRow.at(index) = currentElement+prevElement;
                    prevElement = currentElement;
                }
            }
        }
        return currentRow;
    }
    
};