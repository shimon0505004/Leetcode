/*
	shimon0505004
	531. Lonely Pixel I
	https://leetcode.com/problems/lonely-pixel-i/
*/


class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        vector<int> rowBCounter(picture.size(),0);
        vector<int> colBCounter(picture[0].size(),0);
        for(int row=0;row<picture.size();row++)
        {
            for(int col=0;col<picture[row].size();col++)
            {
                if(picture[row][col]=='B')
                {
                    rowBCounter[row]++;
                    colBCounter[col]++;
                }
            }            
        }

        int result = 0;
        for(int row=0;row<picture.size();row++)
        {
            for(int col=0;col<picture[row].size();col++)
            {
                if(picture[row][col]=='B')
                {
                    if(rowBCounter[row]==1 && colBCounter[col]==1)
                        result++;
                }
            }            
        }
        
        return result;
    }
};