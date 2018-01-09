/*
	shimon0505004
	269. Alien Dictionary
	https://leetcode.com/problems/alien-dictionary/
*/

class Solution {
public:
    
    std::pair<int,int> generateEdge(string& left, string& right)
    {
        int leftIndex=0;
        int rightIndex=0;
        while(leftIndex<left.length() && rightIndex<right.length())
        {
            if(left.at(leftIndex) != right.at(rightIndex))
            {
                int source = left.at(leftIndex)-'a';
                int dest = right.at(rightIndex)-'a';
                return  std::make_pair(source,dest); 
            }
            leftIndex++;
            rightIndex++;
        }
        
        return std::make_pair(-1,-1);
    }
    
    std::unordered_map<int,std::vector<int>> populateAdjacencyList(vector<string>& words)
    {
        std::unordered_map<int,std::vector<int>> adjL;
        for(std::string& word : words)
        {
            for(int c: word)
            {
                int index = c-'a';
                adjL[index] = std::vector<int>();
            }
        }
        
        for(int index=1; index<words.size(); index++)
        {
            auto edge = generateEdge(words[index-1], words[index]);
            if(edge.first != -1 && edge.second != -1)
                adjL[edge.first].push_back(edge.second);
        }
                
        return adjL;
    }
    
    std::unordered_map<int,int> populateIndegreeMap(vector<string>& words)
    {
        std::unordered_map<int,int> indeg;
        for(std::string& word : words)
        {
            for(int c: word)
            {
                int index = c-'a';
                indeg[index] = 0;
            }
        }
        
        for(int index=1; index<words.size(); index++)
        {
            auto edge = generateEdge(words[index-1], words[index]);
            if(edge.first != -1 && edge.second != -1)
                indeg[edge.second] = indeg[edge.second]+1;
        }
        
        return indeg;
    }
    
    void printNode(int node)
    {
        char nodeChar = static_cast<char>(node+'a');
        std::cout << nodeChar << std::endl;  
    }
    
    void printCurrentAndNextNode(int currentNode, int nextNode)
    {
        char currentNodeChar = static_cast<char>(currentNode+'a');
        char nextNodeChar = static_cast<char>(nextNode+'a');
        std::cout << currentNodeChar << " " << nextNodeChar << std::endl;  
    }
    
    std::queue<int> initializeQueueForZeroIndegreeNodes(std::unordered_map<int,int>& indeg)
    {
        std::queue<int> zeroIndegNodes;
        for(auto pair: indeg)
        {
            int node = pair.first;
            int indegree = pair.second;
            if(indegree==0)
                zeroIndegNodes.push(node);
        }
        return zeroIndegNodes;
    }
    
    void updateResultOrder(std::string& currentResultOrder, int currentNode)
    {
        char currentChar = static_cast<char>(currentNode + 'a');
        currentResultOrder += currentChar;
    }
    
    
    std::string topologicalSorting(std::unordered_map<int,std::vector<int>>& adjL,
                                   std::unordered_map<int,int>& indegMap)
    {
        std::queue<int> zeroIndegNodes = initializeQueueForZeroIndegreeNodes(indegMap);        
        std::string resultOrder ;
        
        while(!zeroIndegNodes.empty())
        {
            int currentlyVisitingNode = zeroIndegNodes.front();
            zeroIndegNodes.pop();
            
            updateResultOrder(resultOrder, currentlyVisitingNode);
            
            for(int nextNode : adjL[currentlyVisitingNode])
            {
                indegMap[nextNode]--;
                if(indegMap[nextNode] == 0)
                    zeroIndegNodes.push(nextNode);
            }
        }
        
        //At this point, if all nodes have zero indegree, resultOrder
        //should contain the final result.
        //If there are still nodes with indegree, that means there is a cycle
        //present in this directed graph; and it is not a DAG
        for(auto mapEntry: indegMap)
        {
            int currentIndegree = mapEntry.second;
            if(currentIndegree>0)
                return std::string();
        }
        
        return resultOrder;
    }
        
    string alienOrder(vector<string>& words) {
        if(words.size() < 1)
            return std::string();

        std::unordered_map<int,std::vector<int>> adjL = populateAdjacencyList(words);
        std::unordered_map<int,int> indegMap = populateIndegreeMap(words);        
        
        return topologicalSorting(adjL, indegMap);
    }
};