/*
	https://leetcode.com/submissions/detail/130487636/
	shimon0505004
*/

class Solution {
public:
    bool kahnsTopologicalSort(int numCourses, vector<pair<int, int>>& prerequisites) {
        std::vector<std::vector<int>> adjacencyList(numCourses, std::vector<int>());
        std::vector<int> incomingEdges(numCourses,0); // 0 = no incoming edge, 1 = has incoming edge
        int numberOfEdges = prerequisites.size();
                
        //O(E)
        for(auto courseAndPrerequisite : prerequisites)
        {
            adjacencyList[courseAndPrerequisite.second].push_back(courseAndPrerequisite.first);
            ++incomingEdges[courseAndPrerequisite.first]; //increasing number of incoming edge.
            
        }
        
        
        //O(V)
        std::queue<int> nodesWithoutIncomingEdges;
        for(int nodeIndex=0; nodeIndex < numCourses ; nodeIndex++)
        {
            if(incomingEdges[nodeIndex]==0)
                nodesWithoutIncomingEdges.push(nodeIndex);
        }
        
        //O(V+E)
        std::vector<int> topologicalSort;
        while(!nodesWithoutIncomingEdges.empty())
        {
            int u = nodesWithoutIncomingEdges.front();
            nodesWithoutIncomingEdges.pop();
            topologicalSort.push_back(u);
            for(int v:adjacencyList[u])
            {
                --incomingEdges[v];
                if(incomingEdges[v]==0)
                    nodesWithoutIncomingEdges.push(v);
            }
            numberOfEdges -= adjacencyList[u].size();
            adjacencyList[u].clear();
        }
                    
        return (numberOfEdges==0);
        
    }
    
    
    
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        return  kahnsTopologicalSort(numCourses,prerequisites);        
    }
};