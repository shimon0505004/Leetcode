/*
	https://leetcode.com/problems/number-complement/
	shimon0505004
*/

class Solution {
public:
    std::vector<int> initializer_list()
    {
        std::vector<int> arr;
        arr.push_back(1);
        for(int index=1;index<32;index++)
        {
            int newElem = 2*arr.back();
            arr.push_back(newElem);
        }
        
        for(int index=0;index<32;index++)
        {
            arr[index] -= 1;
        }
        
        return arr;
    }
    


    int findComplement(int num) {
        std::vector<int> arr = initializer_list(); 
        //Binary search
                
        int lo = 0;
        int hi = arr.size()-1;
        while(lo<=hi)
        {
            int mid=(lo+hi) / 2;
            if(arr.at(mid)==num)
            {
                lo = mid;
                hi = mid;
            }
            else if(num < arr.at(mid))
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
            
            if(lo==hi || lo==hi-1)
                break;
        }
        
        
        return arr.at(hi) - num;
        
    }
};