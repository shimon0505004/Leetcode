/*
	https://leetcode.com/problems/assign-cookies/description/
	shimon0505004
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(),g.end());
        std::sort(s.begin(),s.end());
        int contentChildren = 0;
        while(!g.empty() && !s.empty())
        {
            if(g.front()<=s.front())
            {
                contentChildren++;
                g.erase(g.begin());
            }
            s.erase(s.begin());
        }
        
        return contentChildren;
    }
};