/*
	shimon0505004
	490. The Maze
	https://leetcode.com/problems/the-maze/
*/

class Solution {
public:
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int numberOfRows = maze.size();
        if(numberOfRows == 0)
            return false;
        
        std::queue<std::pair<int,int>> toVisit;
        toVisit.push(std::make_pair(start[0],start[1]));
        
        while(!toVisit.empty())
        {
            std::pair<int,int> visitedNode = toVisit.front();
            toVisit.pop();
            
            if(destination[0] == visitedNode.first && destination[1] == visitedNode.second)
            {
                return true;
            }

            maze[visitedNode.first][visitedNode.second] = 1 ;

            
            if(visitedNode.first-1 >= 0)
            {
                int row = visitedNode.first-1;
                int col = visitedNode.second;
                if(maze[row][col] == 0)
                    toVisit.push(std::make_pair(row,col));
            }

            if(visitedNode.first+1 < maze.size())
            {
                int row = visitedNode.first+1;
                int col = visitedNode.second;
                if(maze[row][col] == 0)
                    toVisit.push(std::make_pair(row,col));
            }

            if(visitedNode.second-1 >= 0)
            {
                int row = visitedNode.first;
                int col = visitedNode.second-1;
                if(maze[row][col] == 0)
                    toVisit.push(std::make_pair(row,col));
            }
            
            if(visitedNode.second+1 < maze[visitedNode.first].size())
            {
                int row = visitedNode.first;
                int col = visitedNode.second + 1;
                if(maze[row][col] == 0)
                    toVisit.push(std::make_pair(row,col));
            }
        }
        
        return false;
    }
};