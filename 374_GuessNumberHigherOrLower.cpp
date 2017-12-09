/*
	https://leetcode.com/problems/guess-number-higher-or-lower/
	shimon0505004
*/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1;
        int hi = n;
        int mid = 0;
        while(lo<=hi)
        {
            if(lo%2!=0 && hi%2!=0)
                mid = lo/2 + hi/2 +1;
            else
                mid = lo/2 + hi/2;
            cout << mid << endl;
            int ret = guess(mid);
            if(ret==-1)
                hi = mid-1;
            else if(ret==1)
                lo = mid+1;
            else
                break;
        }
        
        return mid;
    }
};