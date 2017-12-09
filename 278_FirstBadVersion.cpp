/*
	https://leetcode.com/problems/first-bad-version/description/
	shimon0505004
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1;
        int hi = n;
        int mid = ((lo%2!=0 && hi%2!=0) ? (lo/2 + hi/2 +1) : (lo/2 + hi/2));
        while(lo<=hi)
        {
            mid = ((lo%2!=0 && hi%2!=0) ? (lo/2 + hi/2 +1) : (lo/2 + hi/2));
            if(isBadVersion(mid))
                hi = mid-1;
            else
                lo = mid+1;
        }
        
        return lo;
    }
};