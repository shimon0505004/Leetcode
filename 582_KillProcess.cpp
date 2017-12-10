/*
	https://leetcode.com/subscribe/
	shimon0505004
*/

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        //can be solved using bfs and dfs
        std::map<int,std::set<int>> childrenMap;
        childrenMap.clear();
        for(int index=0;index<ppid.size();index++)
        {
            childrenMap[ppid[index]].insert(pid[index]);
        }
        
        queue<int> deleteQueue;
        vector<int> result;
        deleteQueue.push(kill);
        while(!deleteQueue.empty())
        {
            int deletedNode = deleteQueue.front();
            deleteQueue.pop();
            result.push_back(deletedNode);
            if(childrenMap.count(deletedNode))//checking if this node had any children
            {
                for(const auto& childNode:childrenMap[deletedNode])
                    deleteQueue.push(childNode);
            }
        }
        
        return result;
    }
};