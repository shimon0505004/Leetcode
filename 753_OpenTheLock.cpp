/*
	shimon0505004
	753. Open the Lock
	https://leetcode.com/problems/open-the-lock/
*/

class Solution {
public:
    using BFSNode = std::pair<string,int>;
        
    int openLock(vector<string>& deadends, string target) 
    {
        for(string deadendString : deadends)
            deadendNumbers.insert(deadendString);
        
        std::queue<BFSNode> toVisit;
        toVisit.push(std::make_pair(std::string("0000"),0));

        int minTurnsNeeded = -1;
        
        while(!toVisit.empty())
        {
            BFSNode node = toVisit.front();
            toVisit.pop();
            
            if(node.first==target)
            {
                minTurnsNeeded = node.second;
                break;
            }

            if(visitedCombinations.find(node.first) == visitedCombinations.end()
              && deadendNumbers.find(node.first) == deadendNumbers.end())
            {
                visitedCombinations.insert(node.first);
                for(int index=0; index< node.first.size();index++)
                {
                    string less(node.first);
                    string more(node.first);
                    more[index] = (((more[index]+1) < '9') ? (more[index]+1) : '0' );
                    less[index] = (((less[index]-1) > '0') ? (less[index]-1) : '9' );

                    toVisit.push(std::make_pair(std::string(less),(node.second+1)));
                    toVisit.push(std::make_pair(std::string(more),(node.second+1)));
                }                

            }
           
        }
                                 
        return minTurnsNeeded;
    }
    
private:
    std::unordered_set<string> visitedCombinations;
    std::unordered_set<string> deadendNumbers;
};