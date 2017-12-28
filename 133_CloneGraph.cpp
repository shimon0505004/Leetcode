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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==nullptr)
            return nullptr;
        
        if(originalToCloneNodeMapping.find(node)  != originalToCloneNodeMapping.end())
        {
            return originalToCloneNodeMapping.at(node);        
        }
        
        UndirectedGraphNode* copyNode = new UndirectedGraphNode(node->label);
        originalToCloneNodeMapping[node] = copyNode;
        queue<UndirectedGraphNode *> toVisit;
        toVisit.push(node);
        
        while(!toVisit.empty())
        {
            UndirectedGraphNode* current = toVisit.front();
            toVisit.pop();
            for(UndirectedGraphNode* neighbour : current->neighbors)
            {
                if(originalToCloneNodeMapping.find(neighbour)  == originalToCloneNodeMapping.end())
                {
                    UndirectedGraphNode* neighbourCopy = new UndirectedGraphNode(neighbour->label);
                    originalToCloneNodeMapping[neighbour] = neighbourCopy;
                    toVisit.push(neighbour);
                }
                originalToCloneNodeMapping[current]->neighbors.push_back(originalToCloneNodeMapping[neighbour]);
            }
        }
        
        return copyNode;
    }
    
private:
    std::unordered_map<UndirectedGraphNode *,UndirectedGraphNode *> originalToCloneNodeMapping;
};