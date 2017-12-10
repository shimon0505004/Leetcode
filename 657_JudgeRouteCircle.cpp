/*
	https://leetcode.com/problems/judge-route-circle/
	shimon0505004
*/

class Solution {
public:
    bool judgeCircle(string moves) {
        int horizontal = 0;
        int vertical = 0;
        for(const auto& c: moves)
        {
            switch(c)
            {
                case 'R':
                    horizontal++;
                    break;
                case 'L':
                    horizontal--;
                    break;
                case 'U':
                    vertical++;
                    break;
                case 'D':
                    vertical--;
                    break;
                default:
                    break;
            }
        }
        
        return (horizontal==0 && vertical==0);
    }
};