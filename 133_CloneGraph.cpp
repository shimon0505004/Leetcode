/*
	shimon0505004
	133. Clone Graph
	https://leetcode.com/problems/clone-graph/description/		
*/

/*
	Use graph traversal using BFS or DFS.
	For each node, create a mapping for corresponding copied node.
	If the copied node is already found in the map, then the original node has already been visited.
*/


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    using SourceToCloneNodeMap = std::unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>;
    using BFSQueue = std::queue<UndirectedGraphNode *>;
    using DFSStack = std::stack<UndirectedGraphNode *>;
        
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        return cloneGraphUsingDFS(node);
    }
    
    UndirectedGraphNode *cloneGraphUsingDFS(UndirectedGraphNode *node) {
        UndirectedGraphNode * cloneHead = nullptr;
        if(node != nullptr)
        {
            cloneHead = new UndirectedGraphNode(node->label);
            map[node] = cloneHead;
            DFSStack toVisit;
            toVisit.push(node);
            
            while(!toVisit.empty())
            {
                UndirectedGraphNode * currentNode = toVisit.top();
                toVisit.pop();
                for(auto neighbor : currentNode->neighbors)
                {
                    if(map.find(neighbor) == map.end())
                    {
                        UndirectedGraphNode * neigbourClone = new UndirectedGraphNode(neighbor->label);
                        map[neighbor] = neigbourClone;
                        toVisit.push(neighbor);
                    }
                    map[currentNode]->neighbors.push_back(map[neighbor]);
                }
            }
        }
        map.clear();
        return cloneHead;
    }
        
    UndirectedGraphNode *cloneGraphUsingBFS(UndirectedGraphNode *node) {
        UndirectedGraphNode * cloneHead = nullptr;
        if(node != nullptr)
        {
            cloneHead = new UndirectedGraphNode(node->label);
            map[node] = cloneHead;
            BFSQueue toVisit;
            toVisit.push(node);
            
            while(!toVisit.empty())
            {
                UndirectedGraphNode * currentNode = toVisit.front();
                toVisit.pop();
                for(auto neighbor : currentNode->neighbors)
                {
                    if(map.find(neighbor) == map.end())
                    {
                        UndirectedGraphNode * neigbourClone = new UndirectedGraphNode(neighbor->label);
                        map[neighbor] = neigbourClone;
                        toVisit.push(neighbor);
                    }
                    map[currentNode]->neighbors.push_back(map[neighbor]);
                }
            }
        }
        map.clear();
        return cloneHead;
    }
    
    
private:
    SourceToCloneNodeMap map;
};