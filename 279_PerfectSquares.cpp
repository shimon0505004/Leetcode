/*
	shimon0505004
	279. Perfect Squares
	https://leetcode.com/problems/perfect-squares/
*/


class Solution {
public:
    int numSquares(int n) {
        if(n<=0)
        {
            return 0;
        }
        
        vector<int> perfectSquares;
        queue<pair<int,int>> searchQ;
        vector<bool> alreadyVisited(n,false);
        for(int i=1;i*i<=n;i++)
        {
            int square = i*i;
            int leastNumberOfPerfectSquaresNeeded = 1;
            perfectSquares.push_back(square);
            searchQ.push(std::make_pair(square,leastNumberOfPerfectSquaresNeeded));
        }
        
        int leastNumberOfPerfectSquaresNeeded = 0;
        while(!searchQ.empty())
        {
            auto current = searchQ.front();
            searchQ.pop();
            int currentNumber = current.first;
            leastNumberOfPerfectSquaresNeeded = current.second;
            if(currentNumber==n)
                break;
            else
            {
                if(alreadyVisited[currentNumber-1]==false)
                {
                    for(auto perfectSquare: perfectSquares)
                    {
                        int nextPossibleNumber = currentNumber + perfectSquare;
                        if(nextPossibleNumber <= n)
                            searchQ.push(std::make_pair(nextPossibleNumber,leastNumberOfPerfectSquaresNeeded+1));
                        else
                            break;
                    }
                    alreadyVisited[currentNumber-1]= true;
                }
            }            
        }
        return leastNumberOfPerfectSquaresNeeded;
    }
};