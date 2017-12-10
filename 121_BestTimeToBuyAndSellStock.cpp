/*
	https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
	shimon0505004
*/

#include <algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxProfitSoFar = 0;
        if(prices.size() > 0)
        {
            int curMin = prices.at(0);
            for(int index=1;index<prices.size();index++)
            {
                curMin = min(curMin,prices.at(index));
                maxProfitSoFar = max(maxProfitSoFar,prices.at(index)-curMin);
            }
        }
        return maxProfitSoFar;
    }
};