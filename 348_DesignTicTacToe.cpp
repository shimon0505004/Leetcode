/*
	shimon0505004
	https://leetcode.com/problems/design-tic-tac-toe/
*/


class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        matrixSize = n;
        rowSum = std::vector<int>(n,0);
        columnSum = std::vector<int>(n,0);
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
        if(player==2)
            player = -1;
        
        updateRowColumnDiagonalSum(row,col, player);
        
        int result = matchFoundUsingSum(row,col, player);
        if(result == -1)
            result = 2;
        
        return result;
    }
    
    
    void updateRowColumnDiagonalSum(int row, int col, int player) 
    {
        rowSum.at(row) += player;
        columnSum.at(col) += player;
        
        if(row==col)
            leftToRightDiagonalSum += player;
        
        if(row+col == matrixSize - 1)
            rightToLeftDiagonalSum += player;
        
        return;
    }
    
    
    
    int matchFoundUsingSum(int row, int col,int player)
    {
        //check row
        if(rowSum.at(row) == (player * matrixSize))
            return player;
        
        if(columnSum.at(col) == (player * matrixSize))
            return player;
        
        if(leftToRightDiagonalSum == (player * matrixSize))
            return player;
        
        if(rightToLeftDiagonalSum == (player * matrixSize))
            return player;
        
        return 0;
    }
    
    
    
private:
    int matrixSize;
    std::vector<int> rowSum;
    std::vector<int> columnSum;
    int leftToRightDiagonalSum = 0;
    int rightToLeftDiagonalSum = 0;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */