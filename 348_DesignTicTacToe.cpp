/*
	shimon0505004
	https://leetcode.com/problems/design-tic-tac-toe/
*/


#include<algorithm>

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        matrix = std::vector<std::vector<int>>(n, std::vector<int>(n,0));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        matrix[row][col] = player;
        if(matchFoundInRow(row))
            return player;
        
        if(matchFoundInColumn(col))
            return player;
        
        if(matchFoundInDiagonal())
            return player;
        
        return 0;
    }
    
    
    bool matchFoundInRow(int row)
    {
        return matchFoundInLine(matrix[row]);
    }
    
    bool matchFoundInColumn(int col)
    {
        vector<int> column(matrix.size(),0);
        for(int row=0;row<matrix.size();row++)
            column.at(row) = matrix[row][col];
        
        return matchFoundInLine(column);
    }
    
    bool matchFoundInDiagonal()
    {
        vector<int> leftToRight(matrix.size(),0);
        vector<int> rightToLeft(matrix.size(),0);
        
        for(int level=0;level < matrix.size(); level++)
        {
            int offset = matrix.size()-1;
            leftToRight.at(level) = matrix[level][level];
            rightToLeft.at(level) = matrix[level][offset-level];
        }
        
        return (matchFoundInLine(leftToRight) || matchFoundInLine(rightToLeft));
    }
    
    bool matchFoundInLine(vector<int> line)
    {
        
        bool lineFull = !(std::any_of(line.begin() , line.end() , [](int number){return number==0;}));
        
        bool isAll1 = std::all_of(line.begin() , line.end() , [](int number){return number==1;});
        bool isAll2 = std::all_of(line.begin() , line.end() , [](int number){return number==2;});
        
        return (lineFull && (isAll1 || isAll2));
    }
    
    
private:
    std::vector<std::vector<int>> matrix;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */