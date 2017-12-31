/*
	shimon0505004
	682. Baseball Game
	https://leetcode.com/problems/baseball-game/
*/


#include<exception>

class Solution {
public:
    int calPoints(vector<string>& ops) 
    {
        std::list<int> list;
        int runningSum = 0;
        
        for(const string& op : ops)
        {
            if(op == "C" && list.size() > 0)
            {
                runningSum -= list.back();
                list.pop_back();
            }
            else 
            {
                int roundN = 0;
                if(op == "D")
                {
                    int numberToMultiplyBy2 = 0;
                    if(list.size()>0)
                        numberToMultiplyBy2 = list.back();

                    roundN = (numberToMultiplyBy2 * 2);
                }
                else if(op == "+")
                {
                    int roundN_1 = 0;
                    if(list.size() > 0)
                        roundN_1 = *(std::prev(list.end(),1));

                    int roundN_2 = 0;
                    if(list.size() > 1)
                        roundN_2 = *(std::prev(list.end(),2));

                    roundN = roundN_2 + roundN_1;
                }
                else
                {
                    try
                    {
                        roundN = std::stoi(op);
                    }
                    catch(std::exception e)
                    {             
                        roundN = 0;
                    }

                }
                list.push_back(roundN);
                runningSum += list.back();                         
            }
        }
        return runningSum;
    }
    
};