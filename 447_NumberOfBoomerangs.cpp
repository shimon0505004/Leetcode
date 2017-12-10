/*
	https://leetcode.com/problems/number-of-boomerangs/
	shimon0505004
*/

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int numOfBoomerangs = 0;
        
        for(int index=0;index<points.size();index++)
        {
            unordered_map<long long,int> distanceCountMap(points.size());
            for(int secondIndex=0 ; secondIndex<points.size(); secondIndex++)
            {
                if(index!=secondIndex)
                {
                    int dx = points.at(secondIndex).first - points.at(index).first;
                    int dy = points.at(secondIndex).second - points.at(index).second;
                    long long distSQ = (static_cast<long long> (dx) ) * (static_cast<long long> (dx) );
                    distSQ += (static_cast<long long> (dy) ) * (static_cast<long long> (dy) );
                    ++distanceCountMap[distSQ];
                }
            }
            
            for(const auto& mapElem : distanceCountMap)
            {
                if(mapElem.second>1)
                {
                    numOfBoomerangs += (mapElem.second)*(mapElem.second-1);
                }
            }
        }
        
        return numOfBoomerangs;
    }
};