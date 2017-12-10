/*
	https://leetcode.com/problems/distribute-candies/
	shimon0505004
*/

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        std::unordered_map<int,int> uniqueCandies;
        std::unordered_set<int> keys;
        for(const int& candy:candies)
        {
            if(uniqueCandies.count(candy)==0)
            {
                uniqueCandies[candy]=1;
                keys.insert(candy);     
            }
            else
                uniqueCandies[candy]+=1;
        }
        
        int half = candies.size()/2;
        int index=0;
        int unique =0;
        for(const int& key:keys)
        {
            if(uniqueCandies.count(key)!=0)
            {
                uniqueCandies[key]--;
                unique++;
            }
            if(unique>=half)
                break;
        }
        return unique;
    }
};